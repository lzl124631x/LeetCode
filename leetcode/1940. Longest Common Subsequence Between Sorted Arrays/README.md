# [1940. Longest Common Subsequence Between Sorted Arrays (Medium)](https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/)

<p>Given an array of integer arrays <code>arrays</code> where each <code>arrays[i]</code> is sorted in <strong>strictly increasing</strong> order, return <em>an integer array representing the <strong>longest common subsequence</strong> between <strong>all</strong> the arrays</em>.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some elements (possibly none) without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arrays = [[<u>1</u>,3,<u>4</u>],
                 [<u>1</u>,<u>4</u>,7,9]]
<strong>Output:</strong> [1,4]
<strong>Explanation:</strong> The longest common subsequence in the two arrays is [1,4].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arrays = [[<u>2</u>,<u>3</u>,<u>6</u>,8],
                 [1,<u>2</u>,<u>3</u>,5,<u>6</u>,7,10],
                 [<u>2</u>,<u>3</u>,4,<u>6</u>,9]]
<strong>Output:</strong> [2,3,6]
<strong>Explanation:</strong> The longest common subsequence in all three arrays is [2,3,6].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arrays = [[1,2,3,4,5],
                 [6,7,8]]
<strong>Output:</strong> []
<strong>Explanation:</strong> There is no common subsequence between the two arrays.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arrays.length &lt;= 100</code></li>
	<li><code>1 &lt;= arrays[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= arrays[i][j] &lt;= 100</code></li>
	<li><code>arrays[i]</code> is sorted in <strong>strictly increasing</strong> order.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Merge Two Sorted Lists (Easy)](https://leetcode.com/problems/merge-two-sorted-lists/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/
// Author: github.com/lzl124631x
// Time: O(NL)
// Space: O(R) where `R` is the range of numbers in `A`
class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& A) {
        int cnt[101] = {};
        vector<int> ans;
        for (auto &v : A) {
            for (int n : v) {
                if (++cnt[n] == A.size()) ans.push_back(n);
            }
        }
        return ans;
    }
};
```