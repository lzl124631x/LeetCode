# [546. Remove Boxes (Hard)](https://leetcode.com/problems/remove-boxes/)

<p>Given several boxes with different colors represented by different positive numbers.<br>
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k &gt;= 1), remove them and get <code>k*k</code> points.<br>
Find the maximum points you can get.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> boxes = [1,3,2,2,2,3,4,3,1]
<strong>Output:</strong> 23
<strong>Explanation:</strong>
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----&gt; [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----&gt; [1, 3, 3, 3, 1] (1*1=1 points) 
----&gt; [1, 1] (3*3=9 points) 
----&gt; [] (2*2=4 points)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= boxes.length &lt;= 100</code></li>
	<li><code>1 &lt;= boxes[i]&nbsp;&lt;= 100</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Strange Printer (Hard)](https://leetcode.com/problems/strange-printer/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-boxes/
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(N^3)
// Ref: https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions
class Solution {
    vector<vector<vector<int>>> dp;
    int solve(vector<int> &A, int i, int j, int k) {
        if (i > j) return 0;
        if (dp[i][j][k] > 0) return dp[i][j][k];
        for (; i + 1 <= j && A[i + 1] == A[i]; ++i, ++k);
        int ans = (k + 1) * (k + 1) + solve(A, i + 1, j, 0);
        for (int m = i + 1; m <= j; ++m) {
            if (A[i] != A[m]) continue;
            ans = max(ans, solve(A, i + 1, m - 1, 0) + solve(A, m, j, k + 1));
        }
        return dp[i][j][k] = ans;
    }
public:
    int removeBoxes(vector<int>& A) {
        int N = A.size();
        dp.assign(N, vector<vector<int>>(N, vector<int>(N)));
        return solve(A, 0, N - 1, 0);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/remove-boxes/
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(N^3)
// Ref: https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions
class Solution {
public:
    int removeBoxes(vector<int>& A) {
        int N = A.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N)));
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k <= i; ++k) dp[i][i][k] = (k + 1) * (k + 1);
        }
        for (int len = 1; len < N; ++len) {
            for (int j = len; j < N; ++j) {
                int i = j - len;
                for (int k = 0; k <= i; ++k) {
                    int ans = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    for (int m = i + 1; m <= j; ++m) {
                        if (A[m] != A[i]) continue;
                        ans = max(ans, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                    }
                    dp[i][j][k] = ans;
                }
            }
        }
        return dp[0][N - 1][0];
    }
};
```