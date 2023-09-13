# [689. Maximum Sum of 3 Non-Overlapping Subarrays (Hard)](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, find three non-overlapping subarrays of length <code>k</code> with maximum sum and return them.</p>

<p>Return the result as a list of indices representing the starting position of each interval (<strong>0-indexed</strong>). If there are multiple answers, return the lexicographically smallest one.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,1,2,6,7,5,1], k = 2
<strong>Output:</strong> [0,3,5]
<strong>Explanation:</strong> Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,1,2,1,2,1,2,1], k = 2
<strong>Output:</strong> [0,2,4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;&nbsp;2<sup>16</sup></code></li>
	<li><code>1 &lt;= k &lt;= floor(nums.length / 3)</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Best Time to Buy and Sell Stock III (Hard)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

## Solution 1. Prefix Sum + Mono-stack

```cpp
// OJ: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& A, int k) {
        int N = A.size(), M = N - k + 1, maxSum = 0;
        vector<int> sum(M);
        for (int i = 0, a = 0, b = 0; i < N; ++i) {
            a += A[i];
            if (i - k >= 0) b += A[i - k];
            if (i - k + 1 >= 0) sum[i - k + 1] = a - b;
        }
        stack<int> s;
        for (int i = M - 1; i >= 2 * k; --i) {
            if (s.empty() || sum[i] >= sum[s.top()]) s.push(i);
        }
        vector<int> ans;
        for (int i = k, left = 0; i < M - k; ++i) {
            if (sum[i - k] > sum[left]) left = i - k;
            int val = sum[left] + sum[i] + sum[s.top()];
            if (val > maxSum) {
                maxSum = val;
                ans = {left, i, s.top()};
            }
            if (i + k == s.top()) s.pop();
        }
        return ans;
    }
};
```