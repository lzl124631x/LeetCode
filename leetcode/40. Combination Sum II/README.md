# [40. Combination Sum II (Medium)](https://leetcode.com/problems/combination-sum-ii/)

<p>Given a collection of candidate numbers (<code>candidates</code>) and a target number (<code>target</code>), find all unique combinations in <code>candidates</code>&nbsp;where the candidate numbers sums to <code>target</code>.</p>

<p>Each number in <code>candidates</code>&nbsp;may only be used <strong>once</strong> in the combination.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>All numbers (including <code>target</code>) will be positive integers.</li>
	<li>The solution set must not contain duplicate combinations.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> candidates =&nbsp;<code>[10,1,2,7,6,1,5]</code>, target =&nbsp;<code>8</code>,
<strong>A solution set is:</strong>
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> candidates =&nbsp;[2,5,2,1,2], target =&nbsp;5,
<strong>A solution set is:</strong>
[
&nbsp; [1,2,2],
&nbsp; [5]
]
</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/combination-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> &A, int target, int start, vector<int> &tmp) {
        if (!target) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i < A.size() && target >= A[i]; ++i) {
            if (i != start && A[i] == A[i - 1]) continue;
            tmp.push_back(A[i]);
            dfs(A, target - A[i], i + 1, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        vector<int> tmp;
        dfs(A, target, 0, tmp);
        return ans;
    }
};
```