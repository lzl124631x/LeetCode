# [300. Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)

<p>Given an integer array <code>nums</code>, return the length of the longest strictly increasing subsequence.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, <code>[3,6,2,7]</code> is a subsequence of the array <code>[0,3,1,6,2,2,7]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [10,9,2,5,3,7,101,18]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,0,3,2,3]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [7,7,7,7,7,7,7]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2500</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><b>Follow up:</b>&nbsp;Can you come up with an algorithm that runs in&nbsp;<code>O(n log(n))</code> time complexity?</p>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [ByteDance](https://leetcode.com/company/bytedance), [VMware](https://leetcode.com/company/vmware), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg), [Walmart Labs](https://leetcode.com/company/walmart-labs), [tiktok](https://leetcode.com/company/tiktok), [HRT](https://leetcode.com/company/hrt), [TuSimple](https://leetcode.com/company/tusimple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Increasing Triplet Subsequence (Medium)](https://leetcode.com/problems/increasing-triplet-subsequence/)
* [Russian Doll Envelopes (Hard)](https://leetcode.com/problems/russian-doll-envelopes/)
* [Maximum Length of Pair Chain (Medium)](https://leetcode.com/problems/maximum-length-of-pair-chain/)
* [Number of Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)
* [Minimum ASCII Delete Sum for Two Strings (Medium)](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)
* [Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)
* [Find the Longest Valid Obstacle Course at Each Position (Hard)](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/)
* [Minimum Operations to Make the Array K-Increasing (Hard)](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/)

## Solution 1. DP

Let `dp[i]` be the length of the LIS ending at `A[i]`.

For `dp[i]`, we can try each `dp[j]` before `A[i]` by appending `A[i]` to the LIS represented by `dp[j]` (`0 <= j < i && A[j] < A[i]`)

```
dp[i] = min(1, max( dp[j] + 1 | 0 <= j < i && A[j] < A[i] ))
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

## Solution 2. Binary Search (Regret Greedy)

We use a `vector<int> lis` to store the LIS. `lis` is always sorted.

For each `n` in `A`, we first find the first `lis[i]` that is `>= n`. 

If such `lis[i]` exists, we replace `lis[i]` with `n`. Such operation won't break the LIS but make this LIS easier to extend.

Otherwise, `n` is greater than all values in `lis`, we can simply append `n` into `lis`.

```cpp
// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/longest-increasing-subsequence/solution/
class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        vector<int> v;
        for (int n : A) {
            auto i = lower_bound(begin(v), end(v), n);
            if (i == end(v)) v.push_back(n);
            else *i = n;
        }
        return v.size();
    }
};
```

or doing it in-place

```cpp
// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1) extra space
class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int len = 0;
        for (int i = 0; i < A.size(); ++i) {
            int j = lower_bound(begin(A), begin(A) + len, A[i]) - begin(A);
            if (j == len) ++len;
            A[j] = A[i];
        }
        return len;
    }
};
```

## Note

[1671. Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) is a great bidirectional extension of this problem.