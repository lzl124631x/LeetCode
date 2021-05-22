# [1197. Minimum Knight Moves (Medium)](https://leetcode.com/problems/minimum-knight-moves/)

<p>In an <strong>infinite</strong> chess board with coordinates from <code>-infinity</code>&nbsp;to <code>+infinity</code>, you have a <strong>knight</strong> at square&nbsp;<code>[0, 0]</code>.</p>

<p>A&nbsp;knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="height: 200px; width: 200px;"></p>

<p>Return the&nbsp;minimum number of steps needed to move the knight to the square <code>[x, y]</code>.&nbsp; It is guaranteed the answer exists.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> x = 2, y = 1
<strong>Output:</strong> 1
<strong>Explanation: </strong>[0, 0] → [2, 1]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> x = 5, y = 5
<strong>Output:</strong> 4
<strong>Explanation: </strong>[0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>|x| + |y| &lt;= 300</code></li>
</ul>


**Companies**:  
[Expedia](https://leetcode.com/company/expedia), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Mathworks](https://leetcode.com/company/mathworks), [Google](https://leetcode.com/company/google), [Indeed](https://leetcode.com/company/indeed), [Microsoft](https://leetcode.com/company/microsoft), [Qualtrics](https://leetcode.com/company/qualtrics), [Cisco](https://leetcode.com/company/cisco), [Twitter](https://leetcode.com/company/twitter)

**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS with optimizations

Firstly, it's symmetric for axes. So let `x = abs(x)`, `y = abs(y)`.

Secondly, attempts with `x` or `y` values smaller than `-1` should be ignored.

For example, to reach `(1,1)` from `(0,0)`, the best way is to get `(2,-1)` or `(-1,2)` first, then `(1,1)` (two steps). If we eliminate all coordinates with negative numbers, then we can't reach `(1,1)` from `(0,0)` within two steps.

```cpp
// OJ: https://leetcode.com/problems/minimum-knight-moves/
// Author: github.com/lzl124631x
// Time: O(XY)
// Space: O(XY)
class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        queue<pair<int, int>> q;
        set<pair<int, int>> s;
        q.emplace(0, 0);
        s.emplace(0, 0);
        int ans = 0, dirs[8][2] = {{1, 2}, {1,-2}, {2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [a, b] = q.front();
                q.pop();
                if (a == x && b == y) return ans;
                for (auto &[dx, dy] : dirs) {
                    pair<int, int> next = {a + dx, b + dy};
                    if (abs(next.first) + abs(next.second) > 300 || next.first < -1 || next.second < -1 || s.count(next)) continue;
                    s.insert(next);
                    q.push(next);
                }
            }
            ++ans;
        }
        return 0;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/minimum-knight-moves/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-knight-moves/discuss/682850/C%2B%2B-O(1)-Formula-solution-with-plot-explanation
class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        if (x < y) swap(x, y);
        if (x == 1 and y == 0) return 3;
        if (x == 2 and y == 2) return 4;
        if (y <= x / 2) {
            return (x + 1) / 2 + (x / 2 - y) % 2;
        }
        return (x + y) / 3 + (x + y) % 3; 
    }
};
```