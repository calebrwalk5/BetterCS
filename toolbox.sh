#!/bin/bash

gdb="$(dirname "$0")/gdb" # For using a gdb build such as the cathook one (The one included)
libname="libgamemodeauto.so.0" # Pretend to be gamemode, change this to another lib that may be in /maps (if already using real gamemode, I'd suggest using libMangoHud.so)
csgo_pid=$(pidof csgo_linux64)

# Set to true to compile with clang. (if changing to true, make sure to delete the build directory from gcc)
export USE_CLANG="false"

if [[ $EUID -eq 0 ]]; then
    echo "You cannot run this as root." 
    exit 1
fi

sudo rm -rf /tmp/dumps
sudo mkdir -p --mode=000 /tmp/dumps

function load {
 function echo_green {
	echo -e "\\e[32m$*\\e[0m"
}

function echo_orange {
	echo -e "\\e[33m$*\\e[0m"
}

function echo_red {
	echo -e "\\e[31m$*\\e[0m"
}

csgo_pid=$(pidof csgo_linux64)
if [ -z "$csgo_pid" ]; then
    echo_red "CS:GO needs to be open before you can inject, exiting..."
    exit 1
fi

#if [ ! -d ".git" ]; then
#    echo "We have detected that you have downloaded Fuzion-master.zip from GitHub.com. This is the WRONG way to download! Please download Fuzion by cloning the Git repository: 'git clone --recursive https://github.com/LWSS/Fuzion.git'"
#fi

# pBypass for crash dumps being sent
# You may also want to consider using -nobreakpad in your launch options.
sudo rm -rf /tmp/dumps # Remove if it exists
sudo mkdir --mode=000 /tmp/dumps # Make it as root with no permissions

if [ ! -f build_id ]; then
    echo "Build ID not found. Please rebuild using the './build' script."
    exit
fi

filename=$(cat build_id)

# Credit: Aixxe @ aixxe.net
if grep -q "$filename" /proc/$csgo_pid/maps; then
    echo_orange "N3WTuX is already injected, aborting..."
    exit
fi
echo "Injecting Build ID: $filename"

# https://www.kernel.org/doc/Documentation/security/Yama.txt
echo "2" | sudo tee /proc/sys/kernel/yama/ptrace_scope # Only allows root to inject code. This is temporary until reboot.

sudo cp "$filename" "/usr/lib/${filename}"

sudo killall -19 steam
sudo killall -19 steamwebhelper

lib_dir_name="lib"
if [ $(getconf LONG_BIT) = 64 ]; then
    lib_dir_name+="64"
fi

input="$(
sudo gdb -n -q -batch-silent \
  -ex "set logging on" \
  -ex "set logging file /dev/null" \
  -ex "set logging redirect on" \
  -ex "set auto-load safe-path /usr/share/gdb/auto-load/usr/$lib_dir_name/:/usr/$lib_dir_name/" \
  -ex "attach $csgo_pid" \
  -ex "set \$dlopen = (void*(*)(char*, int)) dlopen" \
  -ex "call \$dlopen(\"/usr/lib/$filename\", 1)" \
  -ex "detach" \
  -ex "quit"
)"

sleep 1
sudo killall -18 steamwebhelper
sudo killall -18 steam

sudo rm "/usr/lib/${filename}"

last_line="${input##*$'\n'}"

if [ "$last_line" != "\$1 = (void *) 0x0" ]; then
    echo_green "Successfully injected!"
else
    echo_red "Injection failed, make sure you have compiled..."
fi
}

function load_debug {
#!/usr/bin/env bash
# Starts a GDB session on CS:GO, injects cheat if it is not already present.
# Send SIGINT to CS:GO with: "kill -2 "$(pidof csgo_linux64)"".

function echo_red {
	echo -e "\\e[31m$*\\e[0m"
}

csgo_pid=$(pidof csgo_linux64)
if [ -z "$csgo_pid" ]; then
    echo_red "CS:GO needs to be open before you can inject..."
    exit 1
fi

# pBypass for crash dumps being sent
# You may also want to consider using -nobreakpad in your launch options.
sudo rm -rf /tmp/dumps # Remove if it exists
sudo mkdir --mode=000 /tmp/dumps # Make it as root with no permissions

if [ ! -f build_id ]; then
    echo "Build ID not found. Please rebuild using the './build' script."
    exit
fi

filename=$(cat build_id)

# https://www.kernel.org/doc/Documentation/security/Yama.txt
echo "2" | sudo tee /proc/sys/kernel/yama/ptrace_scope # Only allows root to inject code. This is temporary until reboot.

# Adjust the Sleep time below for your system if needed.
# This sends 2 interrupts to CS:GO after gdb attachs so gdb will drop into a shell.
sleep 3 && kill -2 "$csgo_pid" && sleep 1 && kill -2 "$csgo_pid" &

# dlopen method Credits: Aixxe @ aixxe.net
if grep -q "$filename" /proc/"$csgo_pid"/maps; then
    (echo -e "continue\\n"; cat) | sudo gdb -p "$csgo_pid"
else
    echo "Injecting build $filename"
    sudo cp "$filename" /"$filename"
    (echo -e "set confirm off\\nset \$dlopen = (void*(*)(char*, int)) dlopen\\ncall \$dlopen(\"/$filename\", 1)\\n"; cat) | sudo gdb -p "$csgo_pid"
    sudo rm /"$filename"
fi
}

function build {
    #!/usr/bin/env bash
#TODO: check distro and packages

function echo_orange {
	echo -e "\\e[33m$*\\e[0m"
}

function echo_red {
	echo -e "\\e[31m$*\\e[0m"
}
if test -z "$CXX"
then
   CXX=g++
fi

cmake . || exit 1

if ! hash patchelf 2>/dev/null; then
    echo_red -e "You need to install the \"patchelf\" command!\nUse your package manager to install it, or get source here:\nhttps://github.com/NixOS/patchelf"
    exit 1
fi

rm build_id_hex
# Get a Random name from the build_names file.
BUILD_ID=$(shuf -n 1 build_names)

# In case this file exists, get another one. ( checked it works )
while [ -f "/usr/lib/${BUILD_ID}" ] || grep -q ${BUILD_ID} /proc/$(pidof csgo_linux64)/maps; do
	BUILD_ID=$(shuf -n 1 build_names)
done

# Hexify it and put it into build_id_hex
for (( i=0; i<${#BUILD_ID}; i++ )); do
  printf '0x%x,\n' "'${BUILD_ID:$i:1}" >> build_id_hex
done
printf '0x0' >> build_id_hex

make -j"$(grep -c "^processor" /proc/cpuinfo)" "$@" || exit 1

if [ -f build_id ]; then
    filename=$(cat build_id)
    rm "$filename"
    if [ -f "/usr/lib/${filename}" ]; then
    	echo -e "Note: Old file found at /usr/lib/${filename}\n"
        #sudo rm "/usr/lib/${filename}"

    fi
    chmod 660 build_id
    mv build_id build_id_old
fi

echo $BUILD_ID > build_id
mv libN3WTuX.so "$BUILD_ID"

strip -s -v "$BUILD_ID"
patchelf --set-soname "$BUILD_ID" "$BUILD_ID" || echo_orange "Warning: your patchelf version does not support \"--set-soname\"\nConsider building from source: https://github.com/NixOS/patchelf"

chmod 400 build_id # Make the build_id read-only for safety.

echo "Build Completed."
}

function build_debug {
    if test -z $CXX
then
   CXX=g++
fi
cmake -DCMAKE_BUILD_TYPE="DEBUG"
make -j"$(grep -c "^processor" /proc/cpuinfo)"
mv libN3WTuX.so "$(cat build_id)"
}

function pull {
    echo "Feature still in development..."
    git pull
}

while [[ $# -gt 0 ]]
do
keys="$1"
case $keys in
    -l|--load)
        load
        shift
        ;;
    -ld|--load_debug)
        load_debug
        shift
        ;;
    -b|--build)
        build
        shift
        ;;
    -bd|--build_debug)
        build_debug
        shift
        ;;
    -p|--pull)
        pull
        shift
        ;;
    -h|--help)
        echo "
 help
Toolbox script for BetterCS the beste lincucks cheat 2023
=======================================================================
| Argument             | Description                                  |
| -l (--load)          | Load/inject the cheat via gdb.               |
| -ld (--load_debug)   | Load/inject the cheat and debug via gdb.     |
| -b (--build)         | Build to the build/ dir.                     |
| -bd (--build_debug)  | Build to the build/ dir as debug.            |
| -p (--pull)          | Update the cheat.                            |
| -h (--help)          | Show help.                                   |
=======================================================================

All args are executed in the order they are written in, for
example, \"-p -b -l\" would update the cheat, then build it, and
then load it back into csgo.
"
        exit
        ;;
    *)
        echo "Unknown arg $1, use -h for help"
        exit
        ;;
esac
done
