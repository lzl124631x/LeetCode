# [1218. Longest Arithmetic Subsequence of Given Difference (Medium)](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference)

<p>Given an integer array <code>arr</code> and an integer <code>difference</code>, return the length of the longest subsequence in <code>arr</code> which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals <code>difference</code>.</p>
<p>A <strong>subsequence</strong> is a sequence that can be derived from <code>arr</code> by deleting some or no elements without changing the order of the remaining elements.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [1,2,3,4], difference = 1
<strong>Output:</strong> 4
<strong>Explanation: </strong>The longest arithmetic subsequence is [1,2,3,4].</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> arr = [1,3,5,7], difference = 1
<strong>Output:</strong> 1
<strong>Explanation: </strong>The longest arithmetic subsequence is any single element.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> arr = [1,5,7,8,5,3,4,2,1], difference = -2
<strong>Output:</strong> 4
<strong>Explanation: </strong>The longest arithmetic subsequence is [7,5,3,1].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= arr[i], difference &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Destroy Sequential Targets (Medium)](https://leetcode.com/problems/destroy-sequential-targets/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestSubsequence(vector<int>& A, int d) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int n : A) {
            if (m.count(n - d)) m[n] = m[n - d] + 1;
            else m[n] = 1;
            ans = max(ans, m[n]);
        return ans;
    }
};
```