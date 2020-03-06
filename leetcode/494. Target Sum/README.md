# [494. Target Sum (Medium)](https://leetcode.com/problems/target-sum/)

<p>
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols <code>+</code> and <code>-</code>. For each integer, you should choose one from <code>+</code> and <code>-</code> as its new symbol.
</p> 

<p>Find out how many ways to assign symbols to make sum of integers equal to target S.  
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> nums is [1, 1, 1, 1, 1], S is 3. 
<b>Output:</b> 5
<b>Explanation:</b> 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The length of the given array is positive and will not exceed 20. </li>
<li>The sum of elements in the given array will not exceed 1000.</li>
<li>Your output answer is guaranteed to be fitted in a 32-bit integer.</li>
</ol>
<p></p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Expression Add Operators (Hard)](https://leetcode.com/problems/expression-add-operators/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/target-sum
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    unordered_map<int, int> ans;
    ans[0] = 1;
    for (int n : nums) {
      unordered_map<int, int> newAns;
      for (auto p : ans) {
        int sum = p.first, cnt = p.second;
        newAns[sum + n] += cnt;
        newAns[sum - n] += cnt;
      }
      ans = newAns;
    }
    return ans[S];
  }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/target-sum/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
typedef long long LL;
class Solution {
    int dfs(vector<int> &nums, int start, LL target) {
        if (start == nums.size()) return target == 0;
        return dfs(nums, start + 1, target - nums[start])
            + dfs(nums, start + 1, target + nums[start]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, 0, S);
    }
};
```

## Solution 3. DFS + Memo

```cpp
// OJ: https://leetcode.com/problems/target-sum/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
typedef long long LL;
class Solution {
    vector<unordered_map<int, int>> memo;
    int dfs(vector<int> &nums, int start, LL target) {
        if (start == nums.size()) return target == 0;
        if (memo[start].count(target)) return memo[start][target];
        return memo[start][target] = dfs(nums, start + 1, target - nums[start])
            + dfs(nums, start + 1, target + nums[start]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        memo = vector<unordered_map<int, int>>(nums.size());
        return dfs(nums, 0, S);
    }
};
```

## Solution 4. DP

```cpp
// OJ: https://leetcode.com/problems/target-sum
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(S)
// Ref: https://discuss.leetcode.com/topic/76243/java-15-ms-c-3-ms-o-ns-iterative-dp-solution-using-subset-sum-with-explanation
class Solution {
private:
  int subsetSum(vector<int> &nums, int S) {
    vector<int> dp(S + 1, 0);
    dp[0] = 1;
    for (int n : nums)
      for (int i = S; i >= n; --i) dp[i] += dp[i - n];
    return dp[S];
  }
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum < S || (sum + S) % 2 ? 0 : subsetSum(nums, (sum + S) / 2);
  }
};
```