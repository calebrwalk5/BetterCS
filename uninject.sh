#!/bin/bash

gdb="$(dirname "$0")/gdb" # For using a gdb build such as the cathook one (The one included)
libname="libgamemodeauto.so.0" # Pretend to be gamemode, change this to another lib that may be in /maps (if already using real gamemode, I'd suggest using libMangoHud.so)
csgo_pid=$(pidof csgo_linux64)

# Set to true to compile with clang. (if changing to true, make sure to delete the build directory from gcc)
export USE_CLANG="false"

echo "Uninjecting..."
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
if grep -q "$libname" "/proc/$csgo_pid/maps"; then
    $gdb -n -q -batch -ex "attach $csgo_pid" \
        -ex "set \$dlopen = (void*(*)(char*, int)) dlopen" \
        -ex "set \$dlclose = (int(*)(void*)) dlclose" \
        -ex "set \$library = \$dlopen(\"/usr/lib/$libname\", 6)" \
        -ex "call \$dlclose(\$library)" \
        -ex "call \$dlclose(\$library)" \
        -ex "detach" \
        -ex "quit"
fi
echo "Uninjected!"
