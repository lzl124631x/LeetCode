# [79. Word Search (Medium)](https://leetcode.com/problems/word-search/)

<p>Given an <code>m x n</code> grid of characters <code>board</code> and a string <code>word</code>, return <code>true</code> <em>if</em> <code>word</code> <em>exists in the grid</em>.</p>

<p>The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word2.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/word3.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n = board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 6</code></li>
	<li><code>1 &lt;= word.length &lt;= 15</code></li>
	<li><code>board</code> and <code>word</code> consists of only lowercase and uppercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you use search pruning to make your solution faster with a larger <code>board</code>?</p>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Snapchat](https://leetcode.com/company/snapchat), [Bloomberg](https://leetcode.com/company/bloomberg), [Twitter](https://leetcode.com/company/twitter), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Cisco](https://leetcode.com/company/cisco), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [VMware](https://leetcode.com/company/vmware), [Cruise Automation](https://leetcode.com/company/cruise-automation), [ByteDance](https://leetcode.com/company/bytedance), [Bolt](https://leetcode.com/company/bolt)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Word Search II (Hard)](https://leetcode.com/problems/word-search-ii/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/word-search/
// Author: github.com/lzl124631x
// Time: O(MN * 4^K)
// Space: O(K)
class Solution {
public:
    bool exist(vector<vector<char>>& A, string s) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        function<bool(int, int, int)> dfs = [&](int x, int y, int i) {
            if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] != s[i]) return false;
            if (i + 1 == s.size()) return true;
            char c = A[x][y];
            A[x][y] = 0;
            for (auto &[dx, dy] : dirs) {
                if (dfs(x + dx, y + dy, i + 1)) return true;
            }
            A[x][y] = c;
            return false;
        };
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};
```