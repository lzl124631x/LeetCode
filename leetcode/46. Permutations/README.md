# [46. Permutations (Medium)](https://leetcode.com/problems/permutations/submissions/)

<p>Given a collection of <strong>distinct</strong> integers, return all possible permutations.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [1,2,3]
<strong>Output:</strong>
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
</pre>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)
* [Permutation Sequence (Medium)](https://leetcode.com/problems/permutation-sequence/)
* [Combinations (Medium)](https://leetcode.com/problems/combinations/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/permutations/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int start) {
        if (start == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};
```