<h1 align="center">
	cub3d
</h1>

<p align="center">
	<b><i>My first RayCaster with miniLibX</i></b><br>
</p>

---

## About the project

> _This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever.
It will enable you to explore ray-casting. 
Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way._


## Usage

### Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile, go to the program path and run:

```shell
make
```

**2. Executing the program**

To execute the program, run:

```C
./cub3D config.cub
```

The map files are in `map` directory


### Actions

| Keys   | Instruction                         | Action                                                 |
| :----: | :---------------------------------- | ------------------------------------------------------ |
| `W`    | the player movement                 | Press `W` to move forward.                             |
| `A`    | the player movement                 | Press `A` to move left.                                |
| `S`    | the player movement                 | Press `S` to move backward.                            |
| `D`    | the player movement                 | Press `D` to move right.                               |
| `Q`    | minimap (ON / OFF)                  | Press `Q` to display minimap.                          |
| `P`    | fish eye view mode (ON / OFF)       | Press `P` to toggle fisheye mode on and off.           |
| `ESC`  | Finish the game                     | Press `ESC` to finish the game.                        |

### Player 

   
