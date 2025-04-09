# 🕹️ cub3D - A Raycasting Engine in C

## 📖 Overview
`cub3D` is a 3D graphics engine built using the **raycasting** technique, inspired by early FPS games like *Wolfenstein 3D*.  
Developed as part of the 42 curriculum, this project is about rendering a 2D map as a pseudo-3D world using C and MiniLibX.

## 🧱 Core Concepts
- **Raycasting** to simulate a 3D environment
- **2D map parsing** from `.cub` files
- **Texture mapping** for walls and sprites
- **Player movement** and collision detection
- **Basic game engine architecture**

## 🛠️ Technologies
- **Language**: C  
- **Graphics**: MiniLibX  
- **OS**: Linux/macOS  
- **Math**: Trigonometry for ray direction and wall projection

## 📦 Installation
```bash
git clone https://github.com/Yekanat/cub3d.git
cd cub3d
make
Note: You need MiniLibX and related dependencies installed.
On Linux, you may need to install libXext, libX11, and zlib.

🏃 Usage
bash
Copy
Edit
./cub3D maps/map.cub
🕹️ Controls
W/A/S/D → Move

Arrow keys → Rotate view

ESC → Exit the game

🧩 .cub Map File Format
bash
Copy
Edit
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
Includes texture paths, floor/ceiling RGB, and the map layout.

📂 Project Structure
bash
Copy
Edit
cub3d/
├── src/              # Game loop, raycasting, rendering
├── includes/         # Headers
├── maps/             # Sample .cub files
├── textures/         # XPM images
├── Makefile
└── README.md
✅ Features
Player and camera system

Wall hit detection

Texture rendering

Basic error handling and map validation

Modular design

📜 License
This project is licensed under the MIT License – free to use and modify.

👤 Author
Angelo Thekkanath – GitHub
