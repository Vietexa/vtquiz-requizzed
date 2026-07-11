# VTQuiz-Requizzed
## An online remake of VTQuiz using Raylib

(Note: This project is still in very early stages)

# How to build

## Arch Linux
1. ``sudo pacman -Syu && sudo pacman -S gcc cmake make`` (you probably already have gcc)
2. ``mkdir build && cd build``
3. ``cmake ..`` and then ``make``
4. Inside the ``build`` directory you should find an elf executable file, run it and you're good to go

Note: Raylib should already work out of the box even if you don't have it installed via your package manager because I vendor a version of it together with the project
