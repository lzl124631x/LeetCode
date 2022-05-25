# [354. Russian Doll Envelopes (Hard)](https://leetcode.com/problems/russian-doll-envelopes/)

<p>You are given a 2D array of integers <code>envelopes</code> where <code>envelopes[i] = [w<sub>i</sub>, h<sub>i</sub>]</code> represents the width and the height of an envelope.</p>

<p>One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.</p>

<p>Return <em>the maximum number of envelopes you can Russian doll (i.e., put one inside the other)</em>.</p>

<p><strong>Note:</strong> You cannot rotate an envelope.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> envelopes = [[5,4],[6,4],[6,7],[2,3]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The maximum number of envelopes you can Russian doll is <code>3</code> ([2,3] =&gt; [5,4] =&gt; [6,7]).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> envelopes = [[1,1],[1,1],[1,1]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= envelopes.length &lt;= 5000</code></li>
	<li><code>envelopes[i].length == 2</code></li>
	<li><code>1 &lt;= w<sub>i</sub>, h<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [ByteDance](https://leetcode.com/company/bytedance), [Uber](https://leetcode.com/company/uber), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [The Number of Weak Characters in the Game (Medium)](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/)

## Solution 1. LIS

Since there are two dimensions, we can sort one of the dimensions, say width `w`, to simplify the problem. When we scan from left to right, the width dimension is already sorted so we can ignore this dimension.

```
[[5,4],[6,4],[6,7],[2,3]]
// after sorting by `w`
[[2,3],[5,4],[6,4],[6,7]]
// Ignoring the `w` dimension
[3,4,4,7]
```

This problem becomes finding the longest increasing subsequence (LIS). But one caveat is that `[3,4,7]` might implies `[[2,3],[6,4],[6,7]]` which is invalid. To avoid this issue, we can sort by height after sorting by width first.

```
[[5,4],[6,4],[6,7],[2,3]]
// after sorting by `w`, then by `h`
[[2,3],[5,4],[6,7],[6,4]]
// Ignoring the `w` dimension
[3,4,7,4] // Now we can't use [6,4] with [6,7]
```

```cpp
// OJ: https://leetcode.com/problems/russian-doll-envelopes/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });
        vector<int> dp;
        for (auto &v : A) {
            auto it = lower_bound(begin(dp), end(dp), v[1]);
            if (it == end(dp)) dp.push_back(v[1]);
            else *it = v[1];
        }
        return dp.size();
    }
};
```