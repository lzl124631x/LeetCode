# [46. Permutations (Medium)](https://leetcode.com/problems/permutations/)

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

## Solution 1. DFS

For a particular DFS level, let `start` be the index of element we manipulate in this level.

We swap `nums[start]` with a digit whose index `>= start`.

After the swap, we DFS one step further, i.e. `dfs(nums, start + 1)`.

Once the children DFS returns, we recover the array by swapping them back.

The exit condition of DFS is when the `start` index points to the last digit, then we can push the current `nums` into answers.

The initial call is `dfs(nums, 0)`.

Note that:

1. This function doesn't care whether the `nums` is sorted.
1. The permutations generated is NOT in lexigraphical order. For example, if input is `[1,2,3]`, then output is `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,2,1],[3,1,2]]`

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

## Solution 2. Use NextPermutation

```cpp
// OJ: https://leetcode.com/problems/permutations/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(1)
class Solution {
    bool nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2, j = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            while (j > i && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        return i >= 0;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans { nums };
        while (nextPermutation(nums)) ans.push_back(nums);
        return ans;
    }
};
```