# [90. Subsets II (Medium)](https://leetcode.com/problems/subsets-ii/)

<p>Given a collection of integers that might contain duplicates, <strong><em>nums</em></strong>, return all possible subsets (the power set).</p>

<p><strong>Note:</strong> The solution set must not contain duplicate subsets.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [1,2,2]
<strong>Output:</strong>
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
</pre>


## Solution 1.

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

## Solution 2.

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