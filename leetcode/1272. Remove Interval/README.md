# [1272. Remove Interval (Medium)](https://leetcode.com/problems/remove-interval)

<p>A set of real numbers can be represented as the union of several disjoint intervals, where each interval is in the form <code>[a, b)</code>. A real number <code>x</code> is in the set if one of its intervals <code>[a, b)</code> contains <code>x</code> (i.e. <code>a &lt;= x &lt; b</code>).</p>
<p>You are given a <strong>sorted</strong> list of disjoint intervals <code>intervals</code> representing a set of real numbers as described above, where <code>intervals[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> represents the interval <code>[a<sub>i</sub>, b<sub>i</sub>)</code>. You are also given another interval <code>toBeRemoved</code>.</p>
<p>Return <em>the set of real numbers with the interval </em><code>toBeRemoved</code><em> <strong>removed</strong> from</em><em> </em><code>intervals</code><em>. In other words, return the set of real numbers such that every </em><code>x</code><em> in the set is in </em><code>intervals</code><em> but <strong>not</strong> in </em><code>toBeRemoved</code><em>. Your answer should be a <strong>sorted</strong> list of disjoint intervals as described above.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/removeintervalex1.png" style="width: 510px; height: 319px;">
<pre><strong>Input:</strong> intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
<strong>Output:</strong> [[0,1],[6,7]]
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/removeintervalex2.png" style="width: 410px; height: 318px;">
<pre><strong>Input:</strong> intervals = [[0,5]], toBeRemoved = [2,3]
<strong>Output:</strong> [[0,2],[3,5]]
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]], toBeRemoved = [-1,4]
<strong>Output:</strong> [[-5,-4],[-3,-2],[4,5],[8,9]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= a<sub>i</sub> &lt; b<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-interval
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& A, vector<int>& rm) {
        int N = A.size(), i = 0;
        vector<vector<int>> ans;
        for (auto &r : A) {
            if (r[0] > rm[1] || r[1] <= rm[0]) ans.push_back(r);
            else {
                if (r[0] < rm[0]) ans.push_back({r[0], rm[0]});
                if (r[1] > rm[1]) ans.push_back({rm[1], r[1]});
            }
        }
        return ans;
    }
};
```