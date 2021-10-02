# [90. Subsets II (Medium)](https://leetcode.com/problems/subsets-ii/)

<p>Given an integer array <code>nums</code> that may contain duplicates, return <em>all possible subsets (the power set)</em>.</p>

<p>The solution set <strong>must not</strong> contain duplicate subsets. Return the solution in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,2]
<strong>Output:</strong> [[],[1],[1,2],[1,2,2],[2],[2,2]]
</pre><p><strong>Example 2:</strong></p>
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
[Apple](https://leetcode.com/company/apple), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Subsets (Medium)](https://leetcode.com/problems/subsets/)

## Solution 1. Brute Force

There are at most `2^N` subsets in the `set`. Each insertion into the `set` takes `O(log(2^N) * N) = O(N^2)` time. So overall the time complexity is `O(2^N * N^2)`.

```cpp
// OJ: https://leetcode.com/problems/subsets-ii/
// Author: github.com/lzl124631x
// Time: O(2^N * N^2)
// Space: O(2^N * N)
class Solution {
    set<vector<int>> s;
    vector<int> tmp;
    void dfs(vector<int> &A, int i) {
        if (i == A.size()) {
            s.insert(tmp);
            return;
        }
        dfs(A, i + 1);
        tmp.push_back(A[i]);
        dfs(A, i + 1);
        tmp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        sort(begin(A), end(A));
        dfs(A, 0);
        return vector<vector<int>>(begin(s), end(s));
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
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int i, vector<int> &v) {
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        dfs(nums, i + 1, v);
        v.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        dfs(nums, i + 1, v);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, v);
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
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int start, vector<int> &sub, int len) {
        if (!len) {
            ans.push_back(sub);
            return;
        }
        for (int i = start; i <= nums.size() - len; ++i) {
            if (i != start && nums[i] == nums[i - 1]) continue;
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, len - 1);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        for (int i = 0; i <= nums.size(); ++i) dfs(nums, 0, v, i);
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