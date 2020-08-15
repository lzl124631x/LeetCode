# [1268. Search Suggestions System (Medium)](https://leetcode.com/problems/search-suggestions-system/)

<p>Given an array of strings <code>products</code> and a string <code>searchWord</code>. We want to design a system that suggests at most three product names from <code>products</code>&nbsp;after each character of&nbsp;<code>searchWord</code> is typed. Suggested products should have common prefix with the searchWord. If there are&nbsp;more than three products with a common prefix&nbsp;return the three lexicographically minimums products.</p>

<p>Return <em>list of lists</em> of the suggested <code>products</code> after each character of&nbsp;<code>searchWord</code> is typed.&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
<strong>Output:</strong> [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
<strong>Explanation:</strong> products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> products = ["havana"], searchWord = "havana"
<strong>Output:</strong> [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
<strong>Output:</strong> [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> products = ["havana"], searchWord = "tatiana"
<strong>Output:</strong> [[],[],[],[],[],[],[]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= products.length &lt;= 1000</code></li>
	<li>There are no&nbsp;repeated elements in&nbsp;<code>products</code>.</li>
	<li><code>1 &lt;= Σ products[i].length &lt;= 2 * 10^4</code></li>
	<li>All characters of <code>products[i]</code> are lower-case English letters.</li>
	<li><code>1 &lt;= searchWord.length &lt;= 1000</code></li>
	<li>All characters of <code>searchWord</code>&nbsp;are lower-case English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. Trie

```cpp
// OJ: https://leetcode.com/problems/search-suggestions-system/
// Author: github.com/lzl124631x
// Time: O(DS) where D is the size of all the content in the `products`, S is the length of `searchWord`.
// Space: O(D)
struct TrieNode {
    TrieNode *next[26] = {};
    int index = -1;
};
class Solution {
    void add(TrieNode *node, string &w, int i) {
        for (char c : w) {
            int j = c - 'a';
            if (node->next[j] == NULL) node->next[j] = new TrieNode();
            node = node->next[j];
        }
        node->index = i;
    }
    void collect(TrieNode *node, vector<string> &ans, vector<string> &A) {
        if (ans.size() == 3) return;
        if (!node) return;
        if (node->index > -1) ans.push_back(A[node->index]);
        for (int i = 0; i < 26; ++i) collect(node->next[i], ans, A);
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string s) {
        TrieNode root, *node = &root;
        for (int i = 0; i < A.size(); ++i) add(&root, A[i], i);
        vector<vector<string>> ans;
        for (char c : s) {
            ans.emplace_back();
            if (ans.size() > 1 && ans[ans.size() - 2].empty()) continue;
            if (node->next[c - 'a'] == NULL) continue;
            node = node->next[c - 'a'];
            collect(node, ans.back(), A);
        }
        return ans;
    }
};
```