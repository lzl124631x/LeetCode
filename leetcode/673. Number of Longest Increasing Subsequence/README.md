# [673. Number of Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/number-of-longest-increasing-subsequence)

<p>Given an integer array&nbsp;<code>nums</code>, return <em>the number of longest increasing subsequences.</em></p>
<p><strong>Notice</strong> that the sequence has to be <strong>strictly</strong> increasing.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,5,4,7]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,2,2,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Longest Continuous Increasing Subsequence (Easy)](https://leetcode.com/problems/longest-continuous-increasing-subsequence/)
* [Longest Increasing Subsequence II (Hard)](https://leetcode.com/problems/longest-increasing-subsequence-ii/)

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

## Solution 2. Top-down DP

```cpp
// OJ: https://leetcode.com/problems/number-of-longest-increasing-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int findNumberOfLIS(vector<int>& A) {
        int N = A.size(), maxLen = 0, ans = 0;
        vector<int> len(N), cnt(N);
        function<void(int)> dp = [&](int i) {
            if (i == N || len[i]) return;
            len[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (A[j] >= A[i]) continue;
                dp(j);
                if (len[i] < 1 + len[j]) len[i] = 1 + len[j], cnt[i] = cnt[j];
                else if (len[i] == 1 + len[j]) cnt[i] += cnt[j];
            }
        };
        for (int i = 0; i < N; ++i) {
            dp(i);
            if (len[i] > maxLen) maxLen = len[i], ans = cnt[i];
            else if (len[i] == maxLen) ans += cnt[i];
        }
        return ans;
    }
};
```