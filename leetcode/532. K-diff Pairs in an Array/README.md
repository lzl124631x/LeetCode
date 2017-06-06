# [532. K-diff Pairs in an Array (Easy)](https://leetcode.com/problems/k-diff-pairs-in-an-array)

Given an array of integers and an integer **k**, you need to find the number of **unique** k-diff pairs in the array. Here a **k-diff** pair is defined as an integer pair (i, j), where **i** and **j** are both numbers in the array and their [absolute difference](https://en.wikipedia.org/wiki/Absolute_difference) is **k**.

**Example 1:**  

```
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).  
Although we have two 1s in the input, we should only return the number of unique pairs.
```

**Example 2:**  

```
Input: [1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
```

**Example 3:**  

```Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
```

**Note:**  

1.  The pairs (i, j) and (j, i) count as the same pair.
2.  The length of the array won't exceed 10,000.
3.  All the integers in the given input belong to the range: [-1e7, 1e7].

## Solution 1.

Use an `unordered_map<int, int> m` to count the occurrence of each number.

Let `int cnt` be the number of pairs, initially `0`.


For each number `n`,
* If `k == 0` and `m[n] > 1`, increment `cnt`.
* If `k != 0` and `m[n + k] > 0`, increment `cnt`.

```cpp
// OJ: https://leetcode.com/problems/k-diff-pairs-in-an-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> m;
    for (int n : nums) m[n]++;
    int cnt = 0;
    for (auto p : m) {
      if ((!k && p.second > 1)
        || (k && m.count(p.first + k))) ++cnt;
    }
    return cnt;
  }
};
```
