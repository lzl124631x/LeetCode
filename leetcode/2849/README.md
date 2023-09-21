# [2849. Determine if a Cell Is Reachable at a Given Time (Medium)](https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time)

<p>You are given four integers <code>sx</code>, <code>sy</code>, <code>fx</code>, <code>fy</code>, and a <strong>non-negative</strong> integer <code>t</code>.</p>

<p>In an infinite 2D grid, you start at the cell <code>(sx, sy)</code>. Each second, you <strong>must</strong> move to any of its adjacent cells.</p>

<p>Return <code>true</code> <em>if you can reach cell </em><code>(fx, fy)</code> <em>after<strong> exactly</strong></em> <code>t</code> <strong><em>seconds</em></strong>, <em>or</em> <code>false</code> <em>otherwise</em>.</p>

<p>A cell&#39;s <strong>adjacent cells</strong> are the 8 cells around it that share at least one corner with it. You can visit the same cell several times.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/08/05/example2.svg" style="width: 443px; height: 243px;" />
<pre>
<strong>Input:</strong> sx = 2, sy = 4, fx = 7, fy = 7, t = 6
<strong>Output:</strong> true
<strong>Explanation:</strong> Starting at cell (2, 4), we can reach cell (7, 7) in exactly 6 seconds by going through the cells depicted in the picture above. 
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/08/05/example1.svg" style="width: 383px; height: 202px;" />
<pre>
<strong>Input:</strong> sx = 3, sy = 1, fx = 7, fy = 3, t = 3
<strong>Output:</strong> false
<strong>Explanation:</strong> Starting at cell (3, 1), it takes at least 4 seconds to reach cell (7, 3) by going through the cells depicted in the picture above. Hence, we cannot reach cell (7, 3) at the third second.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sx, sy, fx, fy &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= t &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math)

**Similar Questions**:
* [Reaching Points (Hard)](https://leetcode.com/problems/reaching-points)

**Hints**:
* Minimum time to reach the cell should be less than or equal to given time.
* The answer is true if <code>t</code> is greater or equal than the Chebyshev distance from <code>(sx, sy)</code> to <code>(fx, fy)</code>. However, there is one more edge case to be considered.
* The answer is false If <code>sx == fx</code> and <code>sy == fy</code>

## Solution 1.

The minimum time we need is `d = max(abs(fx - sx), abs(fy - sy))`. If `d <= t`, we do it by wasting some steps if necessary.

The only corner case is `d = 0, t = 1` where you can't waste one step and move back.

```cpp
// OJ: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d = max(abs(fx - sx), abs(fy - sy));
        return d == 0 ? t != 1 : d <= t;
    }
};
```