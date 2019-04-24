# [518. Coin Change 2 (Medium)](https://leetcode.com/problems/coin-change-2/)

<p>You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.</p>

<ul>
</ul>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> amount = 5, coins = [1, 2, 5]
<b>Output:</b> 4
<b>Explanation:</b> there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> amount = 3, coins = [2]
<b>Output:</b> 0
<b>Explanation:</b> the amount of 3 cannot be made up just with coins of 2.
</pre>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> amount = 10, coins = [10] 
<b>Output:</b> 1
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<p>You can assume that</p>

<ul>
	<li>0 &lt;= amount &lt;= 5000</li>
	<li>1 &lt;= coin &lt;= 5000</li>
	<li>the number of coins is less than 500</li>
	<li>the answer is guaranteed to fit into signed 32-bit integer</li>
</ul>


## Solution 1. DFS + Memo

```cpp
// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(A * C^2)
// Space: O(AC)
class Solution {
private:
    unordered_map<int, int> memo;
    int change(int amount, vector<int>& coins, int start) {
        if (!amount) return 1;
        if (start >= coins.size()) return 0;
        int key = amount * 1000 + start;
        if (memo.find(key) != memo.end()) return memo[key];
        int ans = 0;
        for (int i = start; i < coins.size(); ++i) {
            if (amount >= coins[i]) ans += change(amount - coins[i], coins, i);
        }
        return memo[key] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        return change(amount, coins, 0);
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(A^2 * C)
// Space: O(AC)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1));
        for (int i = 0; i <= coins.size(); ++i) dp[0][i] = 1;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 1; j <= coins.size(); ++j) {
                for (int k = 0; i - coins[j - 1] * k >= 0; ++k) {
                    dp[i][j] += dp[i - coins[j - 1] * k][j - 1];
                }
            }
        }
        return dp[amount][coins.size()];
    }
};
```

## Solution 3. DP

```cpp
// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(AC)
// Space: O(AC)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1));
        for (int i = 0; i <= coins.size(); ++i) dp[0][i] = 1;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 1; j <= coins.size(); ++j) {
                dp[i][j] = dp[i][j - 1] + (i - coins[j - 1] >= 0 ? dp[i - coins[j - 1]][j] : 0);
            }
        }
        return dp[amount][coins.size()];
    }
};
```

## Solution 4. DP

```cpp
// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(AC)
// Space: O(A)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int j = 1; j <= coins.size(); ++j) {
            for (int i = 1; i <= amount; ++i) {
                if (i - coins[j - 1] >= 0) dp[i] += dp[i - coins[j - 1]];
            }
        }
        return dp[amount];
    }
};
```