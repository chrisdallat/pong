# PONG

Pong clone in C++ using raylib game library, and python GUI using PyQT

from /pong run game from python main after installing dependencies with:

```sh
        python3 main.py
```

## Dependencies

```sh
        brew install raylib
```
```sh
        brew install PyQt6
```

## Game Menu

<img src="./images/pong_menu.png" width="400" />

## Game Window

<img src="./images/pong_game.png" width="600" />

## Powerups
Powerups will display as Circles which when collided with, the powerup is activated for the player who hit it. 

NOTE: Currently only 'Invisiball' powerup is active so the ball disappears after contact until the opponent returns it or it goes out. a new powerup is then dropped on the court at a random coordinate.

<img src="./images/pong_powerup.png" width="600" />

## Winner Window

<img src="./images/pong_winner.png" width="400" />

## Controls

<img src="./images/pong_controls.png" width="600" />

#
#
#
#
#
#
#

TODO: 
-> add powerups:
        multi-ball
        invisi-ball
        reversi-ball
        
-> add more controls for powerups
-> improve AI player movement
```sh
        PLAYER 1(LEFT)      PLAYER 2(RIGHT)
UP      KEY_W               KEY_UP
DOWN    KEY_S               KEY_DOWN
SERVE   KEY_SPACE           KEY_ENTER
```

