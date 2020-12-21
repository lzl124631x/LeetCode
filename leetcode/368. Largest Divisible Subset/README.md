# [368. Largest Divisible Subset (Medium)](https://leetcode.com/problems/largest-divisible-subset/)

<p>Given a set of <b>distinct</b> positive integers, find the largest subset such that every pair (S<sub>i</sub>, S<sub>j</sub>) of elements in this subset satisfies:</p>

<p>S<sub>i</sub> % S<sub>j</sub> = 0 or S<sub>j</sub> % S<sub>i</sub> = 0.</p>

<p>If there are multiple solutions, return any subset is fine.</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,3]</span>
<strong>Output: </strong><span id="example-output-1">[1,2] </span>(of course, [1,3] will also be ok)
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,2,4,8]</span>
<strong>Output: </strong><span id="example-output-2">[1,2,4,8]</span>
</pre>
</div>
</div>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Sort the array in ascending order.

Let `dp[i]` be the size of the largest divisible subset that is within `A[0..i]` and contain `A[i]`.

```
dp[i] = max(dp[j] + 1 | 0 <= j < i && A[i] % A[j] == 0)
dp[0] = 1
```

In order to recover the subset, we make `dp[i]` as a pair, where the second element is the size mentioned aboved, and the first element is the index to the previous element.

```cpp
// OJ: https://leetcode.com/problems/largest-divisible-subset/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        if (A.empty()) return {};
        sort(begin(A), end(A));
        int N = A.size(), best = 0;
        vector<pair<int, int>> dp(N, {-1, 1});
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0 && dp[i].second < dp[j].second + 1) dp[i] = {j, dp[j].second + 1};
            }
            if (dp[i].second > dp[best].second) best = i;
        }
        vector<int> ans;
        while (best >= 0) {
            ans.push_back(A[best]);
            best = dp[best].first;
        }
        return ans;
    }
};
```