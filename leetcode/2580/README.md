# [2580. Count Ways to Group Overlapping Ranges (Medium)](https://leetcode.com/problems/count-ways-to-group-overlapping-ranges)

<p>You are given a 2D integer array <code>ranges</code> where <code>ranges[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> denotes that all integers between <code>start<sub>i</sub></code> and <code>end<sub>i</sub></code> (both <strong>inclusive</strong>) are contained in the <code>i<sup>th</sup></code> range.</p>
<p>You are to split <code>ranges</code> into <strong>two</strong> (possibly empty) groups such that:</p>
<ul>
	<li>Each range belongs to exactly one group.</li>
	<li>Any two <strong>overlapping</strong> ranges must belong to the <strong>same</strong> group.</li>
</ul>
<p>Two ranges are said to be <strong>overlapping</strong>&nbsp;if there exists at least <strong>one</strong> integer that is present in both ranges.</p>
<ul>
	<li>For example, <code>[1, 3]</code> and <code>[2, 5]</code> are overlapping because <code>2</code> and <code>3</code> occur in both ranges.</li>
</ul>
<p>Return <em>the <strong>total number</strong> of ways to split</em> <code>ranges</code> <em>into two groups</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> ranges = [[6,10],[5,15]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The two ranges are overlapping, so they must be in the same group.
Thus, there are two possible ways:
- Put both the ranges together in group 1.
- Put both the ranges together in group 2.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> ranges = [[1,3],[10,20],[2,5],[4,8]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
Ranges [1,3], and [2,5] are overlapping. So, they must be in the same group.
Again, ranges [2,5] and [4,8] are also overlapping. So, they must also be in the same group. 
Thus, there are four possible ways to group them:
- All the ranges in group 1.
- All the ranges in group 2.
- Ranges [1,3], [2,5], and [4,8] in group 1 and [10,20] in group 2.
- Ranges [1,3], [2,5], and [4,8] in group 2 and [10,20] in group 1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= ranges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>ranges[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-ways-to-group-overlapping-ranges
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int countWays(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        long end = INT_MIN, mod = 1e9 + 7, cnt = 0;
        for (auto &r : A) {
            cnt += r[0] > end;
            end = max(end, (long)r[1]);
        }
        auto pow = [&](long base, long e) {
            long ans = 1;
            while (e) {
                if (e & 1) ans = ans * base % mod;
                base = base * base % mod;
                e >>= 1;
            }
            return ans;
        };
        return pow(2, cnt);
    }
};
```