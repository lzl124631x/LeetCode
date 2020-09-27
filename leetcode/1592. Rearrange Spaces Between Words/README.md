# [1592. Rearrange Spaces Between Words (Easy)](https://leetcode.com/problems/rearrange-spaces-between-words/)

<p>You are given a string <code>text</code> of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that <code>text</code> <strong>contains at least one word</strong>.</p>

<p>Rearrange the spaces so that there is an <strong>equal</strong> number of spaces between every pair of adjacent words and that number is <strong>maximized</strong>. If you cannot redistribute all the spaces equally, place the <strong>extra spaces at the end</strong>, meaning the returned string should be the same length as <code>text</code>.</p>

<p>Return <em>the string after rearranging the spaces</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text = "  this   is  a sentence "
<strong>Output:</strong> "this   is   a   sentence"
<strong>Explanation: </strong>There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text = " practice   makes   perfect"
<strong>Output:</strong> "practice   makes   perfect "
<strong>Explanation:</strong>&nbsp;There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> text = "hello   world"
<strong>Output:</strong> "hello   world"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> text = "  walks  udp package   into  bar a"
<strong>Output:</strong> "walks  udp  package  into  bar  a "
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> text = "a"
<strong>Output:</strong> "a"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 100</code></li>
	<li><code>text</code>&nbsp;consists of lowercase English letters and&nbsp;<code>' '</code>.</li>
	<li><code>text</code>&nbsp;contains at least one word.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Text Justification (Hard)](https://leetcode.com/problems/text-justification/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/rearrange-spaces-between-words/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string reorderSpaces(string s) {
        int N = s.size(), cnt = 0;
        for (char c : s) cnt += c == ' ';
        string word;
        istringstream ss(s);
        vector<string> words;
        while (ss >> word) words.push_back(word);
        string ans;
        if (words.size() == 1) {
            ans += words[0];
            for (int i = 0; i < cnt; ++i) ans += ' ';
            return ans;
        }
        int d = cnt / (words.size() - 1), r = cnt - d * (words.size() - 1);
        for (int i = 0; i < words.size(); ++i) {
            ans += words[i];
            int e = i < words.size() - 1 ? d : r;
            for (int k = 0; k < e; ++k) ans += ' ';
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/rearrange-spaces-between-words/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reorderSpaces(string s) {
        int N = s.size(), space = 0, word = 0;
        for (int i = 0; i < N; ++i) {
            if (s[i] == ' ') space++;
            else if (i == 0 || s[i - 1] == ' ') ++word;
        }
        string ans;
        int d = word == 1 ? 0 : (space / (word - 1)), r = word == 1 ? space : (space - d * (word - 1));
        for (int i = 0, w = 0; i < N; ++i) {
            if (s[i] == ' ') continue;
            while (i < N && s[i] != ' ') ans += s[i++];
            int e = w < word - 1 ? d : r;
            ++w;
            for (int k = 0; k < e; ++k) ans += ' ';
        }
        return ans;
    }
};
```