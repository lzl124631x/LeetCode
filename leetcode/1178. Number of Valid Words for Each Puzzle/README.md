# [1178. Number of Valid Words for Each Puzzle (Hard)](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/)

With respect to a given <code>puzzle</code> string, a <code>word</code> is <em>valid</em> if both the following conditions are satisfied:
<ul>
	<li><code>word</code> contains the first letter of <code>puzzle</code>.</li>
	<li>For each letter in <code>word</code>, that letter is in <code>puzzle</code>.
	<ul>
		<li>For example, if the puzzle is <code>"abcdefg"</code>, then valid words are <code>"faced"</code>, <code>"cabbage"</code>, and <code>"baggage"</code>, while</li>
		<li>invalid words are <code>"beefed"</code> (does not include <code>'a'</code>) and <code>"based"</code> (includes <code>'s'</code> which is not in the puzzle).</li>
	</ul>
	</li>
</ul>
Return <em>an array </em><code>answer</code><em>, where </em><code>answer[i]</code><em> is the number of words in the given word list </em><code>words</code><em> that is valid with respect to the puzzle </em><code>puzzles[i]</code>.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["aaaa","asas","able","ability","actt","actor","access"], puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
<strong>Output:</strong> [1,1,3,2,4,0]
<strong>Explanation:</strong> 
1 valid word for "aboveyz" : "aaaa" 
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There are no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["apple","pleas","please"], puzzles = ["aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"]
<strong>Output:</strong> [0,1,3,2,0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>4 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>1 &lt;= puzzles.length &lt;= 10<sup>4</sup></code></li>
	<li><code>puzzles[i].length == 7</code></li>
	<li><code>words[i]</code> and <code>puzzles[i]</code> consist of lowercase English letters.</li>
	<li>Each <code>puzzles[i] </code>does not contain repeated characters.</li>
</ul>


**Companies**:  
[Dropbox](https://leetcode.com/company/dropbox)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Trie](https://leetcode.com/tag/trie/)

## Solution 1. Bitmask

The key is to realize that there are at most `2^6 = 64` bitmasks for each puzzle.

```cpp
// OJ: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
// Author: github.com/lzl124631x
// Time: O(WC + P * 2^L) where `W` is the length of `words`, `C` is the max length of `words[i]`, `P` is the length of `puzzles`, and `L` is the length of `puzzles[i]`.
// Space: O(W)
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& W, vector<string>& P) {
        unordered_map<int, int> cnt;
        for (auto &s : W) {
            int m = 0;
            for (char c : s) m |= 1 << (c - 'a');
            if (__builtin_popcount(m) > 7) continue;
            cnt[m]++;
        }
        function<int(string&, int, int)> dfs = [&](string &s, int i, int m) {
            if (i == s.size()) return cnt.count(m) ? cnt[m] : 0;
            return dfs(s, i + 1, m) + dfs(s, i + 1, m | (1 << (s[i] - 'a')));
        };
        vector<int> ans;
        for (auto &s : P) {
            int m = 1 << (s[0] - 'a');
            ans.push_back(dfs(s, 1, m));
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
// Author: github.com/lzl124631x
// Time: O(WC + P * 2^L) where `W` is the length of `words`, `C` is the max length of `words[i]`, `P` is the length of `puzzles`, and `L` is the length of `puzzles[i]`.
// Space: O(W)
class Solution {
    int encode(const string &s) {
        int b = 0;
        for (char c : s) b |= 1 << (c - 'a');
        return b;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& W, vector<string>& P) {
        unordered_map<int, int> cnt;
        for (auto &w : W) cnt[encode(w)]++;
        vector<int> ans;
        auto count = [&](int m) { return cnt.count(m) ? cnt[m] : 0; };
        for (auto &p : P) {
            int b = encode(p.substr(1)), first = 1 << (p[0] - 'a'), c = count(first);
            for (int m = b; m; m = (m - 1) & b) c += count(m | first);
            ans.push_back(c);
        }
        return ans;
    }
};
```

## Solution 2. Trie

```cpp
// OJ: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
// Author: github.com/lzl124631x
// Time: O(WC + P * 2^L) where `W` is the length of `words`, `C` is the max length of `words[i]`, `P` is the length of `puzzles`, and `L` is the length of `puzzles[i]`.
// Space: O(W)
struct TrieNode {
    TrieNode *next[26] = {};
    int cnt = 0;
};
class Solution {
    int encode(const string &s) {
        int b = 0;
        for (char c : s) b |= 1 << (c - 'a');
        return b;
    }
    void addWord(TrieNode *node, int b) {
        if (__builtin_popcount(b) > 7) return;
        for (int i = 0; i < 26; ++i) {
            if ((b >> i & 1) == 0) continue;
            if (!node->next[i]) node->next[i] = new TrieNode();
            node = node->next[i];
        }
        node->cnt++;
    }
    int dfs(TrieNode *node, int b, int i, int first) {
        if (!node) return 0;
        if (i == 26) return node->cnt;
        if (i == first) return dfs(node->next[i], b, i + 1, first); // first letter must be selected.
        if ((b >> i & 1) == 0) return dfs(node, b, i + 1, first); // this letter is not in the puzzle, skip
        return dfs(node->next[i], b, i + 1, first) + dfs(node, b, i + 1, first); // either choose the current letter or not
    }
public:
    vector<int> findNumOfValidWords(vector<string>& W, vector<string>& P) {
        TrieNode root;
        for (auto &w : W) addWord(&root, encode(w));
        vector<int> ans;
        for (auto &p : P) ans.push_back(dfs(&root, encode(p.substr(1)), 0, p[0] - 'a'));
        return ans;
    }
};
```