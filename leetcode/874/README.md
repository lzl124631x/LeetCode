# [874. Walking Robot Simulation (Easy)](https://leetcode.com/problems/walking-robot-simulation/)

<p>A robot on an infinite grid starts at point (0, 0) and faces north.&nbsp; The robot can receive one of three possible types of commands:</p>

<ul>
	<li><code>-2</code>: turn left 90 degrees</li>
	<li><code>-1</code>: turn right 90 degrees</li>
	<li><code>1 &lt;= x &lt;= 9</code>: move forward <code>x</code> units</li>
</ul>

<p>Some of the grid squares are obstacles.&nbsp;</p>

<p>The <code>i</code>-th obstacle is at grid point <code>(obstacles[i][0], obstacles[i][1])</code></p>

<p>If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)</p>

<p>Return the <strong>square</strong> of the maximum Euclidean distance that the robot will be from the origin.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>commands = <span id="example-input-1-1">[4,-1,3]</span>, obstacles = <span id="example-input-1-2">[]</span>
<strong>Output: </strong><span id="example-output-1">25</span>
<span>Explanation: </span>robot will go to (3, 4)
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>commands = <span id="example-input-2-1">[4,-1,4,-2,4]</span>, obstacles = <span id="example-input-2-2">[[2,4]]</span>
<strong>Output: </strong><span id="example-output-2">65</span>
<strong>Explanation</strong>: robot will be stuck at (1, 4) before turning left and going to (1, 8)
</pre>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= commands.length &lt;= 10000</code></li>
	<li><code>0 &lt;= obstacles.length &lt;= 10000</code></li>
	<li><code>-30000 &lt;= obstacle[i][0] &lt;= 30000</code></li>
	<li><code>-30000 &lt;= obstacle[i][1] &lt;= 30000</code></li>
	<li>The answer is guaranteed to be less than <code>2 ^ 31</code>.</li>
</ol>


**Companies**:  
[Jane Street](https://leetcode.com/company/jane-street)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

Notice that the question asks for the **maximum** distance, not the final distance.

```cpp
// OJ: https://leetcode.com/problems/walking-robot-simulation/
// Author: github.com/lzl124631x
// Time: O(C)
// Space: O(O)
class Solution {
private:
    long long hash(int x, int y) {
        return (long long)(x + 30000) * 100000 + y + 30000;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obs;
        for (auto &ob : obstacles) obs.insert(hash(ob[0], ob[1]));
        int ans = 0, x = 0, y = 0, dir = 0; // 0=N, 1=W, 2=S, 3=E
        int dirs[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        for (int cmd : commands) {
            if (cmd == -2) {
                dir = (dir + 1) % 4;
            } else if (cmd == -1) {
                dir = (dir + 3) % 4;
            } else {
                auto &d = dirs[dir];
                while (cmd--) {
                    if (obs.find(hash(x + d[0], y + d[1])) != obs.end()) break;
                    x += d[0];
                    y += d[1];
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};
```