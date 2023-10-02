# [1403. Minimum Subsequence in Non-Increasing Order (Easy)](https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/)

<p>Given the array <code>nums</code>, obtain a subsequence of the array whose sum of elements is <strong>strictly greater</strong> than the sum of the non&nbsp;included elements in such subsequence.&nbsp;</p>

<p>If there are multiple solutions, return the subsequence with <strong>minimum size</strong> and if there still exist multiple solutions, return the subsequence with the <strong>maximum total sum</strong> of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array.&nbsp;</p>

<p>Note that the solution with the given constraints is guaranteed to be&nbsp;<strong>unique</strong>. Also return the answer sorted in <strong>non-increasing</strong> order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,3,10,9,8]
<strong>Output:</strong> [10,9] 
<strong>Explanation:</strong> The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included, however, the subsequence [10,9] has the maximum total sum of its elements.&nbsp;
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,4,7,6,7]
<strong>Output:</strong> [7,7,6] 
<strong>Explanation:</strong> The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to returned in non-decreasing order.  
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [6]
<strong>Output:</strong> [6]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> minSubsequence(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        int sum = accumulate(begin(A), end(A), 0);
        int s = 0;
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i) {
            s += A[i];
            ans.push_back(A[i]);
            if (s > sum - s) break;
        }
        return ans;
    }
};
```