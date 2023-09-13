# [40. Combination Sum II (Medium)](https://leetcode.com/problems/combination-sum-ii)

<p>Given a collection of candidate numbers (<code>candidates</code>) and a target number (<code>target</code>), find all unique combinations in <code>candidates</code>&nbsp;where the candidate numbers sum to <code>target</code>.</p>
<p>Each number in <code>candidates</code>&nbsp;may only be used <strong>once</strong> in the combination.</p>
<p><strong>Note:</strong>&nbsp;The solution set must not contain duplicate combinations.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> candidates = [10,1,2,7,6,1,5], target = 8
<strong>Output:</strong> 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> candidates = [2,5,2,1,2], target = 5
<strong>Output:</strong> 
[
[1,2,2],
[5]
]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;=&nbsp;candidates.length &lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;candidates[i] &lt;= 50</code></li>
	<li><code>1 &lt;= target &lt;= 30</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/combination-sum-ii
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int, int)> dfs = [&](int i, int target) {
            if (target == 0) {
                ans.push_back(tmp);
                return;
            }
            if (i == A.size()) return;
            if (target >= A[i]) { // pick A[i]
                tmp.push_back(A[i]);
                dfs(i + 1, target - A[i]);
                tmp.pop_back();
            }
            // if we skip A[i], we need to skip all elements that are the same as A[i]
            while (i + 1 < A.size() && A[i + 1] == A[i]) ++i;
            dfs(i + 1, target);
        };
        dfs(0, target);
        return ans;
    }
};
```

## Solution 2. Backtracking

```cpp
// OJ: https://leetcode.com/problems/combination-sum-ii/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int, int)> dfs = [&](int start, int target) {
            if (target == 0) {
                ans.push_back(tmp);
                return;
            }
            for (int i = start; i < A.size() && target >= A[i]; ++i) {
                if (i != start && A[i] == A[i - 1]) continue;
                tmp.push_back(A[i]);
                dfs(i + 1, target - A[i]);
                tmp.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
```