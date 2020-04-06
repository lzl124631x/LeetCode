# [300. Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)

<p>Given an unsorted array of integers, find the length of longest increasing subsequence.</p>

<p><b>Example:</b></p>

<pre><b>Input:</b> <code>[10,9,2,5,3,7,101,18]
</code><b>Output: </b>4 
<strong>Explanation: </strong>The longest increasing subsequence is <code>[2,3,7,101]</code>, therefore the length is <code>4</code>. </pre>

<p><strong>Note: </strong></p>

<ul>
	<li>There may be more than one LIS combination, it is only necessary for you to return the length.</li>
	<li>Your algorithm should run in O(<i>n<sup>2</sup></i>) complexity.</li>
</ul>

<p><b>Follow up:</b> Could you improve it to O(<i>n</i> log <i>n</i>) time complexity?</p>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Increasing Triplet Subsequence (Medium)](https://leetcode.com/problems/increasing-triplet-subsequence/)
* [Russian Doll Envelopes (Hard)](https://leetcode.com/problems/russian-doll-envelopes/)
* [Maximum Length of Pair Chain (Medium)](https://leetcode.com/problems/maximum-length-of-pair-chain/)
* [Number of Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)
* [Minimum ASCII Delete Sum for Two Strings (Medium)](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)

## Solution 1. DP

```
dp[i] = max( dp[j] + 1 | 0 <= j < i && A[j] < A[i] )
dp[0] = 1
```

```cpp
// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<int> dp(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};
```