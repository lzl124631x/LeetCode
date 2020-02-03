# [39. Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

<p>Given a <strong>set</strong> of candidate numbers (<code>candidates</code>) <strong>(without duplicates)</strong> and a target number (<code>target</code>), find all unique combinations in <code>candidates</code>&nbsp;where the candidate numbers sums to <code>target</code>.</p>

<p>The <strong>same</strong> repeated number may be chosen from <code>candidates</code>&nbsp;unlimited number of times.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>All numbers (including <code>target</code>) will be positive integers.</li>
	<li>The solution set must not contain duplicate combinations.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> candidates = <code>[2,3,6,7], </code>target = <code>7</code>,
<strong>A solution set is:</strong>
[
  [7],
  [2,2,3]
]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> candidates = [2,3,5]<code>, </code>target = 8,
<strong>A solution set is:</strong>
[
&nbsp; [2,2,2,2],
&nbsp; [2,3,3],
&nbsp; [3,5]
]
</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Letter Combinations of a Phone Number (Medium)](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
* [Combination Sum II (Medium)](https://leetcode.com/problems/combination-sum-ii/)
* [Combinations (Medium)](https://leetcode.com/problems/combinations/)
* [Combination Sum III (Medium)](https://leetcode.com/problems/combination-sum-iii/)
* [Factor Combinations (Medium)](https://leetcode.com/problems/factor-combinations/)
* [Combination Sum IV (Medium)](https://leetcode.com/problems/combination-sum-iv/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    vector<vector<int>> dfs(vector<int>& A, int target, int start) {
        if (!target) return {{}};
        if (start == A.size()) return {};
        int n = A[start];
        auto ans = dfs(A, target, start + 1);
        if (target >= n) {
            auto tmp = dfs(A, target - n, start);
            for (auto v : tmp) {
                v.push_back(n);
                ans.push_back(v);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        return dfs(A, target, 0);
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> &c, int t, int start, vector<int> &v) {
        if (!t) {
            res.push_back(v);
            return;
        }
        for (int i = start; i < c.size() && t >= c[i]; ++i) {
            v.push_back(c[i]);
            dfs(c, t - c[i], i, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        dfs(candidates, target, 0, v);
        return res;
    }
};
```