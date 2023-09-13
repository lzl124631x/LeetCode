# [77. Combinations (Medium)](https://leetcode.com/problems/combinations)

<p>Given two integers <code>n</code> and <code>k</code>, return <em>all possible combinations of</em> <code>k</code> <em>numbers chosen from the range</em> <code>[1, n]</code>.</p>

<p>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4, k = 2
<strong>Output:</strong> [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
<strong>Explanation:</strong> There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1, k = 1
<strong>Output:</strong> [[1]]
<strong>Explanation:</strong> There is 1 choose 1 = 1 total combination.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/combinations/
// Author: github.com/lzl124631x
// Time: O(K!)
// Space: O(K)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int)> dfs = [&](int start) {
            if (tmp.size() == k) {
                ans.push_back(tmp);
                return;
            }
            for (int i = start; i <= n - k + tmp.size() + 1; ++i) {
                tmp.push_back(i);
                dfs(i + 1);
                tmp.pop_back();
            }
        };
        dfs(1);
        return ans;
    }
};
```