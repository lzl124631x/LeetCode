# [526. Beautiful Arrangement (Medium)](https://leetcode.com/problems/beautiful-arrangement)

Suppose you have `N` integers from `1` to `N`. We define a beautiful arrangement as an array that is constructed by these `N` numbers successfully if one of the following is true for the `ith` position `(1 ≤ i ≤ N)`` in this array:

The number at the `ith` position is divisible by `i`.
`i` is divisible by the number at the `ith` position.
Now given `N`, how many beautiful arrangements can you construct?

**Example 1:**
```
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
```

**Note:**
`N` is a positive integer and will not exceed 15.

## Solution 1. Backtracking using `vector`

Use an `vector<int> nums` to hold all the numbers. For each position `pos (0 <= pos < N)`, iterate through all the numbers, if a number satisfy the condition, mark it as used by setting it to `0`. Once `pos` reaches `N`, increment the count.

```cpp
// OJ: https://leetcode.com/problems/beautiful-arrangement
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
  int dfs(vector<int> &nums, int pos) {
    if (pos == nums.size()) return 1;
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (!nums[i] || (nums[i] % (pos + 1) && (pos + 1) % nums[i])) continue;
      int val = nums[i];
      nums[i] = 0;
      cnt += dfs(nums, pos + 1);
      nums[i] = val;
    }
    return cnt;
  }
public:
  int countArrangement(int N) {
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) nums[i] = i + 1;
    return dfs(nums, 0);
  }
};
```

## Solution 2. Backtracking using `set`
To my intuition, solution 1 is slow because in each `dfs` it needs to iterate through all the numbers. I tried to use `set` to reduce the scale of numbers to visit.

But actually it doesn't reduce the overall complexity. While the number of `dfs` call still remains `O(N^2)`, the insertion and deletion of elements in `set` consume `O(logN)`. So the overall complexity grows to `O(N^2 * logN)`. Yikes.

```cpp
// OJ: https://leetcode.com/problems/beautiful-arrangement
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
class Solution {
private:
  int dfs(set<int> &s, int pos, int N) {
    if (pos == N) return 1;
    int cnt = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
      int n = *it;
      if (n % (pos + 1) && (pos + 1) % n) continue;
      s.erase(n);
      cnt += dfs(s, pos + 1, N);
      s.insert(n);
    }
    return cnt;
  }
public:
  int countArrangement(int N) {
    set<int> s;
    for (int i = 1; i <= N; ++i) s.insert(i);
    return dfs(s, 0, N);
  }
};
```

## Solution 3. Backtracking, `vector + swap`

Compared to solution 1, rather than marking the current number as `0`, we `swap` it to the `pos`. So all the used numbers go to `nums[0..pos]`. This saves computation.

```cpp
// OJ: https://leetcode.com/problems/beautiful-arrangement
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/79921/my-c-elegant-solution-with-back-tracking
class Solution {
private:
  int dfs(vector<int> &nums, int pos) {
    if (pos == nums.size()) return 1;
    int cnt = 0;
    for (int i = pos; i < nums.size(); ++i) {
      if (nums[i] % (pos + 1) && (pos + 1) % nums[i]) continue;
      swap(nums[i], nums[pos]);
      cnt += dfs(nums, pos + 1);
      swap(nums[i], nums[pos]);
    }
    return cnt;
  }
public:
  int countArrangement(int N) {
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) nums[i] = i + 1;
      return dfs(nums, 0);
  }
};
```