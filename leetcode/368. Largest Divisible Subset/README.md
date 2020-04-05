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

Let `dp[i]` be the size of the largest divisible subset within `A[0..i]` and must contain `A[i]`.

```
dp[i] = max(dp[j] + 1 | 0 <= j < i && A[i] % A[j] == 0)
dp[0] = 1
```

```cpp
// OJ: https://leetcode.com/problems/largest-divisible-subset/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        if (A.empty()) return {};
        sort(A.begin(), A.end());
        int N = A.size(), maxLen = 1, best = 0;
        vector<int> cnt(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0) cnt[i] = max(cnt[i], cnt[j] + 1);
            }
            if (cnt[i] > maxLen) {
                maxLen = cnt[i];
                best = i;
            }
        }
        vector<int> ans{A[best]};
        while (cnt[best] != 1) {
            for (int i = best - 1; i >= 0; --i) {
                if (cnt[i] == cnt[best] - 1) {
                    best = i;
                    break;
                }
            }
            ans.push_back(A[best]);
        }
        return ans;
    }
};
```