# Snake Game 🐍

A classic Snake Game implemented in C++ for the console. This project demonstrates basic game development concepts, including collision detection, random positioning, score tracking, and dynamic console rendering.

[b85c62b3-323c-4335-a5e9-7346ebb36d6f.webm](https://github.com/user-attachments/assets/fd2703a7-a550-4679-85d2-8ba946e3445e)

## Table of Contents
- [Features](#features)
- [Game Controls](#game-controls)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Project Structure](#project-structure)
- [Future Improvements](#future-improvements)
- [Contributing](#contributing)
- [License](#license)

## Features
- **Smooth Console Rendering**: Avoids screen flickering by updating the console position.
- **Snake Movement and Growth**: Controls to move the snake in four directions, and grow when it eats fruit.
- **Randomized Fruit Positioning**: Fruit appears at random locations on the grid.
- **Score Tracking**: Real-time score updates as you play.
- **Screen Wrapping**: Snake appears on the opposite side if it moves off the edge.

## Game Controls
- **W** - Move Up
- **A** - Move Left
- **S** - Move Down
- **D** - Move Right
- **X** - Exit the Game

## Installation
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/snake-game-cpp.git
   cd snake-game-cpp

2. **Compile and Run**:
   ```bash
   g++ ConsoleApplication1.cpp -o SnakeGame
   ./SnakeGame

## How to Play
- Start the game and control the snake to eat the fruit (`F`) that appears at random positions on the map.
- Each fruit you eat will increase your score by **10 points** and grow the snake's tail.
- If you run into your own tail, the game is over.

## Project Structure
- **Setup()**: Initializes game variables, randomizes the initial fruit position, and sets starting values.
- **Draw()**: Renders the game’s visuals in the console, including the snake, fruit, and boundaries.
- **Input()**: Captures and processes user input for movement.
- **Logic()**: Handles the movement, collision, and scoring mechanics.

## Future Improvements
- **Boundary Collision Options**: Add an option to toggle screen wrapping.
- **Difficulty Levels**: Implement game speeds for easy, medium, and hard modes.
- **Self-Collision Detection**: Improve collision detection for more advanced gameplay.
- **Modularization**: Refactor code into separate classes or modules.

## Contributing
Contributions are welcome! If you'd like to contribute to this project, please fork the repository and create a pull request with your changes.

