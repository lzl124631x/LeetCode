# [336. Palindrome Pairs (Hard)](https://leetcode.com/problems/palindrome-pairs/)

<p>Given a list of <b>unique</b> words, find all pairs of <b><i>distinct</i></b> indices <code>(i, j)</code> in the given list, so that the concatenation of the two words, i.e. <code>words[i] + words[j]</code> is a palindrome.</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">["abcd","dcba","lls","s","sssll"]</span>
<strong>Output: </strong><span id="example-output-1">[[0,1],[1,0],[3,2],[2,4]] 
<strong>E</strong></span><strong>xplanation<span>: </span></strong>The palindromes are <code>["dcbaabcd","abcddcba","slls","llssssll"]</code>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">["bat","tab","cat"]</span>
<strong>Output: </strong><span id="example-output-2">[[0,1],[1,0]] 
</span><span id="example-output-1"><strong>E</strong></span><strong>xplanation<span>: </span></strong>The palindromes are <code>["battab","tabbat"]</code>
</pre>
</div>
</div>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)
* [Shortest Palindrome (Hard)](https://leetcode.com/problems/shortest-palindrome/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/palindrome-pairs/
// Author: github.com/lzl124631x
// Time: O(N * L^2)
// Space: O(NL)
// Ref: https://leetcode.com/problems/palindrome-pairs/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure
struct TrieNode {
    TrieNode *next[26] = {};
    int index = -1;
    vector<int> palindromeIndexes;
};
class Solution {
    TrieNode root; // Suffix trie
    void add(string &s, int i) {
        auto node = &root;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (isPalindrome(s, 0, j)) node->palindromeIndexes.push_back(i); // A[i]'s prefix forms a palindrome
            int c = s[j] - 'a';
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = i;
        node->palindromeIndexes.push_back(i); // A[i]'s prefix is empty string here, which is a palindrome.
    }
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) add(A[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < N; ++i) {
            auto s = A[i];
            auto node = &root;
            for (int j = 0; j < s.size() && node; ++j) {
                if (node->index != -1 && node->index != i && isPalindrome(s, j, s.size() - 1)) ans.push_back({ i, node->index }); // A[i]'s prefix matches this word and A[i]'s suffix forms a palindrome
                node = node->next[s[j] - 'a'];
            }
            if (!node) continue;
            for (int j : node->palindromeIndexes) { // A[i] is exhausted in the matching above. If a word whose prefix is palindrome after matching its suffix with A[i], then this is also a valid pair
                if (i != j) ans.push_back({ i, j });
            }
        }
        return ans;
    }
};
```