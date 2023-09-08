# [2528. Maximize the Minimum Powered City (Hard)](https://leetcode.com/problems/maximize-the-minimum-powered-city)

<p>You are given a <strong>0-indexed</strong> integer array <code>stations</code> of length <code>n</code>, where <code>stations[i]</code> represents the number of power stations in the <code>i<sup>th</sup></code> city.</p>
<p>Each power station can provide power to every city in a fixed <strong>range</strong>. In other words, if the range is denoted by <code>r</code>, then a power station at city <code>i</code> can provide power to all cities <code>j</code> such that <code>|i - j| &lt;= r</code> and <code>0 &lt;= i, j &lt;= n - 1</code>.</p>
<ul>
	<li>Note that <code>|x|</code> denotes <strong>absolute</strong> value. For example, <code>|7 - 5| = 2</code> and <code>|3 - 10| = 7</code>.</li>
</ul>
<p>The <strong>power</strong> of a city is the total number of power stations it is being provided power from.</p>
<p>The government has sanctioned building <code>k</code> more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.</p>
<p>Given the two integers <code>r</code> and <code>k</code>, return <em>the <strong>maximum possible minimum power</strong> of a city, if the additional power stations are built optimally.</em></p>
<p><strong>Note</strong> that you can build the <code>k</code> power stations in multiple cities.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> stations = [1,2,4,5,0], r = 1, k = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
One of the optimal ways is to install both the power stations at city 1. 
So stations will become [1,4,4,5,0].
- City 0 is provided by 1 + 4 = 5 power stations.
- City 1 is provided by 1 + 4 + 4 = 9 power stations.
- City 2 is provided by 4 + 4 + 5 = 13 power stations.
- City 3 is provided by 5 + 4 = 9 power stations.
- City 4 is provided by 5 + 0 = 5 power stations.
So the minimum power of a city is 5.
Since it is not possible to obtain a larger power, we return 5.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> stations = [4,4,4,4], r = 0, k = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
It can be proved that we cannot make the minimum power of a city greater than 4.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == stations.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= stations[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= r&nbsp;&lt;= n - 1</code></li>
	<li><code>0 &lt;= k&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/), [Queue](https://leetcode.com/tag/queue/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Maximum Number of Tasks You Can Assign (Hard)](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/maximize-the-minimum-powered-city
// Author: github.com/lzl124631x
// Time: O(N * log(SUM(A) + k))
// Space: O(N)
class Solution {
public:
    long long maxPower(vector<int>& A, int r, int k) {
        int N = A.size();
        vector<long long> s(N);
        for (int i = 0; i < N; ++i) {
            s[max(i - r, 0)] += A[i];
            if (i + r + 1 < N) s[i + r + 1] -= A[i];
        }
        for (int i = 0; i < N; ++i) {
            if (i - 1 >= 0) s[i] += s[i - 1];
        }
        long long L = *min_element(begin(s), end(s)), R = *max_element(begin(s), end(s)) + k;
        auto valid = [&](long long minPower) {
            vector<long long> diff(N);
            long long d = 0, used = 0;
            for (int i = 0; i < N; ++i) {
                d += diff[i];
                if (s[i] + d >= minPower) continue;
                long long add = minPower - s[i] - d;
                used += add;
                if (used > k) return false;
                d += add;
                if (i + 2 * r + 1 < N) diff[i + 2 * r + 1] -= add;
            }
            return true;
        };
        while (L <= R) {
            long long M = (L + R) / 2;
            if (valid(M)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```