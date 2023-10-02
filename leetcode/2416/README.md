# [2416. Sum of Prefix Scores of Strings (Hard)](https://leetcode.com/problems/sum-of-prefix-scores-of-strings)

<p>You are given an array <code>words</code> of size <code>n</code> consisting of <strong>non-empty</strong> strings.</p>
<p>We define the <strong>score</strong> of a string <code>word</code> as the <strong>number</strong> of strings <code>words[i]</code> such that <code>word</code> is a <strong>prefix</strong> of <code>words[i]</code>.</p>
<ul>
	<li>For example, if <code>words = ["a", "ab", "abc", "cab"]</code>, then the score of <code>"ab"</code> is <code>2</code>, since <code>"ab"</code> is a prefix of both <code>"ab"</code> and <code>"abc"</code>.</li>
</ul>
<p>Return <em>an array </em><code>answer</code><em> of size </em><code>n</code><em> where </em><code>answer[i]</code><em> is the <strong>sum</strong> of scores of every <strong>non-empty</strong> prefix of </em><code>words[i]</code>.</p>
<p><strong>Note</strong> that a string is considered as a prefix of itself.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["abc","ab","bc","b"]
<strong>Output:</strong> [5,4,3,2]
<strong>Explanation:</strong> The answer for each string is the following:
- "abc" has 3 prefixes: "a", "ab", and "abc".
- There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
The total is answer[0] = 2 + 2 + 1 = 5.
- "ab" has 2 prefixes: "a" and "ab".
- There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
The total is answer[1] = 2 + 2 = 4.
- "bc" has 2 prefixes: "b" and "bc".
- There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
The total is answer[2] = 2 + 1 = 3.
- "b" has 1 prefix: "b".
- There are 2 strings with the prefix "b".
The total is answer[3] = 2.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["abcd"]
<strong>Output:</strong> [4]
<strong>Explanation:</strong>
"abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Trie](https://leetcode.com/tag/trie/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Design Add and Search Words Data Structure (Medium)](https://leetcode.com/problems/design-add-and-search-words-data-structure/)
* [Maximum XOR of Two Numbers in an Array (Medium)](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)
* [Map Sum Pairs (Medium)](https://leetcode.com/problems/map-sum-pairs/)

## Solution 1. Trie

```cpp
// OJ: https://leetcode.com/problems/sum-of-prefix-scores-of-strings
// Author: github.com/lzl124631x
// Time: O(NL) where N is the length of A, and L is the max length of A[i]
// Space: O(NL)
struct TrieNode {
    TrieNode *next[26] = {};
    int cnt = 0;
};
class Solution {
    void addWords(TrieNode *node, string &s) {
        for (auto c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->cnt++;
        }
    }
public:
    vector<int> sumPrefixScores(vector<string>& A) {
        TrieNode root;
        for (auto &s : A) addWords(&root, s);
        vector<int> ans;
        for (auto &s : A) {
            int score = 0;
            auto node = &root;
            for (char c : s) {
                if (!node->next[c - 'a']) break;
                node = node->next[c - 'a'];
                score += node->cnt;
            }
            ans.push_back(score);
        }
        return ans;
    }
};
```