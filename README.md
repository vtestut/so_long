# so_long

Welcome to my `so_long` project !  
This project challenges us to create a simple 2D game using the MinilibX graphics library.

## Project Overview

The `so_long` project is an introduction to graphics programming and game development in the C language. Key features include:

- **Graphics with MinilibX:**
  - Utilize the MinilibX library for creating a graphical interface.

- **Map Parsing:**
  - Read and parse map files to define the game layout.

- **Player and Collectibles:**
  - Implement player movement and include collectible items.

- **Game Loop:**
  - Create a game loop for continuous player interaction.

## Contents

- **`/srcs/`:** Contains the source files, including the main `so_long` program.
- **`/includes/`:** Header files, including `so_long.h`.
- **`/xpm/`:** Graphic assets and textures used in the game.
- **`/ber/`:** Sample map files for testing.
- **`/bonus/`:** better version. Player can die if touched by ennemies, animated sprites, move count

## How to Use

1. Clone the repository to your local machine.
2. Unzip the minilibx-linux.zip
3. Navigate to the `/srcs/` directory and review the source files.
4. Compile the project using the provided Makefile (`make`).
5. Run the executable with a map file as an argument (`./so_long maps/sample_map.ber`).

## Controls

- **W, A, S, D:** Move the player.
- **ESC:** Exit the game.

Special thanks to Ecole 42 for the inspiration and learning opportunity.

Enjoy playing! 🎮
