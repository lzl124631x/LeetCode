# [1268. Search Suggestions System (Medium)](https://leetcode.com/problems/search-suggestions-system/)

<p>You are given an array of strings <code>products</code> and a string <code>searchWord</code>.</p>

<p>Design a system that suggests at most three product names from <code>products</code> after each character of <code>searchWord</code> is typed. Suggested products should have common prefix with <code>searchWord</code>. If there are more than three products with a common prefix return the three lexicographically minimums products.</p>

<p>Return <em>a list of lists of the suggested products after each character of </em><code>searchWord</code><em> is typed</em>.</p>

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

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= products.length &lt;= 1000</code></li>
	<li><code>1 &lt;= products[i].length &lt;= 3000</code></li>
	<li><code>1 &lt;= sum(products[i].length) &lt;= 2 * 10<sup>4</sup></code></li>
	<li>All the strings of <code>products</code> are <strong>unique</strong>.</li>
	<li><code>products[i]</code> consists of lowercase English letters.</li>
	<li><code>1 &lt;= searchWord.length &lt;= 1000</code></li>
	<li><code>searchWord</code> consists of lowercase English letters.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Trie](https://leetcode.com/tag/trie/)

## Solution 1. Trie

We can use Trie to compress the `products`. In order to suggest words, we need to store the index of the product in the corresponding last Trie Node.

During the suggestion phase, we can DFS to find the first 3 words. To ensure we find the lexicographically minimum products, we can find from 'a' to 'z' on each TrieNode.

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
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->index = i; // store the index of product
    }
    void collect(TrieNode *node, vector<string> &ans, vector<string> &A) {
        if (ans.size() == 3) return; // Once we've suggested 3 words, stop
        if (!node) return;
        if (node->index > -1) ans.push_back(A[node->index]);
        for (int i = 0; i < 26; ++i) collect(node->next[i], ans, A); // Since we are looking for the lexicographically minimum products, we look from 'a' to 'z'
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string s) {
        TrieNode root, *node = &root;
        for (int i = 0; i < A.size(); ++i) add(&root, A[i], i);
        vector<vector<string>> ans(s.size());
        for (int i = 0; i < s.size(); ++i) {
            node = node->next[s[i] - 'a'];
            if (!node) break;
            collect(node, ans[i], A);
        }
        return ans;
    }
};
```

## Solution 2. Trie

Another idea about the suggestion phase is that, instead of just storing the index of product in the last Trie Node, we store the index of product to all the Trie Nodes when traversing down. So, each Trie Node needs to store a vector of indices of products sharing the same prefix, sorted in ascending order.

Now, the suggestion phase becomes trivial -- we just take the first 3 indices stored in the Trie Node. We saved time at the cost of space.

```cpp
// OJ: https://leetcode.com/problems/search-suggestions-system/
// Author: github.com/lzl124631x
// Time: O(DS) where D is the size of all the content in the `products`, S is the length of `searchWord`.
// Space: O(D)
struct TrieNode {
    TrieNode *next[26] = {};
    vector<int> index;
};
class Solution {
    void addWord(TrieNode *node, string &w, int i) {
        for (char c : w) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->index.push_back(i);
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string s) {
        sort(begin(A), end(A));
        TrieNode root, *node = &root;
        for (int i = 0; i < A.size(); ++i) addWord(&root, A[i], i);
        vector<vector<string>> ans(s.size());
        for (int i = 0; i < s.size(); ++i) {
            node = node->next[s[i] - 'a'];
            if (!node || node->index.empty()) break;
            for (int j = 0; j < 3 && j < node->index.size(); ++j) ans[i].push_back(A[node->index[j]]);
        }
        return ans;
    }
};
```