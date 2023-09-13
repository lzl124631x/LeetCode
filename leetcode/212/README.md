# [212. Word Search II (Hard)](https://leetcode.com/problems/word-search-ii/)

<p>Given an <code>m x n</code> <code>board</code>&nbsp;of characters and a list of strings <code>words</code>, return <em>all words on the board</em>.</p>

<p>Each word must be constructed from letters of sequentially adjacent cells, where <strong>adjacent cells</strong> are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/07/search1.jpg" style="width: 322px; height: 322px;">
<pre><strong>Input:</strong> board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
<strong>Output:</strong> ["eat","oath"]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/07/search2.jpg" style="width: 162px; height: 162px;">
<pre><strong>Input:</strong> board = [["a","b"],["c","d"]], words = ["abcb"]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 12</code></li>
	<li><code>board[i][j]</code> is a lowercase English letter.</li>
	<li><code>1 &lt;= words.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
	<li>All the strings of <code>words</code> are unique.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Cisco](https://leetcode.com/company/cisco), [Snapchat](https://leetcode.com/company/snapchat), [Twitter](https://leetcode.com/company/twitter), [Apple](https://leetcode.com/company/apple), [Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Trie](https://leetcode.com/tag/trie/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Word Search (Medium)](https://leetcode.com/problems/word-search/)
* [Unique Paths III (Hard)](https://leetcode.com/problems/unique-paths-iii/)

## Solution 1. Trie + Backtracking

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

## Solution 2. Trie + Backtracking

We mark visited end nodes using `end = false` to prevent re-adding the same word. But we still might waste time visting a subtree of Trie which doesn't have any valid words. To prevent such case, we can keep a counter `cnt` in the TrieNode. Whenever an end node is visited, we decrement the counter on it and on all its ancester nodes. In this way, when the counter is `0`, we don't need to traverse the Trie subtree.

```cpp
// OJ: https://leetcode.com/problems/word-search-ii/
// Author: github.com/lzl124631x
// Time: O(WL + MN * 4^L) where M, N is the size of board, W is the size of words and L is the average length of word
// Space: O(WL)
struct TrieNode {
    TrieNode *next[26] = {};
    int cnt = 0;
    bool end = false;
};
class Solution {
    TrieNode root;
    void addWord(TrieNode *node, string &s) {
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->cnt++;
        }
        node->end = true;
    }
public:
    vector<string> findWords(vector<vector<char>>& A, vector<string>& words) {
        for (auto &s : words) addWord(&root, s);
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<string> ans;
        string tmp;
        function<int(int, int, TrieNode*)> dfs = [&](int x, int y, TrieNode *node) {
            int c = A[x][y] - 'a', cnt = 0;
            if (!node->next[c] || !node->next[c]->cnt) return 0;
            node = node->next[c];
            tmp.push_back(A[x][y]);
            if (node->end) {
                ans.push_back(tmp);
                ++cnt;
                node->end = false;
            }
            A[x][y] = 0;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == 0) continue;
                cnt += dfs(a, b, node);
            }
            A[x][y] = 'a' + c;
            tmp.pop_back();
            node->cnt -= cnt;
            return cnt;
        };
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dfs(i, j, &root);
            }
        }
        return ans;
    }
};
```