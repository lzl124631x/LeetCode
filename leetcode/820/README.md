# [820. Short Encoding of Words (Medium)](https://leetcode.com/problems/short-encoding-of-words/)

<p>A <strong>valid encoding</strong> of an array of <code>words</code> is any reference string <code>s</code> and array of indices <code>indices</code> such that:</p>

<ul>
	<li><code>words.length == indices.length</code></li>
	<li>The reference string <code>s</code> ends with the <code>'#'</code> character.</li>
	<li>For each index <code>indices[i]</code>, the <strong>substring</strong> of <code>s</code> starting from <code>indices[i]</code> and up to (but not including) the next <code>'#'</code> character is equal to <code>words[i]</code>.</li>
</ul>

<p>Given an array of <code>words</code>, return <em>the <strong>length of the shortest reference string</strong> </em><code>s</code><em> possible of any <strong>valid encoding</strong> of </em><code>words</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["time", "me", "bell"]
<strong>Output:</strong> 10
<strong>Explanation:</strong> A valid encoding would be s = <code>"time#bell#" and indices = [0, 2, 5</code>].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "<u>time</u>#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "ti<u>me</u>#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#<u>bell</u>#"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["t"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> A valid encoding would be s = "t#" and indices = [0].

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 2000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 7</code></li>
	<li><code>words[i]</code> consists of only lowercase letters.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/short-encoding-of-words/
// Author: github.com/lzl124631x
// Time: O(NlogN * W)
// Space: O(W)
class Solution {
public:
    int minimumLengthEncoding(vector<string>& A) {
        string prev = "";
        int ans = 0;
        for (auto &s : A) reverse(begin(s), end(s));
        sort(begin(A), end(A));
        for (auto &s : A) {
            if (prev != "" && (s.size() < prev.size() || s.substr(0, prev.size()) != prev)) { // the current string can't cover the previous string, must start a new segment.
                ans += 1 + prev.size(); // close the previous segment.
            }
            prev = s;
        }
        return ans + 1 + prev.size();
    }
};
```

## Solution 2. Trie

```cpp
// OJ: https://leetcode.com/problems/short-encoding-of-words/
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(NW)
struct TrieNode {
    TrieNode *next[26] = {};
    bool isLeaf = true;
};
class Solution {
    int dfs(TrieNode *root, int len = 0) {
        if (!root) return 0;
        if (root->isLeaf) return len + 1;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (root->next[i]) ans += dfs(root->next[i], len + 1);
        }
        return ans;
    }
public:
    int minimumLengthEncoding(vector<string>& A) {
        TrieNode root;
        for (auto &s : A) {
            auto node = &root;
            reverse(begin(s), end(s));
            for (char c : s) {
                if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
                node->isLeaf = false;
                node = node->next[c - 'a'];
            }
        }
        return dfs(&root);
    }
};
```