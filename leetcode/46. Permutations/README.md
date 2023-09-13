# [46. Permutations (Medium)](https://leetcode.com/problems/permutations)

<p>Given an array <code>nums</code> of distinct integers, return <em>all the possible permutations</em>. You can return the answer in <strong>any order</strong>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0,1]
<strong>Output:</strong> [[0,1],[1,0]]
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> [[1]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 6</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li>All the integers of <code>nums</code> are <strong>unique</strong>.</li>
</ul>

**Companies**:
[Bloomberg](https://leetcode.com/company/bloomberg), [Apple](https://leetcode.com/company/apple), [Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)
* [Permutation Sequence (Hard)](https://leetcode.com/problems/permutation-sequence/)
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
public:
    vector<vector<int>> permute(vector<int>& A) {
        vector<vector<int>> ans;
        int N = A.size();
        function<void(int)> dfs = [&](int start) {
            if (start == N) {
                ans.push_back(A);
                return;
            }
            for (int i = start; i < N; ++i) {
                swap(A[i], A[start]);
                dfs(start + 1);
                swap(A[i], A[start]);
            }
        };
        dfs(0);
        return ans;
    }
};
```

## Solution 2. Use NextPermutation

Reuse the solution for [31. Next Permutation (Medium)](https://leetcode.com/problems/next-permutation).

```cpp
// OJ: https://leetcode.com/problems/permutations/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(1)
class Solution {
    bool nextPermutation(vector<int>& A) {
        int N = A.size(), i = N - 1;
        while (i - 1 >= 0 && A[i - 1] >= A[i]) --i; // find the first element of a descending subarray from the end.
        reverse(begin(A) + i, end(A)); // reverse this descending subarray
        if (i == 0) return false;
        swap(*upper_bound(begin(A) + i, end(A), A[i - 1]), A[i - 1]); // swap A[i-1] with the first element greater than `A[i-1]` in the subarray.
        return true;
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