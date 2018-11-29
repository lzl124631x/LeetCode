# [645. Set Mismatch (Easy)](https://leetcode.com/problems/set-mismatch)

The set `S` originally contains numbers from 1 to `n`. But unfortunately, due to the data error, one of the numbers in the set got duplicated to **another** number in the set, which results in repetition of one number and loss of another number.

Given an array `nums` representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

**Example 1:**  

**Input:** nums = \[1,2,2,4\]  
**Output:** \[2,3\]

**Note:**  

1.  The given array size will in the range \[2, 10000\].
2.  The given array's numbers won't have any order.

## Solution 1. unordered_map

```cpp
// OJ: https://leetcode.com/problems/set-mismatch
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n : nums) m[n]++;
        int missing, dup;
        for (int i = 1; i <= nums.size(); ++i) {
            if (!m[i]) missing = i;
            if (m[i] == 2) dup = i;
        }
        return { dup, missing };
    }
};
```

## Solution 2. Sort

```cpp
// OJ: https://leetcode.com/problems/set-mismatch/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dup, missing = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) dup = nums[i];
            else if (nums[i] > nums[i - 1] + 1) missing = nums[i - 1] + 1;
        }
        return { dup, nums.back() != nums.size() ? nums.size() : missing };
    }
};
```

## Solution 3. Extra Counts Array

Same idea as Solution 1, but Solution 1 actually requires `2N` space, while this approach requires `N` space.

```cpp
// OJ: https://leetcode.com/problems/set-mismatch/solution/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> cnts(nums.size(), 0);
        int dup, missing;
        for (int n : nums) cnts[n - 1]++;
        for (int i = 0; i < cnts.size(); ++i) {
            if (cnts[i] == 0) missing = i + 1;
            else if (cnts[i] == 2) dup = i + 1;
        }
        return { dup, missing };
    }
};
```

## Solution 4. Using Constant Space

If we can encode the Counts Array into `nums`, we can save space.

When we visit a number `n` in `nums`, we invert `nums[abs(n) - 1]`. If the number `n` just appears once, the corresponding `nums[abs(n) - 1]` will be negative. When we see a negative `nums[abs(n) - 1]`, it means `n` has been visited -- it's the duplicate.

If `nums[i]` is left positive, then `i + 1` is the missing number.

```cpp
// OJ: https://leetcode.com/problems/set-mismatch/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup, missing;
        for (int n : nums) {
            if (nums[abs(n) - 1] < 0) dup = abs(n);
            else nums[abs(n) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) missing = i + 1;
        }
        return { dup, missing };
    }
};
```