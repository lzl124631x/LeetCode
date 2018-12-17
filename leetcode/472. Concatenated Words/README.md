# [472. Concatenated Words (Hard)](https://leetcode.com/problems/concatenated-words/)

Given a list of words (<b>without duplicates</b>), please write a program that returns all concatenated words in the given list of words.
<p>A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.</p>

<p><b>Example:</b><br>
</p><pre><b>Input:</b> ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

<b>Output:</b> ["catsdogcats","dogcatsdog","ratcatdogcat"]

<b>Explanation:</b> "catsdogcats" can be concatenated by "cats", "dog" and "cats"; <br> "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; <br>"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The number of elements of the given array will not exceed <code>10,000 </code>
</li><li>The length sum of elements in the given array will not exceed <code>600,000</code>. </li>
<li>All the input string will only include lower case letters.</li>
<li>The returned elements order does not matter. </li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Word Break II (Hard)](https://leetcode.com/problems/word-break-ii/)

## Solution 1. Trie + C++ Static Pool
Use Trie to store the words.

Use DFS to check whether a word is a concatenated word: traverse from the first letter in word, whenever we meet an word ending, start a new DFS call and re-search from the trie root. If the word is exhausted by matching at least two words, return true; otherwise return false.

```cpp
// OJ: https://leetcode.com/problems/concatenated-words/
// Author: github.com/lzl124631x
// Time: O(N*2^W) where N is length of words array, W is max word length. 
//       2^W is because for each letter we may start or not start a new check there.
// Space: O(C) where C is the length sum of words.
// Ref: https://discuss.leetcode.com/topic/72754/trie-dfs-method-using-static-trie-node-to-avoid-getting-mle-runtime-about-300ms
// NOTE: Use statically allocated memory to avoid MLE in C++.
class TrieNode {
public:
    bool end = false;
    TrieNode *next[26];
};

TrieNode pool[60000];

class Solution {
private:
    TrieNode *root = pool;
    int cnt = 1;
    void insert(string &word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = &pool[cnt++];
            node = node->next[c - 'a'];
        }
        node->end = true;
    }
    
    bool check(string &word, int start) {
        if (start == word.size()) return true;
        TrieNode *node = root;
        for (int i = start; i < word.size(); ++i) {
            node = node->next[word[i] - 'a'];
            if (!node) return false;
            if (i != word.size() - 1 && node->end && check(word, i + 1)) return true;
        }
        return node->end && start;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        memset(pool, 0, sizeof(pool)); // reset pool.
        for (string s : words) insert(s);
        vector<string> ans;
        for (string s : words) {
            if (s.empty()) continue;
            if (check(s, 0)) ans.push_back(s);
        }
        return ans;
    }
};
```

## Solution 2: Trie + unordered_map

Same idea as Solution 1, instead of using statically allocated `pool`, use `unordered_map` to store `children` mapping in `TrieNode`.

```cpp
// OJ: https://leetcode.com/problems/concatenated-words/
// Author: github.com/lzl124631x
// Time: O(N*2^W) where N is length of words array, W is max word length. 
//       2^W is because for each letter we may start or not start a new check there.
// Space: O(C) where C is the length sum of words.
// NOTE: use `unordered_map` instead of `TrieNode*[26]` to save space.
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Trie {
private:
    TrieNode root;
    bool dfs(string &word, int start, int cnt) {
        if (start == word.size()) return cnt > 1;
        TrieNode *node = &root;
        for (int i = start; i < word.size(); ++i) {
            if (node->children.find(word[i]) == node->children.end()) return false;
            TrieNode *next = node->children[word[i]];
            if (next->isWord && dfs(word, i + 1, cnt + 1)) return true;
            node = next;
        }
        return false;
    }
public:
    void insert(string &word) {
        TrieNode *node = &root;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool isConcatednatedWord(string &word) {
        return dfs(word, 0, 0);
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;
        for (auto word : words) trie.insert(word);
        vector<string> ans;
        for (auto word : words) {
            if (trie.isConcatednatedWord(word)) ans.push_back(word);
        }
        return ans;
    }
};
```

## Solution 3. DP

Use `dp[i]` to denote whether `word[0..i]` is a concatenated word.

`dp[i] = true`, if there is a `j` &isin; `[0,i]` such that `word[0..j]` and `word[j..i]` are all words in `words` array.

In my opinion, this is just doing DFS in another way.

```cpp
// OJ: https://leetcode.com/problems/concatenated-words/
// Author: github.com/lzl124631x
// Time: O(N*W^3)
// Space: O(C) where C is the length sum of words.
// Ref: https://discuss.leetcode.com/topic/72393/c-772-ms-dp-solution
class Solution {
private:
    unordered_set<string> s;
    bool isConcatenatedWord(string &word) {
        int W = word.size();
        vector<bool> dp(W, false);
        for (int i = 0; i < W - 1; ++i) {
            if (s.count(word.substr(0, i + 1))) dp[i] = true;
            if (!dp[i]) continue;
            for (int j = i + 1; j < W; ++j) {
                if (s.count(word.substr(i + 1, j - i))) dp[j] = true;
            }
            if (dp[W - 1]) return true;
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        s = unordered_set<string>(words.begin(), words.end());
        vector<string> ans;
        for (string &word : words) {
            if (isConcatenatedWord(word)) ans.push_back(word);
        }
        return ans;
    }
};
```