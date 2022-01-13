# [1041. Robot Bounded In Circle (Medium)](https://leetcode.com/problems/robot-bounded-in-circle/)

<p>On an infinite plane, a robot initially stands at <code>(0, 0)</code> and faces north. The robot can receive one of three instructions:</p>

<ul>
	<li><code>"G"</code>: go straight 1 unit;</li>
	<li><code>"L"</code>: turn 90 degrees to the left;</li>
	<li><code>"R"</code>: turn 90 degrees to the right.</li>
</ul>

<p>The robot performs the <code>instructions</code> given in order, and repeats them forever.</p>

<p>Return <code>true</code> if and only if there exists a circle in the plane such that the robot never leaves the circle.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> instructions = "GGLLGG"
<strong>Output:</strong> true
<strong>Explanation:</strong> The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> instructions = "GG"
<strong>Output:</strong> false
<strong>Explanation:</strong> The robot moves north indefinitely.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> instructions = "GL"
<strong>Output:</strong> true
<strong>Explanation:</strong> The robot moves from (0, 0) -&gt; (0, 1) -&gt; (-1, 1) -&gt; (-1, 0) -&gt; (0, 0) -&gt; ...</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= instructions.length &lt;= 100</code></li>
	<li><code>instructions[i]</code> is <code>'G'</code>, <code>'L'</code> or, <code>'R'</code>.</li>
</ul>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Simulation](https://leetcode.com/tag/simulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/robot-bounded-in-circle/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0, dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
        for (int i = 0; i < 4; ++i) {
            for (char c : instructions) {
                if (c == 'G') x += dir[d][0], y += dir[d][1];
                else if (c == 'L') d = (d + 1) % 4;
                else d = (d + 3) % 4;
            }
            if (x == 0 && y == 0) return true;
        }
        return false;
    }
};
```