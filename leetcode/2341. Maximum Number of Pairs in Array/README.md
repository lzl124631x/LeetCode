# [2341. Maximum Number of Pairs in Array (Easy)](https://leetcode.com/problems/maximum-number-of-pairs-in-array)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. In one operation, you may do the following:</p>
<ul>
	<li>Choose <strong>two</strong> integers in <code>nums</code> that are <strong>equal</strong>.</li>
	<li>Remove both integers from <code>nums</code>, forming a <strong>pair</strong>.</li>
</ul>
<p>The operation is done on <code>nums</code> as many times as possible.</p>
<p>Return <em>a <strong>0-indexed</strong> integer array </em><code>answer</code><em> of size </em><code>2</code><em> where </em><code>answer[0]</code><em> is the number of pairs that are formed and </em><code>answer[1]</code><em> is the number of leftover integers in </em><code>nums</code><em> after doing the operation as many times as possible</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,2,1,3,2,2]
<strong>Output:</strong> [3,1]
<strong>Explanation:</strong>
Form a pair with nums[0] and nums[3] and remove them from nums. Now, nums = [3,2,3,2,2].
Form a pair with nums[0] and nums[2] and remove them from nums. Now, nums = [2,2,2].
Form a pair with nums[0] and nums[1] and remove them from nums. Now, nums = [2].
No more pairs can be formed. A total of 3 pairs have been formed, and there is 1 number leftover in nums.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> [1,0]
<strong>Explanation:</strong> Form a pair with nums[0] and nums[1] and remove them from nums. Now, nums = [].
No more pairs can be formed. A total of 1 pair has been formed, and there are 0 numbers leftover in nums.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> No pairs can be formed, and there is 1 number leftover in nums.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Altimetrik](https://leetcode.com/company/altimetrik)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)
* [Top K Frequent Words (Medium)](https://leetcode.com/problems/top-k-frequent-words/)
* [Sort Array by Increasing Frequency (Easy)](https://leetcode.com/problems/sort-array-by-increasing-frequency/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-pairs-in-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(D) where D is the range of the numbers
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& A) {
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        int pair = 0, single = 0;
        for (auto &[n, c] : cnt) {
            pair += c / 2;
            single += c % 2;
        }
        return {pair, single};
    }
};
```