# [1197. Minimum Knight Moves (Medium)](https://leetcode.com/problems/minimum-knight-moves)

<p>In an <strong>infinite</strong> chess board with coordinates from <code>-infinity</code> to <code>+infinity</code>, you have a <strong>knight</strong> at square <code>[0, 0]</code>.</p>

<p>A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.</p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="height: 250px; width: 250px;" />
<p>Return <em>the minimum number of steps needed to move the knight to the square</em> <code>[x, y]</code>. It is guaranteed the answer exists.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> x = 2, y = 1
<strong>Output:</strong> 1
<strong>Explanation: </strong>[0, 0] &rarr; [2, 1]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> x = 5, y = 5
<strong>Output:</strong> 4
<strong>Explanation: </strong>[0, 0] &rarr; [2, 1] &rarr; [4, 2] &rarr; [3, 4] &rarr; [5, 5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-300 &lt;= x, y &lt;= 300</code></li>
	<li><code>0 &lt;= |x| + |y| &lt;= 300</code></li>
</ul>


**Companies**:
[Citadel](https://leetcode.com/company/citadel), [Amazon](https://leetcode.com/company/amazon), [Expedia](https://leetcode.com/company/expedia), [Google](https://leetcode.com/company/google), [Indeed](https://leetcode.com/company/indeed), [Facebook](https://leetcode.com/company/facebook), [Booking.com](https://leetcode.com/company/bookingcom), [Microsoft](https://leetcode.com/company/microsoft), [LinkedIn](https://leetcode.com/company/linkedin), [Adobe](https://leetcode.com/company/adobe), [IMC](https://leetcode.com/company/imc), [athenahealth](https://leetcode.com/company/athenahealth), [Nvidia](https://leetcode.com/company/nvidia)

**Related Topics**:  
[Breadth-First Search](https://leetcode.com/tag/breadth-first-search)

**Similar Questions**:
* [Check Knight Tour Configuration (Medium)](https://leetcode.com/problems/check-knight-tour-configuration)

**Hints**:
* You can simulate the movements since the limits are low.
* Is there a search algorithm applicable to this problem?
* Since we want the minimum number of moves, we can use Breadth First Search.

## Solution 1. BFS with optimizations

Firstly, it's symmetric for axes. So let `x = abs(x)`, `y = abs(y)`.

Secondly, attempts with `x` or `y` values smaller than `-1` should be ignored.

For example, to reach `(1,1)` from `(0,0)`, the best way is to get `(2,-1)` or `(-1,2)` first, then `(1,1)` (two steps). If we eliminate all coordinates with negative numbers, then we can't reach `(1,1)` from `(0,0)` within two steps.

```cpp
// OJ: https://leetcode.com/problems/minimum-knight-moves
// Author: github.com/lzl124631x
// Time: O(XY)
// Space: O(XY)
class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        bool seen[302][302] = {};
        seen[x + 1][y + 1] = true; // Since -1 is the only negative value, we offset the positions by 1. So (0,0) becomes (1,1) and (x,y) becomes (x+1,y+1)
        queue<pair<int, int>> q{{{x + 1, y + 1}}};
        int step = 0, dirs[8][2] = {{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                if (x == 1 && y == 1) return step;
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a > 301 || b < 0 || b > 301 || seen[a][b]) continue;
                    seen[a][b] = true;
                    q.emplace(a, b);
                }
            }
            ++step;
        }
        return -1;
    }
};
```

## Solution 2.

<p>Please stare at the image first:<br>
<img src="https://assets.leetcode.com/users/cowtony/image_1591939284.png" alt="image"></p>
<p>Some interesting pattern here:</p>
<ol>
<li>Convert the <code>(x, y)</code> into <code>x &gt;= y &gt;= 0</code> due to the 3 direction symmetry of the plot (now we reduce the plane to 1/8).</li>
<li>Then keep divide the problem into two parts: <strong>lower</strong> and <strong>upper</strong>.</li>
<li>For lower half:<br>
Notice <code>x</code> value is dominant the result.<br>
<code>(x + 1) / 2</code> is the base indicate the steps generally grow 1 when x increase 2.<br>
<code>(x / 2 - y) % 2</code> basically tunning the detail, because the number is meshed.</li>
<li>For upper half:<br>
Notice <code>x + y</code> is dominant the result.<br>
Also, if <code>step = n</code>, then <code>x + y = 3n or 3n - 2 or 3n - 4</code>, always these 3 numbers.<br>
So <code>n</code> is a function of <code>x + y</code>, why there is a exact match? becuase the reminder of <code>3n</code>, <code>3n - 2</code>, <code>3n - 4</code> cover all the mod of 3, which is <code>0, 1, 2</code>.<br>
<code>(x + y) % 3 == 0  -&gt; x + y = 3n</code><br>
<code>(x + y) % 3 == 1  -&gt; x + y = 3n - 2</code><br>
<code>(x + y) % 3 == 2  -&gt; x + y = 3n - 4 = 3n - 2 * ((x + y) % 3)</code><br>
<code>n = (x + y + 2 * ((x + y) % 3)) / 3 = (x + y) / 3 + (x + y) % 3</code></li>
</ol>

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