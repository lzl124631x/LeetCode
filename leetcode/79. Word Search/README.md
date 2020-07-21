# [79. Word Search (Medium)](https://leetcode.com/problems/word-search/)

<p>Given a 2D board and a word, find if the word exists in the grid.</p>

<p>The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.</p>

<p><strong>Example:</strong></p>

<pre>board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "<strong>ABCCED</strong>", return <strong>true</strong>.
Given word = "<strong>SEE</strong>", return <strong>true</strong>.
Given word = "<strong>ABCB</strong>", return <strong>false</strong>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>board</code>&nbsp;and <code>word</code> consists only of lowercase and uppercase English letters.</li>
	<li><code>1 &lt;= board.length &lt;= 200</code></li>
	<li><code>1 &lt;= board[i].length &lt;= 200</code></li>
	<li><code>1 &lt;= word.length &lt;= 10^3</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Word Search II (Hard)](https://leetcode.com/problems/word-search-ii/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/word-search/
// Author: github.com/lzl124631x
// Time: O(MN * 4^K)
// Space: O(K)
class Solution {
    int M, N, dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool dfs(vector<vector<char>> &A, string &word, int start, int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] != word[start]) return false;
        if (start + 1 == word.size()) return true;
        char c = A[x][y];
        A[x][y] = '\0';
        for (auto &dir : dirs) {
            if (dfs(A, word, start + 1, x + dir[0], y + dir[1])) return true;
        }
        A[x][y] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& A, string word) {
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dfs(A, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
```