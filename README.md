<p align="center">
  <img src="/lsx/menu.png" alt="N3WTuX">
</p>

### How to use

### Debian / Ubuntu / Pop OS / Linux Mint required packages:

```sudo apt install -y libsdl2-dev cmake git gcc-10 g++-10 gdb clang```

### Arch / Manjaro required packages:

```sudo pacman -S --needed base-devel git cmake gdb sdl2 clang```

### Fedora required packages:

```sudo dnf install gcc-g++ gdb SDL2-devel cmake git clang```

### OpenSUSE required packages:

```sudo zypper install gcc gdb SDL2-devel cmake git llvm-clang llvm-gold```

```sh
git clone https://github.com/calebrwalk5/BetterCS
cd BetterCS
chmod +x toolbox.sh
./toolbox.sh -b -l # build and then load, use -h for help
```

### Features added

Ragebot

## Basic toolbox.sh usage

| Argument           | Description                             |
| ------------------ | --------------------------------------- |
| -l (--load)        | Load/inject the cheat via gdb           |
| -ld (--load_debug) | Load/inject the cheat and debug via gdb |
| -b (--build)       | Build to the build/ dir                 |
| -bd (--build_debug)| Build to the build/ dir as debug        |
| -p (--pull)        | Update the cheat                        |
| -h (--help)        | Show help                               |

All args are executed in the order they are written in, for example, "-b -l" would build it, and then load it back into csgo.


## Credits


Special thanks to the Missedit projetc < https://github.com/HackerPolice/MissedIT

Special thanks to the Original AimTux project > https://github.com/AimTuxOfficial/AimTux.

Special thanks to the Fuzion For Panaroma Update And For Quality Codes > https://github.com/LWSS/Fuzion.

Special thanks to the Nimbus project > https://github.com/NimbusProjects/Nimbus

Special thanks to the Gamesneeze ORIGINAL owner of this project > https://github.com/seksea/gamesneeze
