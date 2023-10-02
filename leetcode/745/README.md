# [745. Prefix and Suffix Search (Hard)](https://leetcode.com/problems/prefix-and-suffix-search/)

<p>Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.</p>

<p>Implement the <code>WordFilter</code> class:</p>

<ul>
	<li><code>WordFilter(string[] words)</code> Initializes the object with the <code>words</code> in the dictionary.</li>
	<li><code>f(string prefix, string suffix)</code> Returns <em>the index of the word in the dictionary</em> which has the prefix <code>prefix</code> and the suffix <code>suffix</code>. If there is&nbsp;more than one valid index, return <strong>the largest</strong> of them. If there is no such word in the dictionary, return <code>-1</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
<strong>Output</strong>
[null, 0]

<strong>Explanation</strong>
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 15000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= prefix.length, suffix.length&nbsp;&lt;= 10</code></li>
	<li><code>words[i]</code>, <code>prefix</code> and <code>suffix</code> consist of lower-case English letters only.</li>
	<li>At most <code>15000</code> calls will be made to the function <code>f</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Design Add and Search Words Data Structure (Medium)](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/prefix-and-suffix-search/
// Author: github.com/lzl124631x
// Time:
//   * WordFilter: O(WL)
//   * f: O(L + W)
// Space: O(WL) where W is `words` length and L is max word length.
struct TrieNode {
    TrieNode *next[26] = {};
    vector<int> index;
};
class WordFilter {
    TrieNode prefixRoot, suffixRoot;
    void addWord(TrieNode *node, string &w, int i) {
        for (char c : w) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->index.push_back(i);
        }
    }
    vector<int> getIndexes(TrieNode *node, string &w) {
        for (char c : w) {
            node = node->next[c - 'a'];
            if (!node) return {};
        }
        return node->index;
    }
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            auto &w = words[i];
            addWord(&prefixRoot, w, i);
            reverse(begin(w), end(w));
            addWord(&suffixRoot, w, i);
        }
    }
    
    int f(string prefix, string suffix) {
        reverse(begin(suffix), end(suffix));
        auto p = getIndexes(&prefixRoot, prefix), s = getIndexes(&suffixRoot, suffix);
        for (int i = p.size() - 1, j = s.size() - 1; i >= 0 && j >= 0; ) {
            if (p[i] == s[j]) return p[i];
            if (p[i] < s[j]) --j;
            else --i;
        }
        return -1;
    }
};
```