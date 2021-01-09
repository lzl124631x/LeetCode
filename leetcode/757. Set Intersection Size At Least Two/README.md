# [757. Set Intersection Size At Least Two (Hard)](https://leetcode.com/problems/set-intersection-size-at-least-two/)

<p>An integer interval <code>[a, b]</code> (for integers <code>a &lt; b</code>) is a set of all consecutive integers from <code>a</code> to <code>b</code>, including <code>a</code> and <code>b</code>.</p>

<p>Find the minimum size of a set S such that for every integer interval A in <code>intervals</code>, the intersection of S with A has a size of at least two.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,3],[1,4],[2,5],[3,5]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
Also, there isn't a smaller size set that fulfills the above condition.
Thus, we output the size of this set, which is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,2],[2,3],[2,4],[4,5]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> An example of a minimum sized set is {1, 2, 3, 4, 5}.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 3000</code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub> &lt;&nbsp;b<sub>i</sub> &lt;= 10<sup>8</sup></code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

Keep track of the two intersection points.

```cpp
// OJ: https://leetcode.com/problems/set-intersection-size-at-least-two/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[1] < b[1]; });
        int ans = 0, a = INT_MIN, b = INT_MIN;
        for (auto &v : A) {
            if (v[0] > b) {
                b = v[1];
                a = v[1] - 1;
                ans += 2;
            } else if (v[0] > a) {
                a = v[1];
                if (a == b) --a;
                else if (a > b) swap(a, b);
                ans++;
            }
        }
        return ans;
    }
};
```