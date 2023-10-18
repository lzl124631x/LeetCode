# [494. Target Sum (Medium)](https://leetcode.com/problems/target-sum)

<p>You are given an integer array <code>nums</code> and an integer <code>target</code>.</p>

<p>You want to build an <strong>expression</strong> out of nums by adding one of the symbols <code>&#39;+&#39;</code> and <code>&#39;-&#39;</code> before each integer in nums and then concatenate all the integers.</p>

<ul>
	<li>For example, if <code>nums = [2, 1]</code>, you can add a <code>&#39;+&#39;</code> before <code>2</code> and a <code>&#39;-&#39;</code> before <code>1</code> and concatenate them to build the expression <code>&quot;+2-1&quot;</code>.</li>
</ul>

<p>Return the number of different <strong>expressions</strong> that you can build, which evaluates to <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1,1,1], target = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1], target = 1
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
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Nuro](https://leetcode.com/company/nuro), [Adobe](https://leetcode.com/company/adobe), [Uber](https://leetcode.com/company/uber), [Apple](https://leetcode.com/company/apple), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Backtracking](https://leetcode.com/tag/backtracking)

**Similar Questions**:
* [Expression Add Operators (Hard)](https://leetcode.com/problems/expression-add-operators)
* [Ways to Express an Integer as Sum of Powers (Medium)](https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers)

## Solution 1. Top-down DP (DFS + Memo)

Let `dp[i][t]` be the number of ways to form `t` using `A[0..i]`. The answer is `dp[N-1][target]`.

```
dp[i][t] =    dp[i-1][t+A[i]]  // assign '+' to A[i]
            + dp[i-1][t-A[i]]  // assign '-' to A[i]

dp[-1][t] = (t == 0 ? 1 : 0)
```

Time complexity: For each `A[i]`, there are two options, `+` and `-`, so there are `2^N` different combinations.

Space compleixty: `memo[N-1]` at most has `2^N` elements in it. `memo[N-2]` at most has `2^(N-1)` elements in it. ... So in total it takes `1 + 2 + 4 + ... + 2^N = O(2^N)` space.

```cpp
// OJ: https://leetcode.com/problems/target-sum/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    int findTargetSumWays(vector<int>& A, int target) {
        vector<unordered_map<int, int>> memo(A.size());
        function<int(int, int)> dfs = [&](int i, int target) -> int {
            if (i < 0) return target == 0;
            if (memo[i].count(target)) return memo[i][target];
            return memo[i][target] = dfs(i - 1, target + A[i]) + dfs(i - 1, target - A[i]);
        };
        return dfs(A.size() - 1, target);
    }
};
```

## Solution 2. Bottom-up DP

This solution is the Bottom-up version of Solution 1.

Since `dp[i]` only depends on `dp[i-1]`, we don't need to store `dp[j]` (`j < i - 1`).

```cpp
// OJ: https://leetcode.com/problems/target-sum
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    int findTargetSumWays(vector<int>& A, int target) {
        unordered_map<int, int> m{{0,1}}, next;
        for (int n : A) {
            next.clear();
            for (auto &[val, cnt] : m) {
                next[val + n] += cnt;
                next[val - n] += cnt;
            }
            swap(m, next);
        }
        return m[target];
    }
};
```

## Solution 3. Bottom-up DP (0-1 Knapsack)

Let's say `X` is a subset of `A` and `Y` is the complement subset of `X`. We assign `+` to all numbers in `X` and `-` to all numbers in `Y`.

We have `SUM(X) - SUM(Y) = target`. Since `SUM(Y) = SUM(A) - SUM(X)`, we have `2 * SUM(X) = target + SUM(A)`.

So, we want to find a subset whose sum `S` satisfies `2S = target + SUM(A)` (`target + SUM(A) >= 0` and `(target + SUM(A)) % 2 == 0`). This is a 0-1 Knapsack problem.

Let `dp[i+1][j]` be the number of ways to form sum `j` using `A[0..i]`. The answer is `dp[N][sum]`.

```
dp[i+1][j] =    dp[i][j]                                    // Skip A[i]
              + (j - A[i] >= 0 ? dp[i][j - A[i]] : 0)       // Pick A[i]

dp[0][0] = 1
```

```cpp
// OJ: https://leetcode.com/problems/target-sum/
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(NS)
class Solution {
    int subsetSum(vector<int> &A, int sum) {
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(sum + 1));
        dp[0][0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= sum; ++j) {
                dp[i + 1][j] = dp[i][j] + (j - A[i] >= 0 ? dp[i][j - A[i]] : 0);
            }
        }
        return dp[N][sum];
    }
public:
    int findTargetSumWays(vector<int>& A, int target) {
        target += accumulate(begin(A), end(A), 0);
        return target < 0 || target % 2 ? 0 : subsetSum(A, target / 2);
    }
};
```

Or with space-optimization.

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
        target += accumulate(begin(A), end(A), 0);
        return target < 0 || target % 2 ? 0 : subsetSum(A, target / 2);
    }
};
```

## NOTE

Related to [416. Partition Equal Subset Sum (Medium)](https://leetcode.com/problems/partition-equal-subset-sum/)