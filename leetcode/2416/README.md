# [2416. Sum of Prefix Scores of Strings (Hard)](https://leetcode.com/problems/sum-of-prefix-scores-of-strings)

<p>You are given an array <code>words</code> of size <code>n</code> consisting of <strong>non-empty</strong> strings.</p>

<p>We define the <strong>score</strong> of a string <code>word</code> as the <strong>number</strong> of strings <code>words[i]</code> such that <code>word</code> is a <strong>prefix</strong> of <code>words[i]</code>.</p>

<ul>
	<li>For example, if <code>words = [&quot;a&quot;, &quot;ab&quot;, &quot;abc&quot;, &quot;cab&quot;]</code>, then the score of <code>&quot;ab&quot;</code> is <code>2</code>, since <code>&quot;ab&quot;</code> is a prefix of both <code>&quot;ab&quot;</code> and <code>&quot;abc&quot;</code>.</li>
</ul>

<p>Return <em>an array </em><code>answer</code><em> of size </em><code>n</code><em> where </em><code>answer[i]</code><em> is the <strong>sum</strong> of scores of every <strong>non-empty</strong> prefix of </em><code>words[i]</code>.</p>

<p><strong>Note</strong> that a string is considered as a prefix of itself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abc&quot;,&quot;ab&quot;,&quot;bc&quot;,&quot;b&quot;]
<strong>Output:</strong> [5,4,3,2]
<strong>Explanation:</strong> The answer for each string is the following:
- &quot;abc&quot; has 3 prefixes: &quot;a&quot;, &quot;ab&quot;, and &quot;abc&quot;.
- There are 2 strings with the prefix &quot;a&quot;, 2 strings with the prefix &quot;ab&quot;, and 1 string with the prefix &quot;abc&quot;.
The total is answer[0] = 2 + 2 + 1 = 5.
- &quot;ab&quot; has 2 prefixes: &quot;a&quot; and &quot;ab&quot;.
- There are 2 strings with the prefix &quot;a&quot;, and 2 strings with the prefix &quot;ab&quot;.
The total is answer[1] = 2 + 2 = 4.
- &quot;bc&quot; has 2 prefixes: &quot;b&quot; and &quot;bc&quot;.
- There are 2 strings with the prefix &quot;b&quot;, and 1 string with the prefix &quot;bc&quot;.
The total is answer[2] = 2 + 1 = 3.
- &quot;b&quot; has 1 prefix: &quot;b&quot;.
- There are 2 strings with the prefix &quot;b&quot;.
The total is answer[3] = 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abcd&quot;]
<strong>Output:</strong> [4]
<strong>Explanation:</strong>
&quot;abcd&quot; has 4 prefixes: &quot;a&quot;, &quot;ab&quot;, &quot;abc&quot;, and &quot;abcd&quot;.
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
[Array](https://leetcode.com/tag/array), [String](https://leetcode.com/tag/string), [Trie](https://leetcode.com/tag/trie), [Counting](https://leetcode.com/tag/counting)

**Similar Questions**:
* [Design Add and Search Words Data Structure (Medium)](https://leetcode.com/problems/design-add-and-search-words-data-structure)
* [Maximum XOR of Two Numbers in an Array (Medium)](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array)
* [Map Sum Pairs (Medium)](https://leetcode.com/problems/map-sum-pairs)

**Hints**:
* What data structure will allow you to efficiently keep track of the score of each prefix?
* Use a Trie. Insert all the words into it, and keep a counter at each node that will tell you how many times we have visited each prefix.

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
    void addWord(TrieNode *node, string &s) {
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->cnt++;
        }
    }
    int count(TrieNode *node, string &s) {
        int ans = 0;
        for (char c : s) {
            node = node->next[c - 'a'];
            ans += node->cnt;
        }
        return ans;
    }
public:
    vector<int> sumPrefixScores(vector<string>& A) {
        TrieNode root;
        for (auto &s : A) addWord(&root, s);
        vector<int> ans;
        for (auto &s : A) ans.push_back(count(&root, s));
        return ans;
    }
};
```