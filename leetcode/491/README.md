# [491. Increasing Subsequences (Medium)](https://leetcode.com/problems/increasing-subsequences/)

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

**Example:**
```
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
```

**Note:**
1. The length of the given array will not exceed 15.
2. The range of integer in the given array is [-100,100].
3. The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

## Solution 1

Use a `set<vector<int>> ans` to hold the results and to keep the sub-sequences being unique, which initially hold one empty `vector<int>`.

For each number in `nums`, for each vector `seq` in `ans`, if the number is greater or equal to the last number in `seq`, `seq` concatenated with the number should be inserted into `ans`.

Finally, remove all the vectors holding only one number from `ans`.

```cpp
// OJ: https://leetcode.com/problems/increasing-subsequences
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    set<vector<int>> ans;
    ans.insert(vector<int>());
    for (int i = 0; i < nums.size(); ++i) {
      set<vector<int>> newAns = ans;
      for (auto it = ans.begin(); it != ans.end(); ++it) {
        vector<int> seq = *it;
        if (seq.size() && nums[i] < seq.back()) continue;
        seq.push_back(nums[i]);
        newAns.insert(seq);
      }
      ans = newAns;
    }
    for (auto it = ans.begin(); it != ans.end(); ) {
      if (it->size() <= 1) it = ans.erase(it);
      else ++it;
    }
    return vector<vector<int>>(ans.begin(), ans.end());
  }
};
```

## Solution 2. DFS
Use a `set<vector<int>> s` to hold the results and to keep the sub-sequences being unique.

DFS starts at index `start` (being 0 at the first call). For each number indexed at/after `start`, attempt to add it into the sub-sequence.

Add any subsequences of length greater than 1.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
private:
  set<vector<int>> s;
  void dfs(vector<int> &nums, int start, vector<int> &seq) {
    if (seq.size() > 1) s.insert(seq);
    for (int i = start; i < nums.size(); ++i) {
      if (seq.size() && nums[i] < seq.back()) continue;
      seq.push_back(nums[i]);
      dfs(nums, i + 1, seq);
      seq.pop_back();
    }
  }
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> seq;
    dfs(nums, 0, seq);
    return vector<vector<int>>(s.begin(), s.end());
  }
};
```

## Solution 3. DFS
`set<vector<int>>` is time-consuming when comparing the items. To remove it, consider the fact that, in solution 2, for one DFS call, if one number is visited already, the following occurrance of that number should be omitted. To achieve it, `unordered_set<int>` is enough.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
private:
  vector<vector<int>> ans;
  void dfs(vector<int> &nums, int start, vector<int> &seq) {
    if (start == nums.size()) return;
    unordered_set<int> visited;
    for (int i = start; i < nums.size(); ++i) {
      int n = nums[i];
      if (visited.count(n) || (seq.size() && seq.back() > n)) continue;
      visited.insert(n);
      seq.push_back(n);
      if (seq.size() > 1) ans.push_back(seq);
      dfs(nums, i + 1, seq);
      seq.pop_back();
    }
  }
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> seq;
    dfs(nums, 0, seq);
    return ans;
  }
};
```