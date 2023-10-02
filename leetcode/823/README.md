# [823. Binary Trees With Factors (Medium)](https://leetcode.com/problems/binary-trees-with-factors/)

<p>Given an array of unique integers, each integer is strictly greater than 1.</p>

<p>We make a binary tree using these integers&nbsp;and each number may be used for any number of times.</p>

<p>Each non-leaf node's&nbsp;value should be equal to the product of the values of it's children.</p>

<p>How many binary trees can we make?&nbsp; Return the answer <strong>modulo 10 ** 9 + 7</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>A = [2, 4]</code>
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can make these trees: <code>[2], [4], [4, 2, 2]</code></pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <code>A = [2, 4, 5, 10]</code>
<strong>Output:</strong> <code>7</code>
<strong>Explanation:</strong> We can make these trees: <code>[2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2]</code>.</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;=&nbsp;1000</code>.</li>
	<li><code>2 &lt;=&nbsp;A[i]&nbsp;&lt;=&nbsp;10 ^ 9</code>.</li>
</ol>


## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/binary-trees-with-factors/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int mod = 1e9 + 7, N = A.size();
        sort(A.begin(), A.end());
        vector<long long> dp(N, 1);
        unordered_map<int, long long> m;
        for (int i = 0; i < N; ++i) m[A[i]] = i;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] || m.find(A[i] / A[j]) == m.end()) continue;
                dp[i] = (dp[i] + dp[j] * dp[m[A[i] / A[j]]]) % mod;
            }
        }
        int ans = 0;
        for (auto n : dp) ans = (ans + n) % mod;
        return ans;
    }
};
```