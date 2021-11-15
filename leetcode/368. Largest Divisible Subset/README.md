# [368. Largest Divisible Subset (Medium)](https://leetcode.com/problems/largest-divisible-subset/)

<p>Given a set of <strong>distinct</strong> positive integers <code>nums</code>, return the largest subset <code>answer</code> such that every pair <code>(answer[i], answer[j])</code> of elements in this subset satisfies:</p>

<ul>
	<li><code>answer[i] % answer[j] == 0</code>, or</li>
	<li><code>answer[j] % answer[i] == 0</code></li>
</ul>

<p>If there are multiple solutions, return any of them.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> [1,3] is also accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,4,8]
<strong>Output:</strong> [1,2,4,8]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>9</sup></code></li>
	<li>All the integers in <code>nums</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Codenation](https://leetcode.com/company/codenation), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1. DP

Sort the array in ascending order.

Let `dp[i]` be the size of the largest divisible subset that is within `A[0..i]` and contain `A[i]`.

```
dp[i] = max(dp[j] + 1 | 0 <= j < i && A[i] % A[j] == 0)
dp[0] = 1
```

In order to recover the subset, we also use a `prev` array where `prev[i]` is the choice of previous index corresponding to `dp[i]`.

```cpp
// OJ: https://leetcode.com/problems/largest-divisible-subset/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size(), last = 0;
        vector<int> dp(N, 1), prev(N, -1), ans;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[last]) last = i;
        }
        for (int i = last; i != -1; i = prev[i]) ans.push_back(A[i]);
        return ans;
    }
};
```