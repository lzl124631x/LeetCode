# [2069. Walking Robot Simulation II (Medium)](https://leetcode.com/problems/walking-robot-simulation-ii/)

<p>A <code>width x height</code> grid is on an XY-plane with the <strong>bottom-left</strong> cell at <code>(0, 0)</code> and the <strong>top-right</strong> cell at <code>(width - 1, height - 1)</code>. The grid is aligned with the four cardinal directions (<code>"North"</code>, <code>"East"</code>, <code>"South"</code>, and <code>"West"</code>). A robot is <strong>initially</strong> at cell <code>(0, 0)</code> facing direction <code>"East"</code>.</p>

<p>The robot can be instructed to move for a specific number of <strong>steps</strong>. For each step, it does the following.</p>

<ol>
	<li>Attempts to move <strong>forward one</strong> cell in the direction it is facing.</li>
	<li>If the cell the robot is <strong>moving to</strong> is <strong>out of bounds</strong>, the robot instead <strong>turns</strong> 90 degrees <strong>counterclockwise</strong> and retries the step.</li>
</ol>

<p>After the robot finishes moving the number of steps required, it stops and awaits the next instruction.</p>

<p>Implement the <code>Robot</code> class:</p>

<ul>
	<li><code>Robot(int width, int height)</code> Initializes the <code>width x height</code> grid with the robot at <code>(0, 0)</code> facing <code>"East"</code>.</li>
	<li><code>void move(int num)</code> Instructs the robot to move forward <code>num</code> steps.</li>
	<li><code>int[] getPos()</code> Returns the current cell the robot is at, as an array of length 2, <code>[x, y]</code>.</li>
	<li><code>String getDir()</code> Returns the current direction of the robot, <code>"North"</code>, <code>"East"</code>, <code>"South"</code>, or <code>"West"</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="example-1" src="https://assets.leetcode.com/uploads/2021/10/09/example-1.png" style="width: 498px; height: 268px;">
<pre><strong>Input</strong>
["Robot", "move", "move", "getPos", "getDir", "move", "move", "move", "getPos", "getDir"]
[[6, 3], [2], [2], [], [], [2], [1], [4], [], []]
<strong>Output</strong>
[null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]

<strong>Explanation</strong>
Robot robot = new Robot(6, 3); // Initialize the grid and the robot at (0, 0) facing East.
robot.move(2);  // It moves two steps East to (2, 0), and faces East.
robot.move(2);  // It moves two steps East to (4, 0), and faces East.
robot.getPos(); // return [4, 0]
robot.getDir(); // return "East"
robot.move(2);  // It moves one step East to (5, 0), and faces East.
                // Moving the next step East would be out of bounds, so it turns and faces North.
                // Then, it moves one step North to (5, 1), and faces North.
robot.move(1);  // It moves one step North to (5, 2), and faces <strong>North</strong> (not West).
robot.move(4);  // Moving the next step North would be out of bounds, so it turns and faces West.
                // Then, it moves four steps West to (1, 2), and faces West.
robot.getPos(); // return [1, 2]
robot.getDir(); // return "West"

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= width, height &lt;= 100</code></li>
	<li><code>1 &lt;= num &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls <strong>in total</strong> will be made to <code>move</code>, <code>getPos</code>, and <code>getDir</code>.</li>
</ul>


**Similar Questions**:
* [Walking Robot Simulation (Medium)](https://leetcode.com/problems/walking-robot-simulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/walking-robot-simulation-ii/
// Author: github.com/lzl124631x
// Time: 
//      move: O(W + H)
//      Robot, getPos, getDir: O(1)
// Space: O(1)
class Robot {
    int dir = 0, dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, w, h, perimeter, x = 0, y = 0;
    string text[4] = {"East","North","West","South"};
public:
    Robot(int width, int height) : w(width), h(height), perimeter(2*(w + h - 2)) {}
    void move(int k) {
        if (k >= perimeter) {
            k %= perimeter;
            if (x == 0 && y == 0 && dir == 0) dir = 3; // Special case: if we are at the beginning (x = 0, y = 0 and facing east), after the round trip, the direction becomes south.
        }
        while (k > 0) {
            auto &[dx, dy] = dirs[dir];
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
                dir = (dir + 1) % 4;
            } else {
                x = nx, y = ny;
                --k;
            }
        }
    }
    vector<int> getPos() {
        return {x,y};
    }
    string getDir() {
        return text[dir];
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/walking-robot-simulation-ii/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(1)
class Robot {
    int dir = 0, dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, w, h, perimeter, x = 0, y = 0;
    string text[4] = {"East","North","West","South"};
    int maxStep() {
        if (dir == 0) return w - 1 - x;
        if (dir == 1) return h - 1 - y;
        if (dir == 2) return x;
        return y;
    }
public:
    Robot(int width, int height) : w(width), h(height), perimeter(2*(w + h - 2)) {}
    void move(int k) {
        if (k >= perimeter) {
            k %= perimeter;
            if (x == 0 && y == 0 && dir == 0) dir = 3; // Special case: if we are at the beginning (x = 0, y = 0 and facing east), after the round trip, the direction becomes south.
        }
        while (k > 0) {
            int step = min(k, maxStep());
            k -= step;
            auto &[dx, dy] = dirs[dir];
            x += dx * step;
            y += dy * step;
            if (k) dir = (dir + 1) % 4;
        }
    }
    vector<int> getPos() {
        return {x,y};
    }
    string getDir() {
        return text[dir];
    }
};
```

## Discuss

https://leetcode.com/problems/walking-robot-simulation-ii/discuss/1575990/C%2B%2B-handle-round-trip