# [673. Number of Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

<p>
Given an unsorted array of integers, find the number of longest increasing subsequence.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,3,5,4,7]
<b>Output:</b> 2
<b>Explanation:</b> The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [2,2,2,2,2]
<b>Output:</b> 5
<b>Explanation:</b> The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
</pre>
<p></p>

<p><b>Note:</b>
Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
</p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Longest Continuous Increasing Subsequence (Easy)](https://leetcode.com/problems/longest-continuous-increasing-subsequence/)

## Solution 1. DP

Consider the subproblem in range `A[0..i]` and the LIS must ends with `A[i]`.

Let `len[i]` be the length of longest LIS ending with `A[i]`.

Let `cnt[i]` be the count of longest LIS ending with `A[i]`.

```
len[i] = 1 + max( len[j] | 0 <= j < i && A[j] < A[i] )
cnt[i] = sum( cnt[j] | 0 <= j < i && len[j] + 1 == len[i] )
```

The answer is

```
sum( cnt[i] | len[i] == maxLen )
    where maxLen = max( len[i] | 0 <= i < N )
```

```cpp
// OJ: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int findNumberOfLIS(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), ans = 0, maxLen = 0;
        vector<int> len(N, 1), cnt(N, 1);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j] >= A[i]) continue;
                if (len[i] < 1 + len[j]) len[i] = 1 + len[j], cnt[i] = cnt[j];
                else if (len[i] == 1 + len[j]) cnt[i] += cnt[j];
            }
            if (len[i] > maxLen) maxLen = len[i], ans = cnt[i];
            else if (len[i] == maxLen) ans += cnt[i];
        }
        return ans;
    }
};
```