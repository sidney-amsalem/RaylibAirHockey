# Air Hockey Game
I built a simple 2-player air hockey game in C++ using the RayLib library. This was a great project in applying programming principles I learned in my Software Design class at Vanderbilt.

Some principles I focused on were object-oriented programming, inheritance and polymorphism, encapsulation, and the single responsibility principle.

# Classes
* **Game Logic**: The GameLogic class is responsible for managing the game state, including player movement, puck movement, collision detection, scoring, and saving/restoring game state. It interacts with the Player and Puck classes to update their positions and handle collisions. The class also provides methods to retrieve the current game state, such as player and puck data, scores, and saved game state.
* **Drawing**: The Drawing class provides functions to draw the time, score, game objects, map, pause screen, menu screen, and title screen. It also provides a function to draw centered text on the screen.
* **Game Object**: The GameObject class represents a generic game object with position, velocity, radius, mass, friction coefficient, and color. It provides methods to update the position, get and set the position, velocity, mass, radius, color, and friction coefficient of the object. This class is intended to be inherited by specific game object classes.
* **Player**: It inherits from the GameObject class and provides functionality for creating left and right players, moving the player in different directions,updating the player’s state, and resetting the player’s position.
* **Puck**: It inherits from the GameObject class and provides methods for updating the puck’s position and resetting it to its initial position.
