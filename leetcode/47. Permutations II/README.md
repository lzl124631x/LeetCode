# [47. Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)

<p>Given a collection of numbers that might contain duplicates, return all possible unique permutations.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [1,1,2]
<strong>Output:</strong>
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
</pre>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)
* [Palindrome Permutation II (Medium)](https://leetcode.com/problems/palindrome-permutation-ii/)
* [Number of Squareful Arrays (Hard)](https://leetcode.com/problems/number-of-squareful-arrays/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N! * N^2)
// Space: O(N^2)
// Ref: https://discuss.leetcode.com/topic/8831/a-simple-c-solution-in-only-20-lines
class Solution {
private:
  vector<vector<int>> ans;
  void permute(vector<int> nums, int start) {
    if (start == nums.size() - 1) {
      ans.push_back(nums);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      if (i != start && nums[i] == nums[start]) continue;
      swap(nums[i], nums[start]);
      permute(nums, start + 1);
    }
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    permute(nums, 0);
    return ans;
  }
};
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N! * N^2)
// Space: O(N)
class Solution {
    vector<vector<int>> ans;
    void move(vector<int> &nums, int from, int to) {
        int tmp = nums[from], d = from > to ? -1 : 1;
        for (int i = from; i != to; i += d) nums[i] = nums[i + d];
        nums[to] = tmp;
    }
    void permutate(vector<int> &nums, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        int prev =  nums[start];
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == prev) continue;
            move(nums, i, start);
            permutate(nums, start + 1);
            move(nums, start, i);
            prev = nums[i];
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        permutate(nums, 0);
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N! * N^2)
// Space: O(N^2)
class Solution {
private:
  vector<vector<int>> ans;
  void permute(vector<int> &nums, int start) {
    if (start == nums.size()) {
      ans.push_back(nums);
      return;
    }
    unordered_set<int> s;
    for (int i = start; i < nums.size(); ++i) {
      if (s.count(nums[i])) continue;
      swap(nums[i], nums[start]);
      permute(nums, start + 1);
      swap(nums[i], nums[start]);
      s.insert(nums[i]);
    }
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    permute(nums, 0);
    return ans;
  }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N! * N)
// Space: O(1)
class Solution {
private:
  bool nextPermutation(vector<int> &nums) {
    int i = nums.size() - 2, j = nums.size() - 1;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i >= 0) {
        while (j > i && nums[j] <= nums[i]) --j;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
    return i != -1;
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans { nums };
    while (nextPermutation(nums)) ans.push_back(nums);
    return ans;
  }
};
```