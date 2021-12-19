# [494. Target Sum (Medium)](https://leetcode.com/problems/target-sum/)

<p>You are given an integer array <code>nums</code> and an integer <code>target</code>.</p>

<p>You want to build an <strong>expression</strong> out of nums by adding one of the symbols <code>'+'</code> and <code>'-'</code> before each integer in nums and then concatenate all the integers.</p>

<ul>
	<li>For example, if <code>nums = [2, 1]</code>, you can add a <code>'+'</code> before <code>2</code> and a <code>'-'</code> before <code>1</code> and concatenate them to build the expression <code>"+2-1"</code>.</li>
</ul>

<p>Return the number of different <strong>expressions</strong> that you can build, which evaluates to <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,1,1], target = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1], target = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 20</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= sum(nums[i]) &lt;= 1000</code></li>
	<li><code>-1000 &lt;= target &lt;= 1000</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [ByteDance](https://leetcode.com/company/bytedance), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Expression Add Operators (Hard)](https://leetcode.com/problems/expression-add-operators/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/target-sum
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    int findTargetSumWays(vector<int>& A, int target) {
        unordered_map<int, int> m, next;
        m[0] = 1;
        for (int n : A) {
            next.clear();
            for (auto [val, cnt] : m) {
                next[val + n] += cnt;
                next[val - n] += cnt;
            }
            swap(m, next);
        }
        return m[target];
    }
};
```

## Solution 3. Top-down DP (DFS + Memo)

```cpp
// OJ: https://leetcode.com/problems/target-sum/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    int findTargetSumWays(vector<int>& A, int target) {
        vector<unordered_map<int, int>> memo(A.size());
        function<int(int, int)> dfs = [&](int start, int target) -> int {
            if (start == A.size()) return target == 0;
            if (memo[start].count(target)) return memo[start][target];
            return memo[start][target] = dfs(start + 1, target - A[start]) + dfs(start + 1, target + A[start]);
        };
        return dfs(0, target);
    }
};
```

## Solution 3. Bottom-up DP (0-1 Knapsack)

```cpp
// OJ: https://leetcode.com/problems/target-sum
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(S)
class Solution {
    int subsetSum(vector<int> &A, int sum) {
        vector<int> dp(sum + 1);
        dp[0] = 1;
        for (int n : A) {
            for (int i = sum; i >= n; --i) {
                dp[i] += dp[i - n];
            }
        }
        return dp[sum];
    }
public:
    int findTargetSumWays(vector<int>& A, int target) {
        target = (accumulate(begin(A), end(A), 0) + target);
        return target < 0 || target % 2 ? 0 : subsetSum(A, target / 2);
    }
};
```

## NOTE

Related to [416. Partition Equal Subset Sum (Medium)](https://leetcode.com/problems/partition-equal-subset-sum/)