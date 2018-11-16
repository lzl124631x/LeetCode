# [657. Robot Return to Origin (Easy)](https://leetcode.com/problems/robot-return-to-origin/)

<p>There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot <strong>ends up at (0, 0)</strong> after it completes its moves.</p>

<p>The move sequence is represented by a string, and the character moves[i] represents its ith move. Valid moves are R (right), L (left), U (up), and D (down). If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.</p>

<p><strong>Note</strong>: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> "UD"
<b>Output:</b> true 
<strong>Explanation</strong>: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> "LL"
<b>Output:</b> false
<strong>Explanation</strong>: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.
</pre>

## Solution 1.
```cpp
// OJ: https://leetcode.com/problems/robot-return-to-origin/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool judgeCircle(string moves) {
        int V = 0, H = 0;
        for (char c : moves) {
            switch (c) {
                case 'U': ++V; break;
                case 'D': --V; break;
                case 'L': ++H; break;
                case 'R': --H; break;
            }
        }
        return !V && !H;
    }
};
```