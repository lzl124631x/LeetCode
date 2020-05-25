# [1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence (Easy)](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)

<p>Given a <code>sentence</code>&nbsp;that consists of some words separated by a&nbsp;<strong>single space</strong>, and a <code>searchWord</code>.</p>

<p>You have to check if <code>searchWord</code> is a prefix of any word in <code>sentence</code>.</p>

<p>Return <em>the index of the word</em> in <code>sentence</code> where <code>searchWord</code> is a prefix of this word (<strong>1-indexed</strong>).</p>

<p>If <code>searchWord</code> is&nbsp;a prefix of more than one word, return the index of the first word <strong>(minimum index)</strong>. If there is no such word return <strong>-1</strong>.</p>

<p>A <strong>prefix</strong> of a string&nbsp;<code>S</code> is any leading contiguous substring of <code>S</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sentence = "i love eating burger", searchWord = "burg"
<strong>Output:</strong> 4
<strong>Explanation:</strong> "burg" is prefix of "burger" which is the 4th word in the sentence.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sentence = "this problem is an easy problem", searchWord = "pro"
<strong>Output:</strong> 2
<strong>Explanation:</strong> "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> sentence = "i am tired", searchWord = "you"
<strong>Output:</strong> -1
<strong>Explanation:</strong> "you" is not a prefix of any word in the sentence.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> sentence = "i use triple pillow", searchWord = "pill"
<strong>Output:</strong> 4
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> sentence = "hello from the other side", searchWord = "they"
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 100</code></li>
	<li><code>1 &lt;= searchWord.length &lt;= 10</code></li>
	<li><code>sentence</code> consists of lowercase English letters and spaces.</li>
	<li><code>searchWord</code>&nbsp;consists of lowercase English letters.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

Keep extracting word as `word` out of `s` and check if `w` is a prefix of `word`.

```cpp
// OJ: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        istringstream ss(s);
        string word;
        for (int i = 1; ss >> word; ++i) {
            if (word.size() >= w.size() && word.substr(0, w.size()) == w) return i;
        }
        return -1;
    }
};
```

## Solution 2.

Some other variations that just require constant extra space for string comparison.

```cpp
// OJ: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        istringstream ss(s);
        string word;
        for (int i = 1; ss >> word; ++i) {
            if (word.size() >= w.size() && mismatch(w.begin(), w.end(), word.begin()).first == w.end()) return i;
        }
        return -1;
    }
};
```

```cpp
// OJ: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        istringstream ss(s);
        string word;
        for (int i = 1; ss >> word; ++i) {
            string_view wv(word);
            if (word.size() >= w.size() && wv.substr(0, w.size()) == w) return i;
        }
        return -1;
    }
};
```