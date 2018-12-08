# [Implement minesweeper](https://leetcode.com/discuss/interview-question/125302/Implement-minesweeper/)

## Parameters
Assume we only allow board size to be `N * N`. Three difficulty levels, easy, medium and hard. Denote `B` as bomb count.

For easy, `N = 8`, `B = 12`, ratio `18.75%`
For medium `N = 15`, `B = 50`, ratio `22.22%`.
For hard `N = 20`, `B = 100`, ratio `25%`.

## Setup
1. Randomly assign bombs to board. Use reservoir sampling. The value of bomb cell is `-1`.
1. For each cell in the board that is not a bomb, put count of adjacent bomb in the cell.

## Game Play
The player has two action options: mine or flag.

If mine, reveal the cell.
* If it's bomb then game over
* otherwise show the count number in the cell. If the number is `0`, use BFS to mine the neighbors as well until the cells of the region all have count numbers greater than 0.

If flag, add `10` to the cell value to denote the cell as flagged. (The max count number is 8, so adding `10` is fine).

The game goes on until:
* the player mined a bomb, game over.
* the count of unmined cells is the same as the count of bombs -- Win!

## APIs

```
Constructor(DifficultyEnum difficulty)

GameStateEnum play(int x, int y, ActionEnum action)
```

```
DifficultyEnum { Easy, Medium, Hard }
GameStateEnum { Continue, Win, GameOver }
ActionEnum { Mine, Flag }
```