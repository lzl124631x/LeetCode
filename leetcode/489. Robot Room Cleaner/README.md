# [489. Robot Room Cleaner (Hard)](https://leetcode.com/problems/robot-room-cleaner/)

<p>Given a robot cleaner in a room modeled as a grid.</p>

<p>Each cell in the grid can be empty or blocked.</p>

<p>The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.</p>

<p>When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.</p>

<p>Design an algorithm to clean the entire room using only the 4 given APIs shown below.</p>

<pre>interface Robot {
&nbsp; // returns true if next cell is open and robot moves into the cell.
&nbsp; // returns false if next cell is obstacle and robot stays on the current cell.
&nbsp; boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
&nbsp; // Each turn will be 90 degrees.
&nbsp; void turnLeft();
&nbsp; void turnRight();

  // Clean the current cell.
  void clean();
}
</pre>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>
room = [
  [1,1,1,1,1,0,1,1],
  [1,1,1,1,1,0,1,1],
  [1,0,1,1,1,1,1,1],
  [0,0,0,1,0,0,0,0],
  [1,1,1,1,1,1,1,1]
],
row = 1,
col = 3

<strong>Explanation:</strong>
All grids in the room are marked by either 0 or 1.
0 means the cell is blocked, while 1 means the cell is accessible.
The robot initially starts at the position of row=1, col=3.
From the top left corner, its position is one row below and three columns right.
</pre>

<p><strong>Notes:</strong></p>

<ol>
	<li>The input is only given to initialize the room and the robot's position internally.&nbsp;You must solve this problem "blindfolded". In other words, you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.</li>
	<li>The robot's initial position will always be in an accessible cell.</li>
	<li>The initial direction of the robot will be facing up.</li>
	<li>All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.</li>
	<li>Assume all four edges of the grid are all surrounded by wall.</li>
</ol>

**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Walls and Gates (Medium)](https://leetcode.com/problems/walls-and-gates/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/robot-room-cleaner/
// Author: github.com/lzl124631x
// Time: O(MN) where M and N are the width and height of the room.
// Space: O(MN)
class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_map<int, unordered_set<int>> seen;
    void dfs(Robot& robot, int x, int y, int dir) {
        for (int i = 0; i < 4; ++i, robot.turnRight(), dir = (dir + 1) % 4) {
            int nx = x + dirs[dir][0];
            int ny = y + dirs[dir][1];
            if (seen[nx].find(ny) != seen[nx].end()) continue;
            seen[nx].insert(ny);
            bool movable = robot.move();
            if (!movable) continue;
            robot.clean();
            dfs(robot, nx, ny, dir);
        }
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
public:
    void cleanRoom(Robot& robot) {
        robot.clean();
        seen[0].insert(0);
        dfs(robot, 0, 0, 0);
    }
};
```