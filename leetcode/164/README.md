# [164. Maximum Gap (Hard)](https://leetcode.com/problems/maximum-gap/)

<p>Given an integer array <code>nums</code>, return <em>the maximum difference between two successive elements in its sorted form</em>. If the array contains less than two elements, return <code>0</code>.</p>

<p>You must write an algorithm that runs in linear time and uses linear extra space.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,6,9,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [10]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The array contains less than 2 elements, therefore return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-gap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/5999/bucket-sort-java-solution-with-explanation-o-n-time-and-space
class Solution {
public:
    int maximumGap(vector<int>& A) {
        if (A.size() == 1) return 0;
        int minVal = *min_element(begin(A), end(A));
        int maxVal = *max_element(begin(A), end(A));
        int N = A.size(), gap = (maxVal - minVal + N - 2) / (N - 1);
        vector<int> mn(N - 1, INT_MAX), mx(N - 1, INT_MIN);
        for (int n : A) {
            if (n == minVal || n == maxVal) continue;
            int i = (n - minVal) / gap;
            mn[i] = min(mn[i], n);
            mx[i] = max(mx[i], n);
        }
        int ans = gap, prev = minVal;
        for (int i = 0; i < N - 1; ++i) {
            if (mn[i] == INT_MAX) continue;
            ans = max(ans, mn[i] - prev);
            prev = mx[i];
        }
        return max(ans, maxVal - prev);
    }
};
```