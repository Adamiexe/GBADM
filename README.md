
# GameBoyADM

GameBoyADM (aka GBADM) is cross-platform Gameboy Emulator, built with C++20.

The main goal of this Emulator is to be compatible with a lot of platform and manage to emulate GameBoy and Gameboy Color games.

### External Libraries

The following libraries are included directly in the `/library` folder of the project as Submodules:

- **SDL** – Used for window creation and input handling.  

No additional downloads are required for these libraries. Ensure the folder structure remains intact when building the project.

## Compilation

You will need at least Cmake 3.12 and a compatible platform listed below:

## Supported Platforms

| OS | Status |
| --- | --- |
| Windows | YES |
| Linux | NO |
| Android | NO |
| IOS | NO |
| MAC | NO |

## Quick Use

### Once compiled you need to:

- create a rom folder with your rom in the .gb or .gbc format 
- run GBADM

### Defaults controls :

| Input | Gameboy Controll |
| --- | --- |
| A | A |
| Z | B |
| S | Start |
| D | Select |
| I | Up |
| J | Down |
| K | Left |
| L | Right |

Currently the only way to change the mapping on the gamepad is to directly modify the "ui.c" file in the "ui_on_key()" function.


## Author

- [@AdamAkhrouf](https://www.github.com/adamiexe)

### Special Thanks

- to [Low Level Devel](https://www.youtube.com/@lowleveldevel1712/videos) for the youtube tutorials


