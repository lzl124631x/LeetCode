# [935. Knight Dialer (Medium)](https://leetcode.com/problems/knight-dialer)

<p>The chess knight has a <strong>unique movement</strong>,&nbsp;it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an <strong>L</strong>). The possible movements of chess knight are shown in this diagaram:</p>

<p>A chess knight can move as indicated in the chess diagram below:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/18/chess.jpg" style="width: 402px; height: 402px;" />
<p>We have a chess knight and a phone pad as shown below, the knight <strong>can only stand on a numeric cell</strong>&nbsp;(i.e. blue cell).</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/18/phone.jpg" style="width: 242px; height: 322px;" />
<p>Given an integer <code>n</code>, return how many distinct phone numbers of length <code>n</code> we can dial.</p>

<p>You are allowed to place the knight <strong>on any numeric cell</strong> initially and then you should perform <code>n - 1</code> jumps to dial a number of length <code>n</code>. All jumps should be <strong>valid</strong> knight jumps.</p>

<p>As the answer may be very large, <strong>return the answer modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 10
<strong>Explanation:</strong> We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 20
<strong>Explanation:</strong> All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 3131
<strong>Output:</strong> 136006598
<strong>Explanation:</strong> Please take care of the mod.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Twilio](https://leetcode.com/company/twilio)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/knight-dialer/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    vector<vector<int>> next {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
public:
    int knightDialer(int N) {
        vector<vector<int>> dp(2, vector<int>(10, 1));
        int mod = 1e9 + 7, ans = 0;
        for (int i = 2; i <= N; ++i) {
            for (int j = 0; j <= 9; ++j) {
                dp[i % 2][j] = 0;
                for (int n : next[j]) {
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][n]) % mod;
                }
            }
        }
        for (int i = 0; i <= 9; ++i) ans = (ans + dp[N % 2][i]) % mod;
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/knight-dialer
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    int knightDialer(int n) {
        vector<int> m[10]{{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{4,2}};
        long dp[10] = {[0 ... 9] = 1}, mod = 1e9 + 7, ans = 0;
        for (int i = 1; i < n; ++i) {
            long next[10] = {};
            for (int j = 0; j <= 9; ++j) {
                for (int n : m[j]) next[n] = (next[n] + dp[j]) % mod;
            }
            swap(dp, next);
        }
        for (int i = 0; i <= 9; ++i) ans = (ans + dp[i]) % mod;
        return ans;
    }
};
```