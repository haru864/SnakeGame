# snakegame

## what is lifegame?
&emsp; snakegame \- operate snake, eat feed and grow, alive as long as you can

## SYNOPSIS
&emsp; snakegame

## DESCRIPTION
In snakegame, player operate snake expressed by symbol '<', '>', '^', 'v'.

Symbol expressing snake is fluctuate depending op direction snake move.

'^' snake go up

'v' snake go down

'<' snake go left

'>' snake go right

if snake eat feed expressed by '#', then snake grow and become longer.

When snake collide screen edge or one's body, the game is over, number of feeds snake ate and survival time are displayed on terminal.

## GAME SCREEN
![Screenshot from 2022-09-11 21-37-23](https://user-images.githubusercontent.com/45516420/189529058-3ecf1e4c-9c33-40e6-94d0-7853e706ed2d.png)

## RESULT SCREEN
```
user@localhost:~/sample$ ./bin/snakegame 
feeds: 2
survival time: 00:00:28(hh:mm:ss)
```
