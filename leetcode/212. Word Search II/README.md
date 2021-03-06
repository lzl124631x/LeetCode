# [212. Word Search II (Hard)](https://leetcode.com/problems/word-search-ii/)

<p>Given a 2D board and a list of words from the dictionary, find all words in the board.</p>

<p>Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.</p>

<p>&nbsp;</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 
<b>board </b>= [
  ['<span style="color:#d70">o</span>','<span style="color:#d70">a</span>','a','n'],
  ['e','<span style="color:#d30">t</span>','<span style="color:#d00">a</span>','<span style="color:#d00">e</span>'],
  ['i','<span style="color:#d70">h</span>','k','r'],
  ['i','f','l','v']
]
<b>words</b> = <code>["oath","pea","eat","rain"]</code>

<strong>Output:&nbsp;</strong><code>["eat","oath"]</code>
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>All inputs are consist of lowercase letters <code>a-z</code>.</li>
	<li>The values of&nbsp;<code>words</code> are distinct.</li>
</ol>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Word Search (Medium)](https://leetcode.com/problems/word-search/)
* [Unique Paths III (Hard)](https://leetcode.com/problems/unique-paths-iii/)

## Solution 1. Trie

### Complexity Analysis

Building the Trie takes `O(WL)` time and `O(WL)` space, where `W` is the size of array `words` and `L` is the maximum length of a word.

The DFS part will take each point on the board as a starting point. There are `O(MN)` starting points. For each starting point, we DFS in 4 directions with the maximum depth being `L`. So the DFS part takes `O(MN * 4^L)` time.

```cpp
// OJ: https://leetcode.com/problems/word-search-ii/
// Author: github.com/lzl124631x
// Time: O(WL + MN * 4^L) where M, N is the size of board, W is the size of words and L is the average length of word
// Space: O(WL)
struct TrieNode {
    TrieNode *next[26] = {0};
    bool word = false;
};
void addWord(TrieNode *node, string &w) {
    for (char c : w) {
        if (node->next[c - 'a'] == NULL) node->next[c - 'a'] = new TrieNode();
        node = node->next[c - 'a'];
    }
    node->word = true;
}
class Solution {
    int M, N, dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    vector<string> ans;
    string path;
    void dfs(vector<vector<char>> &A, TrieNode *node, int x, int y) {
        char c = A[x][y];
        node = node->next[c - 'a'];
        if (!node) return;
        path.push_back(c);
        A[x][y] = 0;
        if (node->word) {
            ans.push_back(path);
            node->word = false; // prevent adding the same word again.
        }
        for (auto &dir : dirs) {
            int a = x + dir[0], b = y + dir[1];
            if (a >= M || a < 0 || b >= N || b < 0 || A[a][b] == 0) continue;
            dfs(A, node, a, b);
        }
        A[x][y] = c;
        path.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty()) return {};
        M = board.size(), N = board[0].size();
        TrieNode root;
        for (auto &w : words) addWord(&root, w);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) dfs(board, &root, i, j);
        }
        return ans;
    }
};
```