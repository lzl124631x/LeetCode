# [2389. Longest Subsequence With Limited Sum (Easy)](https://leetcode.com/problems/longest-subsequence-with-limited-sum)

<p>You are given an integer array <code>nums</code> of length <code>n</code>, and an integer array <code>queries</code> of length <code>m</code>.</p>
<p>Return <em>an array </em><code>answer</code><em> of length </em><code>m</code><em> where </em><code>answer[i]</code><em> is the <strong>maximum</strong> size of a <strong>subsequence</strong> that you can take from </em><code>nums</code><em> such that the <strong>sum</strong> of its elements is less than or equal to </em><code>queries[i]</code>.</p>
<p>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,2,1], queries = [3,10,21]
<strong>Output:</strong> [2,3,4]
<strong>Explanation:</strong> We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,3,4,5], queries = [1]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [How Many Numbers Are Smaller Than the Current Number (Easy)](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)
* [Successful Pairs of Spells and Potions (Medium)](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-subsequence-with-limited-sum
// Author: github.com/lzl124631x
// Time: O((N + Q) * logN)
// Space: O(1)
class Solution {
public:
    vector<int> answerQueries(vector<int>& A, vector<int>& Q) {
        sort(begin(A), end(A));
        int N = A.size();
        for (int i = 1; i < N; ++i) A[i] += A[i - 1];
        vector<int> ans;
        for (int q : Q) {
            ans.push_back(upper_bound(begin(A), end(A), q) - begin(A));
        }
        return ans;
    }
};
```