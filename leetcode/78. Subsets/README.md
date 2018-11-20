# [78. Subsets (Medium)](https://leetcode.com/problems/subsets/)

<p>Given a set of <strong>distinct</strong> integers, <em>nums</em>, return all possible subsets (the power set).</p>

<p><strong>Note:</strong> The solution set must not contain duplicate subsets.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong>
[
  [3],
&nbsp; [1],
&nbsp; [2],
&nbsp; [1,2,3],
&nbsp; [1,3],
&nbsp; [2,3],
&nbsp; [1,2],
&nbsp; []
]</pre>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/subsets
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
        dfs(nums, i + 1, v);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(nums, 0, v);
        return ans;
    }
};
```

## Solution 2.
```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(N)
class Solution {
private:
  vector<vector<int>> ans;
  void dfs(vector<int> &nums, int start, int len, vector<int> &tmp) {
    if (!len) {
      ans.push_back(tmp);
      return;
    }
    for (int i = start; i <= nums.size() - len; ++i) {
      tmp.push_back(nums[i]);
      dfs(nums, i + 1, len - 1, tmp);
      tmp.pop_back();
    }
  }
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> tmp;
    for (int len = 0; len <= nums.size(); ++len) dfs(nums, 0, len, tmp);
    return ans;
  }
};
```

## Solution 3. Bit Manipulation

```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/2764/my-solution-using-bit-manipulation
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int N = 1 << nums.size();
    vector<vector<int>> ans(N, vector<int>());
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < N; ++j) {
        if ((j >> i) & 1) ans[j].push_back(nums[i]);
      }
    }
    return ans;
  }
};
```
## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(1)
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans(1);
    for (int i = 0; i < nums.size(); ++i) {
      int len = ans.size();
      for (int j = 0; j < len; ++j) {
        ans.push_back(ans[j]);
        ans.back().push_back(nums[i]);
      }
    }
    return ans;
  }
};
```