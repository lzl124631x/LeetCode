# [2047. Number of Valid Words in a Sentence (Easy)](https://leetcode.com/problems/number-of-valid-words-in-a-sentence/)

<p>A sentence consists of lowercase letters (<code>'a'</code> to <code>'z'</code>), digits (<code>'0'</code> to <code>'9'</code>), hyphens (<code>'-'</code>), punctuation marks (<code>'!'</code>, <code>'.'</code>, and <code>','</code>), and spaces (<code>' '</code>) only. Each sentence can be broken down into <strong>one or more tokens</strong> separated by one or more spaces <code>' '</code>.</p>

<p>A token is a valid word if:</p>

<ul>
	<li>It only contains lowercase letters, hyphens, and/or punctuation (<strong>no</strong> digits).</li>
	<li>There is <strong>at most one</strong> hyphen <code>'-'</code>. If present, it should be surrounded by lowercase characters (<code>"a-b"</code> is valid, but <code>"-ab"</code> and <code>"ab-"</code> are not valid).</li>
	<li>There is <strong>at most one</strong> punctuation mark. If present, it should be at the <strong>end</strong> of the token.</li>
</ul>

<p>Examples of valid words include <code>"a-b."</code>, <code>"afad"</code>, <code>"ba-c"</code>, <code>"a!"</code>, and <code>"!"</code>.</p>

<p>Given a string <code>sentence</code>, return <em>the <strong>number</strong> of valid words in </em><code>sentence</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sentence = "<u>cat</u> <u>and</u>  <u>dog</u>"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The valid words in the sentence are "cat", "and", and "dog".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sentence = "!this  1-s b8d!"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no valid words in the sentence.
"!this" is invalid because it starts with a punctuation mark.
"1-s" and "b8d" are invalid because they contain digits.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> sentence = "<u>alice</u> <u>and</u>  <u>bob</u> <u>are</u> <u>playing</u> stone-game10"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The valid words in the sentence are "alice", "and", "bob", "are", and "playing".
"stone-game10" is invalid because it contains digits.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> sentence = "<u>he</u> <u>bought</u> 2 <u>pencils,</u> 3 <u>erasers,</u> <u>and</u> 1  <u>pencil-sharpener.</u>"
<strong>Output:</strong> 6
<strong>Explanation:</strong> The valid words in the sentence are "he", "bought", "pencils,", "erasers,", "and", and "pencil-sharpener.".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 1000</code></li>
	<li><code>sentence</code> only contains lowercase English letters, digits, <code>' '</code>, <code>'-'</code>, <code>'!'</code>, <code>'.'</code>, and <code>','</code>.</li>
	<li>There will be at least&nbsp;<code>1</code> token.</li>
</ul>


## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    bool valid(string &s) {
        int hyphen = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            if (isdigit(s[i])) return false; // no digit
            if (isalpha(s[i])) continue; // skip letters
            if (s[i] == '-') {
                if (++hyphen > 1) return false; // at most one hyphen allowed
                if (i - 1 < 0 || !isalpha(s[i - 1]) || i + 1 >= N || !isalpha(s[i + 1])) return false; // hyphen must be surrounded by letters
            } else if (i != N - 1) return false; // punctuation, if any, must be the last character of token
        }
        return true;
    }
public:
    int countValidWords(string s) {
        string w;
        istringstream ss(s);
        int ans = 0;
        while (ss >> w) ans += valid(w);
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/number-of-valid-words-in-a-sentence/discuss/1537483/C%2B%2B-Straight-Forward