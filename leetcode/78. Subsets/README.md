# [78. Subsets (Medium)](https://leetcode.com/problems/subsets)

<p>Given an integer array <code>nums</code> of <strong>unique</strong> elements, return <em>all possible</em> <span data-keyword="subset" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div id="headlessui-popover-button-:r50:" aria-expanded="false" data-headlessui-state=""><em>subsets</em></div></div></div></span> <em>(the power set)</em>.</p>
<p>The solution set <strong>must not</strong> contain duplicate subsets. Return the solution in <strong>any order</strong>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [[],[0]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li>All the numbers of&nbsp;<code>nums</code> are <strong>unique</strong>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Subsets II (Medium)](https://leetcode.com/problems/subsets-ii/)
* [Generalized Abbreviation (Medium)](https://leetcode.com/problems/generalized-abbreviation/)
* [Letter Case Permutation (Medium)](https://leetcode.com/problems/letter-case-permutation/)
* [Find Array Given Subset Sums (Hard)](https://leetcode.com/problems/find-array-given-subset-sums/)
* [Count Number of Maximum Bitwise-OR Subsets (Medium)](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/subsets/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int)> dfs = [&](int i) {
            if (i == A.size()) {
                ans.push_back(tmp);
                return;
            }
            tmp.push_back(A[i]);
            dfs(i + 1); // Pick A[i]
            tmp.pop_back();
            dfs(i + 1); // Skip A[i]
        };
        dfs(0);
        return ans;
    }
};
```

## Solution 2. Backtracking

```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int N = A.size();
        function<void(int, int)> dfs = [&](int start, int len) {
            if (!len) {
                ans.push_back(tmp);
                return;
            }
            for (int i = start; i <= N - len; ++i) {
                tmp.push_back(A[i]);
                dfs(i + 1, len - 1);
                tmp.pop_back(); // backtrack
            }
        };
        for (int len = 0; len <= N; ++len) dfs(0, len);
        return ans;
    }
};
```

## Solution 3. Bitmask

```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/2764/my-solution-using-bit-manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        int N = 1 << A.size();
        vector<vector<int>> ans(N);
        for (int i = 0; i < A.size(); ++i) { // For each numbers in A
            for (int j = 0; j < N; ++j) { // check if it is in the jth subset in the output
                if (j >> i & 1) ans[j].push_back(A[i]);
            }
        }
        return ans;
    }
};
```

## Solution 4. DP

Let `dp[i]` be the subsets ending with `A[i]`.

```
dp[i] = [ [k, A[i]] | k is in dp[i-1] ]
```

```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<vector<int>> ans(1);
        for (int i = 0; i < A.size(); ++i) {
            int len = ans.size();
            for (int j = 0; j < len; ++j) {
                ans.push_back(ans[j]);
                ans.back().push_back(A[i]);
            }
        }
        return ans;
    }
};
```