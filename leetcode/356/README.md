# [356. Line Reflection (Medium)](https://leetcode.com/problems/line-reflection)

<p>Given <code>n</code> points on a 2D plane, find if there is such a line parallel to the y-axis that reflects the given points symmetrically.</p>

<p>In other words, answer whether or not if there exists a line that after reflecting all points over the given line, the original points&#39; set is the same as the reflected ones.</p>

<p><strong>Note</strong> that there can be repeated points.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/356_example_1.PNG" style="width: 389px; height: 340px;" />
<pre>
<strong>Input:</strong> points = [[1,1],[-1,1]]
<strong>Output:</strong> true
<strong>Explanation:</strong> We can choose the line x = 0.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/356_example_2.PNG" style="width: 300px; height: 294px;" />
<pre>
<strong>Input:</strong> points = [[1,1],[-1,-1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> We can&#39;t choose a line.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == points.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>8</sup> &lt;= points[i][j] &lt;= 10<sup>8</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do better than <code>O(n<sup>2</sup>)</code>?</p>


**Companies**:
[Yandex](https://leetcode.com/company/yandex), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Math](https://leetcode.com/tag/math)

**Similar Questions**:
* [Max Points on a Line (Hard)](https://leetcode.com/problems/max-points-on-a-line)
* [Number of Boomerangs (Medium)](https://leetcode.com/problems/number-of-boomerangs)

**Hints**:
* Find the smallest and largest x-value for all points.
* If there is a line then it should be at y = (minX + maxX) / 2.
* For each point, make sure that it has a reflected point in the opposite side.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/line-reflection
// Author: github.com/lzl124631x
// Time: O((logN)^2 + N)
// Space: O(N)
class Solution {
public:
    bool isReflected(vector<vector<int>>& A) {
        map<int, set<int>> m;
        for (auto &p : A) m[p[0]].insert(p[1]);
        long long minX = m.begin()->first, maxX = m.rbegin()->first, sumX = minX + maxX;
        auto L = m.begin();
        auto R = m.rbegin();
        for (; L != m.end() && L->first <= R->first; ++L, ++R) {
            long long lx = L->first, rx = R->first;
            if (lx + rx != sumX) return false;
            auto &lys = L->second, &rys = R->second;
            if (lys != rys) return false;
        }
        return true;
    }
};
```