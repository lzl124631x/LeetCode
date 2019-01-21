# [77. Combinations (Medium)](https://leetcode.com/problems/combinations/)

<p>Given two integers <em>n</em> and <em>k</em>, return all possible combinations of <em>k</em> numbers out of 1 ... <em>n</em>.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>&nbsp;n = 4, k = 2
<strong>Output:</strong>
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google)

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
private:
    vector<vector<int>> ans;
    void dfs(int start, int n, int k, vector<int>& tmp) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i <= n - k + 1 + tmp.size(); ++i) {
            tmp.push_back(i);
            dfs(i + 1, n, k, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(1, n, k, tmp);
        return ans;
    }
};
```