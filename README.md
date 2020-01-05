# Flappy-Bird
## About
This is my desktop implementation of the famous `Flappy Bird` using the `C++` language and [SFML GUI library](https://www.sfml-dev.org/).

The main purpose of this project is to familiarize myself with the structures of a "quite" complex game. It also helps improving my knowledge in making a game/ app in general.

## Screenshots
1. Splash Screen 


   ![Splash Screen](https://github.com/QuangTran304/Flappy-Bird/blob/master/Screen%20Shot%202020-01-05%20at%204.48.30%20PM.png)

2. Main Menu Screen

    ![Main Menu Screen](https://github.com/QuangTran304/Flappy-Bird/blob/master/Screen%20Shot%202020-01-05%20at%204.48.10%20PM.png)

3. Flash Screen on Death

    ![Flash Screen](https://github.com/QuangTran304/Flappy-Bird/blob/master/Screen%20Shot%202020-01-05%20at%204.48.54%20PM.png)

4. Game Over Screen

    ![GameOver Screen](https://github.com/QuangTran304/Flappy-Bird/blob/master/Screen%20Shot%202020-01-05%20at%204.49.07%20PM.png)

## How the game is designed
The game is designed based on the [states machine](https://en.wikipedia.org/wiki/Finite-state_machine) model. 

### Inputs
Inputs (i.e. clicks) are handled by the `InputManager` class.

### Assets
All assets (i.e. textures and fonts) are handled using the `AssetManager` class.

### States
Every state transitions, add/ remove a state, active state are processed by the `StateMachine` class (Different from `State` class).

### Main game loop

* `Game` object is created.
* Setup a window - video mode.
* Move on to `Splash State`
* Game `run()`
* Show `Main Menu State`
* Main game happens in `Game State`
* If bird crashes, move to `GameOver State`
* Back to `Game State` if replay is clicked.


## State class
```C++
    class State {
    public:
        void init() { /* ... */ };
        void handleInput() { /* ... */ };
        void update() { /* ... */ };
        void draw() { /* ... */ };
    };
```

## Issues
* The pipes are still quite far from each other.
* Pipe heights do not change much.
* The game consumes a high CPU power.