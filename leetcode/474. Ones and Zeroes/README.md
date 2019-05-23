# [474. Ones and Zeroes (Medium)](https://leetcode.com/problems/ones-and-zeroes/)

<p>In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.</p>

<p>For now, suppose you are a dominator of <b>m</b> <code>0s</code> and <b>n</b> <code>1s</code> respectively. On the other hand, there is an array with strings consisting of only <code>0s</code> and <code>1s</code>.</p>

<p>Now your task is to find the maximum number of strings that you can form with given <b>m</b> <code>0s</code> and <b>n</b> <code>1s</code>. Each <code>0</code> and <code>1</code> can be used at most <b>once</b>.</p>

<p><b>Note:</b></p>

<ol>
	<li>The given numbers of <code>0s</code> and <code>1s</code> will both not exceed <code>100</code></li>
	<li>The size of given string array won't exceed <code>600</code>.</li>
</ol>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
<b>Output:</b> 4

<b>Explanation:</b> This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> Array = {"10", "0", "1"}, m = 1, n = 1
<b>Output:</b> 2

<b>Explanation:</b> You could form "10", but then you'd have nothing left. Better form "0" and "1".
</pre>

<p>&nbsp;</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/ones-and-zeroes/
// Author: github.com/lzl124631x
// Time: O(MNS)
// Space: O(MNS)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int M, int N) {
        int S = strs.size();
        vector<vector<vector<int>>> dp(M + 1, vector<vector<int>>(N + 1, vector<int>(S + 1, 0)));
        vector<pair<int, int>> cnts(S);
        for (int i = 0; i < S; ++i) {
            auto str = strs[i];
            cnts[i].first = count(str.begin(), str.end(), '0');
            cnts[i].second = count(str.begin(), str.end(), '1');
        }
        for (int k = 1; k <= S; ++k) {
            int zeros = cnts[k - 1].first, ones = cnts[k - 1].second;
            for (int i = 0; i <= M; ++i) {
                for (int j = 0; j <= N; ++j) {
                    dp[i][j][k] = dp[i][j][k - 1];
                    if (zeros <= i && ones <= j) dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - zeros][j - ones][k - 1]);
                }
            }
        }
        return dp[M][N][S];
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/ones-and-zeroes/
// Author: github.com/lzl124631x
// Time: O(MNS)
// Space: O(MN)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1], len = strs.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; ++i) {
            int cm = 0, cn = 0;
            for (char c : strs[i]) {
                if (c == '0') ++cm;
                else ++cn;
            }
            for (int im = m; im >= cm; --im) {
                for (int in = n; in >= cn; --in) {
                    dp[im][in] = max(dp[im][in], dp[im - cm][in - cn] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
```