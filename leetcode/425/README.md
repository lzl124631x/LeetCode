# [425. Word Squares (Hard)](https://leetcode.com/problems/word-squares/)

<p>Given an array of <strong>unique</strong> strings <code>words</code>, return <em>all the </em><strong><a href="https://en.wikipedia.org/wiki/Word_square" target="_blank">word squares</a></strong><em> you can build from </em><code>words</code>. The same word from <code>words</code> can be used <strong>multiple times</strong>. You can return the answer in <strong>any order</strong>.</p>

<p>A sequence of strings forms a valid <strong>word square</strong> if the <code>k<sup>th</sup></code> row and column read the same string, where <code>0 &lt;= k &lt; max(numRows, numColumns)</code>.</p>

<ul>
	<li>For example, the word sequence <code>["ball","area","lead","lady"]</code> forms a word square because each word reads the same both horizontally and vertically.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["area","lead","wall","lady","ball"]
<strong>Output:</strong> [["ball","area","lead","lady"],["wall","area","lead","lady"]]
<strong>Explanation:</strong>
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["abat","baba","atan","atal"]
<strong>Output:</strong> [["baba","abat","baba","atal"],["baba","abat","baba","atan"]]
<strong>Explanation:</strong>
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 5</code></li>
	<li>All <code>words[i]</code> have the same length.</li>
	<li><code>words[i]</code> consists of only lowercase English letters.</li>
	<li>All <code>words[i]</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Oracle](https://leetcode.com/company/oracle), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Valid Word Square (Easy)](https://leetcode.com/problems/valid-word-square/)

## Solution 1. Trie + DFS

```cpp
// OJ: https://leetcode.com/problems/word-squares/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
struct TrieNode {
    TrieNode *next[26] = {};
    vector<int> indices;
};
class Solution {
    void addWord(TrieNode *node, string &s, int i) {
        node->indices.push_back(i);
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->indices.push_back(i);
        }
    }
    vector<int> getWords(TrieNode *node, string &s) {
        for (char c : s) {
            node = node->next[c - 'a'];
            if (!node) return {};
        }
        return node->indices;
    }
public:
    vector<vector<string>> wordSquares(vector<string>& A) {
        int N = A[0].size(), M = A.size();
        vector<vector<string>> ans;
        vector<string> tmp(N, string(N, ' '));
        TrieNode root;
        for (int i = 0; i < M; ++i) addWord(&root, A[i], i);
        function<void(int)> dfs = [&](int i) {
            if (i == N) {
                ans.push_back(tmp);
                return;
            }
            auto prefix = tmp[i].substr(0, i);
            for (auto &index : getWords(&root, prefix)) {
                for (int k = i; k < N; ++k) {
                    tmp[i][k] = tmp[k][i] = A[index][k];
                }
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};
```