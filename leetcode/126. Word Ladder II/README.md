# [126. Word Ladder II (Hard)](https://leetcode.com/problems/word-ladder-ii/)

<p>A <strong>transformation sequence</strong> from word <code>beginWord</code> to word <code>endWord</code> using a dictionary <code>wordList</code> is a sequence of words <code>beginWord -&gt; s<sub>1</sub> -&gt; s<sub>2</sub> -&gt; ... -&gt; s<sub>k</sub></code> such that:</p>

<ul>
	<li>Every adjacent pair of words differs by a single letter.</li>
	<li>Every <code>s<sub>i</sub></code> for <code>1 &lt;= i &lt;= k</code> is in <code>wordList</code>. Note that <code>beginWord</code> does not need to be in <code>wordList</code>.</li>
	<li><code>s<sub>k</sub> == endWord</code></li>
</ul>

<p>Given two words, <code>beginWord</code> and <code>endWord</code>, and a dictionary <code>wordList</code>, return <em>all the <strong>shortest transformation sequences</strong> from</em> <code>beginWord</code> <em>to</em> <code>endWord</code><em>, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words </em><code>[beginWord, s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub>]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
<strong>Output:</strong> [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
<strong>Explanation:</strong>&nbsp;There are 2 shortest transformation sequences:
"hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; "cog"
"hit" -&gt; "hot" -&gt; "lot" -&gt; "log" -&gt; "cog"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
<strong>Output:</strong> []
<strong>Explanation:</strong> The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= beginWord.length &lt;= 7</code></li>
	<li><code>endWord.length == beginWord.length</code></li>
	<li><code>1 &lt;= wordList.length &lt;= 5000</code></li>
	<li><code>wordList[i].length == beginWord.length</code></li>
	<li><code>beginWord</code>, <code>endWord</code>, and <code>wordList[i]</code> consist of lowercase English letters.</li>
	<li><code>beginWord != endWord</code></li>
	<li>All the words in <code>wordList</code> are <strong>unique</strong>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Word Ladder (Hard)](https://leetcode.com/problems/word-ladder/)

## Solution 1.

### Complexity Analysis

For the building graph part, we need to traverse each word and try altering each letters of the words from 'a' to 'z'. This will take `O(26NW)` time, where `N` is the length of `wordList` and `W` is the length of a single word. It takes `O(NW)` space to store the graph.

For the BFS part, we visit each word at most once and store the level number of each word in `level` map. For a word `u` popped from the queue, assuming its level is `lv`, we visit all its neighbors. For a neighbor `v`, if we've visited `v` and `v` level is `lv + 1`, then we add `v` as a next node of `u` by adding `v` to `next[u]`. We stop the BFS when we pop the `endWord` from the queue.

If we haven't visited the `endWord` during BFS, it means that the `endWord` is unreacheable, we return empty array.

Otherwise, we reconstruct the paths using DFS plus the `next` map.

```cpp
// OJ: https://leetcode.com/problems/word-ladder-ii/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
    unordered_map<string, vector<string>> next;
    vector<vector<string>> ans;
    vector<string> path;
    string endWord;
    void dfs(string u) {
        if (u == endWord) {
            ans.push_back(path);
            return;
        }
        for (auto &v : next[u]) {
            path.push_back(v);
            dfs(v);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // build graph
        unordered_map<string, vector<string>> G;
        unordered_set<string> s(begin(wordList), end(wordList));
        if (s.count(endWord) == 0) return {};
        s.insert(beginWord);
        for (auto &w : s) {
            for (int i = 0; i < w.size(); ++i) {
                auto tmp = w;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (w[i] == c) continue;
                    tmp[i] = c;
                    if (s.count(tmp)) G[w].push_back(tmp);
                }
            }
        }
        // bfs to find the shortest paths
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> level;
        level[beginWord] = 0;
        int lv = 0;
        bool done = false;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto u = q.front();
                q.pop();
                if (u == endWord) {
                    done = true;
                    break;
                }
                for (auto &v : G[u]) {
                    if (level.count(v)) {
                        if (level[v] == lv + 1) {
                            next[u].push_back(v);
                        }
                    } else {
                        next[u].push_back(v);
                        level[v] = lv + 1;
                        q.push(v);
                    }
                }
            }
            if (done) break;
            ++lv;
        }
        if (!done) return {};
        // reconstruct path
        this->endWord = endWord;
        path.push_back(beginWord);
        dfs(beginWord);
        return ans;
    }
};
```