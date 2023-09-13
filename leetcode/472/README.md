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

## Solution 1. DP

Use `dp[i]` to denote whether we can get `word[0..i]` by concatenating one or more words in the word list.

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
            if (s.count(word.substr(0, i + 1))) dp[i] = true; // If `s[0..i]` is in the word list, we mark `i` as reachable.
            if (!dp[i]) continue; // If `i` is not reachable, skip
            for (int j = i + 1; j < W; ++j) { // Given that we can reach `i`, we see if we can reach `j` via string `s[(i+1)..(j)]`.
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


## Solution 2. Trie + DP

### Complexity Analysis

Building the Trie will take `O(NW)` time and `O(NW)` space where `N` is the length of `A` and `W` is the maximum word length.

Checking if a word is a concatenated word will take `O(W^2)` time and `O(W)` space. So checking the `N` words will take `O(N * W^2)` time.

So overall, this solution takes `O(N * W^2)` time and `O(NW)` space.

```cpp
// OJ: https://leetcode.com/problems/concatenated-words/
// Author: github.com/lzl124631x
// Time: O(N * W^2)
// Space: O(NW)
struct TrieNode {
    TrieNode *next[26] = {};
    bool end = false;
};
class Solution {
    TrieNode root;
    void addWord(TrieNode *node, string &s) {
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->end = true;
    }
    bool valid(string &s) {
        int N = s.size();
        vector<bool> dp(N + 1);
        dp[0] = true;
        for (int i = 0; i < N && !dp[N]; ++i) {
            if (!dp[i]) continue;
            auto node = &root;
            for (int j = i; j < N - (i == 0); ++j) {
                node = node->next[s[j] - 'a'];
                if (!node) break;
                if (node->end) dp[j + 1] = true;
            }
        }
        return dp[N];
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& A) {
        for (auto &s : A) {
            if (s.empty()) continue;
            addWord(&root, s);
        }
        vector<string> ans;
        for (auto &s : A) {
            if (s.size() && valid(s)) ans.push_back(s);
        }
        return ans;
    }
};
```