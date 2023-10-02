# [90. Subsets II (Medium)](https://leetcode.com/problems/subsets-ii)

<p>Given an integer array <code>nums</code> that may contain duplicates, return <em>all possible</em> <span data-keyword="subset" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div id="headlessui-popover-button-:r5g:" aria-expanded="false" data-headlessui-state=""><em>subsets</em></div></div></div></span><em> (the power set)</em>.</p>
<p>The solution set <strong>must not</strong> contain duplicate subsets. Return the solution in <strong>any order</strong>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,2]
<strong>Output:</strong> [[],[1],[1,2],[1,2,2],[2],[2,2]]
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
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Subsets (Medium)](https://leetcode.com/problems/subsets/)
* [Find Array Given Subset Sums (Hard)](https://leetcode.com/problems/find-array-given-subset-sums/)

## Solution 1. DFS

Consider how duplicates are generated.

Say `A = [2,2]`, let `use[i] = 1 or 0` mean whether we use `A[i]`.

* `use=[1,1], subset=[2,2]`
* `use=[1,0], subset=[2,x]`
* `use=[0,1], subset=[x,2]`. Duplication happens here. The pattern is that, if we don't use `A[i]`, we shouldn't use any subsequent `A[j] == A[i] (j > i)`.
* `use=[0,0], subset=[x,x]`

```cpp
// OJ: https://leetcode.com/problems/subsets-ii/
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        vector<int> tmp;
        int N = A.size();
        function<void(int)> dfs = [&](int i) { // dfs(i) tries using and not using A[i]
            if (i == N) {
                ans.push_back(tmp);
                return;
            }
            // use A[i]
            tmp.push_back(A[i]);
            dfs(i + 1);
            tmp.pop_back();
            // skip A[i]. When A[i] is skipped, we shouldn't use any `A[j] == A[i] (j > i)` because that will cause duplication. We need to skip subsequent same characters and start with a different character.
            while (i + 1 < N && A[i + 1] == A[i]) ++i;
            dfs(i + 1);
        };
        dfs(0);
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/subsets-ii/
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(N)
class Solution {
private:
public:
    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        vector<int> tmp;
        int N = A.size();
        function<void(int, int)> dfs = [&](int start, int len) {
            if (!len) {
                ans.push_back(tmp);
                return;
            }
            for (int i = start; i <= N - len; ++i) {
                if (i != start && A[i] == A[i - 1]) continue;
                tmp.push_back(A[i]);
                dfs(i + 1, len - 1);
                tmp.pop_back();
            }
        };
        for (int len = 0; len <= N; ++len) dfs(0, len);
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/subsets-ii/
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans(1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ) {
            int cnt = 0, n = nums[i], len = ans.size();
            while (i < nums.size() && nums[i] == n) ++cnt, ++i;
            for (int j = 0; j < len; ++j) {
                vector<int> sub = ans[j];
                for (int k = 0; k < cnt; ++k) {
                    sub.push_back(n);
                    ans.push_back(sub);
                }
            }
        }
        return ans;
    }
};
```