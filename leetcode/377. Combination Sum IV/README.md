# [377. Combination Sum IV (Medium)](https://leetcode.com/problems/combination-sum-iv/)

<p>Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.</p>

<p><b>Example:</b></p>

<pre><i><b>nums</b></i> = [1, 2, 3]
<i><b>target</b></i> = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is <i><b>7</b></i>.
</pre>

<p>&nbsp;</p>

<p><b>Follow up:</b><br>
What if negative numbers are allowed in the given array?<br>
How does it change the problem?<br>
What limitation we need to add to the question to allow negative numbers?</p>

<p><b>Credits:</b><br>
Special thanks to <a href="https://leetcode.com/pbrother/">@pbrother</a> for adding this problem and creating all test cases.</p>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

## Solution 1. DP Top-down

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iv/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(T)
class Solution {
    unordered_map<int, int> m {{0, 1}};
    int dp(vector<int>& nums, int target) {
        if (m.count(target)) return m[target];
        int cnt = 0;
        for (int n : nums) {
            if (n > target) break;
            cnt += dp(nums, target - n);
        }
        return m[target] = cnt;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return dp(nums, target);
    }
};
```

## Solution 2. DP bottom-up

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iv/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(T)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int n : nums) {
                if (n > i) break;
                dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};
```