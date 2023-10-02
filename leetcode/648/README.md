# [648. Replace Words (Medium)](https://leetcode.com/problems/replace-words/)

<p>In English, we have a concept called <code>root</code>, which can be followed by some other words to form another longer word - let's call this word <code>successor</code>. For example, the root <code>an</code>, followed by <code>other</code>, which can form another word <code>another</code>.</p>

<p>Now, given a dictionary consisting of many roots and a sentence. You need to replace all the <code>successor</code> in the sentence with the <code>root</code> forming it. If a <code>successor</code> has many <code>roots</code> can form it, replace it with the root with the shortest length.</p>

<p>You need to output the sentence after the replacement.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
<b>Output:</b> "the cat was rat by the bat"
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The input will only have lower-case letters.</li>
	<li>1 &lt;= dict words number &lt;= 1000</li>
	<li>1 &lt;= sentence words number &lt;= 1000</li>
	<li>1 &lt;= root length &lt;= 100</li>
	<li>1 &lt;= sentence words length &lt;= 1000</li>
</ol>

<p>&nbsp;</p>


**Companies**:  
[Uber](https://leetcode.com/company/uber), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Trie](https://leetcode.com/tag/trie/)

## Solution 1. Trie

```cpp
// OJ: https://leetcode.com/problems/replace-words/
// Author: github.com/lzl124631x
// Time: O(D + S) where D is size of all contents in dictionary, S is size of all contents in sentence
// Space: O(D)
class TrieNode {
public:
    TrieNode *next[26] = {};
    bool isWord = false;
};
class Trie {
private:
    TrieNode root;
public:
    void insert(string &s) {
        auto node = &root;
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }
    string getWord(string &s) {
        auto node = &root;
        for (int i = 0; i < s.size(); ++i) {
            if (!node->next[s[i] - 'a']) return s;
            node = node->next[s[i] - 'a'];
            if (node->isWord) return s.substr(0, i + 1);
        }
        return s;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        istringstream ss(sentence);
        string word, ans;
        Trie trie;
        for (auto s : dict) trie.insert(s);
        while (ss >> word) ans += trie.getWord(word)+ " ";
        ans.pop_back();
        return ans;
    }
};
```