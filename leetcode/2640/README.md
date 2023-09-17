# [2640. Find the Score of All Prefixes of an Array (Medium)](https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array)

<p>We define the <strong>conversion array</strong> <code>conver</code> of an array <code>arr</code> as follows:</p>

<ul>
	<li><code>conver[i] = arr[i] + max(arr[0..i])</code> where <code>max(arr[0..i])</code> is the maximum value of <code>arr[j]</code> over <code>0 &lt;= j &lt;= i</code>.</li>
</ul>

<p>We also define the <strong>score</strong> of an array <code>arr</code> as the sum of the values of the conversion array of <code>arr</code>.</p>

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code>, return <em>an array </em><code>ans</code><em> of length </em><code>n</code><em> where </em><code>ans[i]</code><em> is the score of the prefix</em> <code>nums[0..i]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,7,5,10]
<strong>Output:</strong> [4,10,24,36,56]
<strong>Explanation:</strong> 
For the prefix [2], the conversion array is [4] hence the score is 4
For the prefix [2, 3], the conversion array is [4, 6] hence the score is 10
For the prefix [2, 3, 7], the conversion array is [4, 6, 14] hence the score is 24
For the prefix [2, 3, 7, 5], the conversion array is [4, 6, 14, 12] hence the score is 36
For the prefix [2, 3, 7, 5, 10], the conversion array is [4, 6, 14, 12, 20] hence the score is 56
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,2,4,8,16]
<strong>Output:</strong> [2,4,8,16,32,64]
<strong>Explanation:</strong> 
For the prefix [1], the conversion array is [2] hence the score is 2
For the prefix [1, 1], the conversion array is [2, 2] hence the score is 4
For the prefix [1, 1, 2], the conversion array is [2, 2, 4] hence the score is 8
For the prefix [1, 1, 2, 4], the conversion array is [2, 2, 4, 8] hence the score is 16
For the prefix [1, 1, 2, 4, 8], the conversion array is [2, 2, 4, 8, 16] hence the score is 32
For the prefix [1, 1, 2, 4, 8, 16], the conversion array is [2, 2, 4, 8, 16, 32] hence the score is 64
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Prefix Sum](https://leetcode.com/tag/prefix-sum)

**Similar Questions**:
* [Most Beautiful Item for Each Query (Medium)](https://leetcode.com/problems/most-beautiful-item-for-each-query)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& A) {
        vector<long long> ans;
        long long N = A.size(), sum = 0, mx = 0;
        for (int i = 0; i < N; ++i) {
            mx = max(mx, (long long)A[i]);
            sum += A[i] + mx;
            ans.push_back(sum);
        }
        return ans;
    }
};
```