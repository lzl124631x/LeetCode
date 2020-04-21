# [1349. Maximum Students Taking Exam (Hard)](https://leetcode.com/problems/maximum-students-taking-exam/)

<p>Given a <code>m&nbsp;* n</code>&nbsp;matrix <code>seats</code>&nbsp;&nbsp;that represent seats distributions&nbsp;in a classroom.&nbsp;If a seat&nbsp;is&nbsp;broken, it is denoted by <code>'#'</code> character otherwise it is denoted by a <code>'.'</code> character.</p>

<p>Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting&nbsp;directly in front or behind him. Return the <strong>maximum </strong>number of students that can take the exam together&nbsp;without any cheating being possible..</p>

<p>Students must be placed in seats in good condition.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img height="200" src="https://assets.leetcode.com/uploads/2020/01/29/image.png" width="339">
<pre><strong>Input:</strong> seats = [["#",".","#","#",".","#"],
&nbsp;               [".","#","#","#","#","."],
&nbsp;               ["#",".","#","#",".","#"]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Teacher can place 4 students in available seats so they don't cheat on the exam. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> seats = [[".","#"],
&nbsp;               ["#","#"],
&nbsp;               ["#","."],
&nbsp;               ["#","#"],
&nbsp;               [".","#"]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Place all students in available seats. 

</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> seats = [["#",".","<strong>.</strong>",".","#"],
&nbsp;               ["<strong>.</strong>","#","<strong>.</strong>","#","<strong>.</strong>"],
&nbsp;               ["<strong>.</strong>",".","#",".","<strong>.</strong>"],
&nbsp;               ["<strong>.</strong>","#","<strong>.</strong>","#","<strong>.</strong>"],
&nbsp;               ["#",".","<strong>.</strong>",".","#"]]
<strong>Output:</strong> 10
<strong>Explanation:</strong> Place students in available seats in column 1, 3 and 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>seats</code>&nbsp;contains only characters&nbsp;<code>'.'<font face="sans-serif, Arial, Verdana, Trebuchet MS">&nbsp;and</font></code><code>'#'.</code></li>
	<li><code>m ==&nbsp;seats.length</code></li>
	<li><code>n ==&nbsp;seats[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 8</code></li>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/maximum-students-taking-exam/
// Author: github.com/lzl124631x
// Time: O(M * (2^N)^2)
// Space: O(M * 2^N)
// Ref: https://leetcode.com/problems/maximum-students-taking-exam/discuss/503686/A-simple-tutorial-on-this-bitmasking-problem
class Solution {
public:
    int maxStudents(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> states;
        for (int i = 0; i < M; ++i) {
            int cur = 0;
            for (int j = 0; j < N; ++j) cur = cur * 2 + (A[i][j] == '.');
            states.push_back(cur);
        }
        vector<vector<int>> dp(M + 1, vector<int>(1 << N, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= M; ++i) {
            int state = states[i - 1];
            for (int j = 0; j < (1 << N); ++j) {
                if ((j & state) != j || (j & (j >> 1))) continue;
                int cnt = __builtin_popcount(j);
                for (int k = 0; k < (1 << N); ++k) {
                    if ((j & (k >> 1)) || (j & (k << 1)) || dp[i - 1][k] == -1) continue;
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + cnt);
                }
            }
        }
        return *max_element(begin(dp[M]), end(dp[M]));
    }
};
```