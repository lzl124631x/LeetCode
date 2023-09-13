# [1296. Divide Array in Sets of K Consecutive Numbers (Medium)](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/)

<p>Given an array of integers&nbsp;<code>nums</code>&nbsp;and a positive integer&nbsp;<code>k</code>, find whether it's possible to divide this array into&nbsp;sets of <code>k</code> consecutive numbers<br>
Return&nbsp;<code>True</code>&nbsp;if its possible<strong>&nbsp;</strong>otherwise&nbsp;return&nbsp;<code>False</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,3,4,4,5,6], k = 4
<strong>Output:</strong> true
<strong>Explanation:</strong> Array can be divided into [1,2,3,4] and [3,4,5,6].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
<strong>Output:</strong> true
<strong>Explanation:</strong> Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,3,2,2,1,1], k = 3
<strong>Output:</strong> true
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4], k = 3
<strong>Output:</strong> false
<strong>Explanation:</strong> Each array should be divided in subarrays of size 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^9</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>
<strong>Note:</strong> This question is the same as&nbsp;846:&nbsp;<a href="https://leetcode.com/problems/hand-of-straights/">https://leetcode.com/problems/hand-of-straights/</a>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Split Array into Consecutive Subsequences (Medium)](https://leetcode.com/problems/split-array-into-consecutive-subsequences/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// Author: github.com/lzl124631x
// Time: O(NlogM + MK) where M is the number of unique numbers in `A`.
// Space: O(N)
class Solution {
public:
    bool isPossibleDivide(vector<int>& A, int k) {
        if (A.size() % k) return false;
        map<int, int> m;
        for (int n : A) ++m[n];
        for (auto &[n, cnt] : m) {
            if (cnt == 0) continue;
            for (int i = 1; i < k; ++i) {
                if (m.count(n + i) == 0 || m[n + i] < cnt) return false; 
                m[n + i] -= cnt;
            }
        }
        return true;
    }
};
```