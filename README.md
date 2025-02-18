# Blob Demo

Blob Demo is a simple physics simulation that demonstrates a blob-like structure built from multiple particles interacting with static platforms. The simulation uses OpenGL and GLUT for rendering and includes basic physics for gravity, collision detection, and response.

## Features

- **Particle-Based Simulation:**  
  The blob is represented by multiple particles that simulate soft-body dynamics.

- **Custom Collision Detection:**  
  A simple collision detection algorithm is implemented to handle interactions between the blob particles and static platforms.

- **Dynamic Rendering Options:**  
  By modifying a few lines of code in the display function, you can render the blob particles as different geometric shapes (e.g., circles, cubes, or hexagons).

- **Basic Physics:**  
  Incorporates gravity, damping, and restitution to simulate realistic motion.

## Requirements

- **C++ Compiler:** Supports C++ (the code is written in C++).
- **OpenGL:** For rendering.
- **GLUT (or FreeGLUT):** For window management and handling OpenGL context.

> **Note:** The code currently includes `<gl/glut.h>`, which is typical for Windows. If you're using another platform, you may need to adjust your include paths accordingly.

