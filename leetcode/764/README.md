# [764. Largest Plus Sign (Medium)](https://leetcode.com/problems/largest-plus-sign/)

<p>
In a 2D <code>grid</code> from (0, 0) to (N-1, N-1), every cell contains a <code>1</code>, except those cells in the given list <code>mines</code> which are <code>0</code>.  What is the largest axis-aligned plus sign of <code>1</code>s contained in the grid?  Return the order of the plus sign.  If there is none, return 0.
</p><p>
An "<i>axis-aligned plus sign of <code>1</code>s</i> of order <b>k</b>" has some center <code>grid[x][y] = 1</code> along with 4 arms of length <code>k-1</code> going up, down, left, and right, and made of <code>1</code>s.  This is demonstrated in the diagrams below.  Note that there could be <code>0</code>s or <code>1</code>s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.
</p><p>

</p><p><b>Examples of Axis-Aligned Plus Signs of Order k:</b><br></p><pre>Order 1:
000
0<b>1</b>0
000

Order 2:
00000
00<b>1</b>00
0<b>111</b>0
00<b>1</b>00
00000

Order 3:
0000000
000<b>1</b>000
000<b>1</b>000
0<b>11111</b>0
000<b>1</b>000
000<b>1</b>000
0000000
</pre><p></p>

<p><b>Example 1:</b><br></p><pre><b>Input:</b> N = 5, mines = [[4, 2]]
<b>Output:</b> 2
<b>Explanation:</b>
11111
11111
1<b>1</b>111
<b>111</b>11
1<b>1</b>011
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.
</pre><p></p>

<p><b>Example 2:</b><br></p><pre><b>Input:</b> N = 2, mines = []
<b>Output:</b> 1
<b>Explanation:</b>
There is no plus sign of order 2, but there is of order 1.
</pre><p></p>

<p><b>Example 3:</b><br></p><pre><b>Input:</b> N = 1, mines = [[0, 0]]
<b>Output:</b> 0
<b>Explanation:</b>
There is no plus sign, so return 0.
</pre><p></p>

<p><b>Note:</b><br></p><ol>
<li><code>N</code> will be an integer in the range <code>[1, 500]</code>.</li>
<li><code>mines</code> will have length at most <code>5000</code>.</li>
<li><code>mines[i]</code> will be length 2 and consist of integers in the range <code>[0, N-1]</code>.</li>
<li><i>(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)</i></li>
</ol><p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Maximal Square (Medium)](https://leetcode.com/problems/maximal-square/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-plus-sign/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& A) {
        vector<vector<int>> M(N, vector<int>(N, 1)), H(N, vector<int>(N)), V(N, vector<int>(N));
        for (auto &v : A) {
            M[v[0]][v[1]] = 0;
        }
        for (int i = 0; i < N; ++i) {
            stack<int> s;
            s.push(N);
            for (int j = N - 1; j >= 0; --j) {
                if (M[i][j] == 0) s.push(j);
            }
            int prev = -1;
            for (int j = 0; j < N; ++j) {
                if (M[i][j] == 0) {
                    s.pop();
                    prev = j;
                } else H[i][j] = min(j - prev, s.top() - j);
            }
        }
        for (int j = 0; j < N; ++j) {
            stack<int> s;
            s.push(N);
            for (int i = N - 1; i >= 0; --i) {
                if (M[i][j] == 0) s.push(i);
            }
            int prev = -1;
            for (int i = 0; i < N; ++i) {
                if (M[i][j] == 0) {
                    s.pop();
                    prev = i;
                } else V[i][j] = min(i - prev, s.top() - i);
            }
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ans = max(ans, min(H[i][j], V[i][j]));
            }
        }
        return ans;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/largest-plus-sign/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& A) {
        int ans = 0;
        unordered_set<int> s;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (auto &v : A) {
            s.insert(v[0] * N + v[1]);
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0, cnt = 0; j < N; ++j) {
                cnt = s.count(i * N + j) ? 0 : (1 + cnt);
                dp[i][j] = cnt;
            }
            for (int j = N - 1, cnt = 0; j >= 0; --j) {
                cnt = s.count(i * N + j) ? 0 : (1 + cnt);
                dp[i][j] = min(dp[i][j], cnt);
            }
        }
        for (int j = 0; j < N; ++j) {
            for (int i = 0, cnt = 0; i < N; ++i) {
                cnt = s.count(i * N + j) ? 0 : (1 + cnt);
                dp[i][j] = min(dp[i][j], cnt);
            }
            for (int i = N - 1, cnt = 0; i >= 0; --i) {
                cnt = s.count(i * N + j) ? 0 : (1 + cnt);
                dp[i][j] = min(dp[i][j], cnt);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
```