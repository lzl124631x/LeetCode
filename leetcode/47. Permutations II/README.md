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

Similar idea as the DFS solution to [46. Permutations (Medium)](../46.%20Permutations).

But since there are duplicates, we shouldn't swap the `nums[start]` with the same digit twice.

To prevent this from happening, we need to do several modifications:
1. Sort the array at the beginning
1. If `nums[i] == nums[start] (i != start)` then should skip the swap, because this swap won't make any change to the array. In other words, the `nums[start]` represents the digit we tried last time, so we shouldn't try its duplicate again.
1. We can't pass `nums` by reference. We have to copy the array in each DFS step. Because the previous point is based on the assumption that the numbers after `nums[i]` are sorted so that the duplicates following `nums[i]` are skipped. If we pass by reference, the numbers after `nums[i]` might be unsorted, which breaks the assumption.

The drawback of this solution is that we need to keep copying the `nums` array during DFS, which adds time and space complexity.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N! * N)
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
```

## Solution 2.

Assume `nums` is sorted.

Consider [the DFS solution to 46. Permutations](../46.%20Permutations). In each DFS level, assume the numbers starting from index `start` are sorted, then if `nums[i]` is the same as the number in front of itself, when `nums[i]` should be skipped because we've used the same number before.

For example, `start = 0, nums = [1,1,2], i = 1`, since `nums[i] = 1 = nums[i - 1]`, it means that we already did DFS using `nums[i - 1]` so we shouldn't try to put `nums[i]` at `nums[start]`.

If `nums[i]` is the first digit in the sequence of the same digit, we move it to `nums[start]` and DFS one step further.

And after that, we move it back from `nums[start]` to `nums[i]`.

We can not just swap `nums[i]` and `nums[start]` because it will break the assumption that the numbers starting from index `start` are sorted. For example, `start = 0, nums = [1, 1, 2, 2, 3, 3], i = 4`, if we do swap we get `[3, 1, 2, 2, 1, 3]` which breaks the sorted assumption.

So we have to move the numbers one by one.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N! * N)
// Space: O(N)
class Solution {
    vector<vector<int>> ans;
    void move(vector<int> &nums, int from, int to) {
        int tmp = nums[from], d = from > to ? -1 : 1;
        for (int i = from; i != to; i += d) nums[i] = nums[i + d];
        nums[to] = tmp;
    }
    void permute(vector<int> &nums, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        int prev = nums[start];
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == prev) continue;
            move(nums, i, start);
            permute(nums, start + 1);
            move(nums, start, i);
            prev = nums[i];
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        permute(nums, 0);
        return ans;
    }
};
```

## Solution 3.

Similar to Solution 2, based on [the DFS solution to 46. Permutations](../46.%20Permutations).

But when we check whether the `nums[i]` is used before, we simply use a set to store the visited digits!

The logic of this code is way simpler. It's just that the set takes extra space.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N!)
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

Based on [the solution to 31. Next Permutation](../31.%20Next%20Permutation).

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N!)
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

## Solution 5.

See explanations in https://youtu.be/nYFd7VHKyWQ

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
// Ref: https://youtu.be/nYFd7VHKyWQ
class Solution {
    vector<int> cnt;
    vector<int> digit;
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = 0; i < cnt.size(); ++i) {
            if (!cnt[i]) continue;
            cnt[i]--;
            nums[start] = digit[i];
            dfs(nums, start + 1);
            cnt[i]++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        for (auto p : m) {
            digit.push_back(p.first);
            cnt.push_back(p.second);
        }
        dfs(nums, 0);
        return ans;
    }
};
```