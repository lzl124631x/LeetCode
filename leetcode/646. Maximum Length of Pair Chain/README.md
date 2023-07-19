# [646. Maximum Length of Pair Chain (Medium)](https://leetcode.com/problems/maximum-length-of-pair-chain)

<p>You are given an array of <code>n</code> pairs <code>pairs</code> where <code>pairs[i] = [left<sub>i</sub>, right<sub>i</sub>]</code> and <code>left<sub>i</sub> &lt; right<sub>i</sub></code>.</p>
<p>A pair <code>p2 = [c, d]</code> <strong>follows</strong> a pair <code>p1 = [a, b]</code> if <code>b &lt; c</code>. A <strong>chain</strong> of pairs can be formed in this fashion.</p>
<p>Return <em>the length longest chain which can be formed</em>.</p>
<p>You do not need to use up all the given intervals. You can select pairs in any order.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> pairs = [[1,2],[2,3],[3,4]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest chain is [1,2] -&gt; [3,4].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> pairs = [[1,2],[7,8],[4,5]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest chain is [1,2] -&gt; [4,5] -&gt; [7,8].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == pairs.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>-1000 &lt;= left<sub>i</sub> &lt; right<sub>i</sub> &lt;= 1000</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Flipkart](https://leetcode.com/company/flipkart)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Non-decreasing Subsequences (Medium)](https://leetcode.com/problems/non-decreasing-subsequences/)
* [Longest Non-decreasing Subarray From Two Arrays (Medium)](https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/)

## Solution 1. DP

First sort the array in ascending order.

Let `dp[i]` be the length of maximum chain formed using a subsequence of `A[0..i]` where `A[i]` must be used.

```
dp[i] = max(1, max(1 + dp[j] | pair j can go after pair i ))
```

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-pair-chain/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        int N = A.size();
        vector<int> dp(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j][1] >= A[i][0]) continue;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};
```

## Solution 3. Interval Scheduling Maximization (ISM)

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-pair-chain/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[1] < b[1]; });
        int e = INT_MIN, ans = 0;
        for (auto &v : A) {
            if (e >= v[0]) continue;
            e = v[1];
            ++ans;
        }
        return ans;
    }
};
```