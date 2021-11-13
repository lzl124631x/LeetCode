# [2068. Check Whether Two Strings are Almost Equivalent (Easy)](https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/)

<p>Two strings <code>word1</code> and <code>word2</code> are considered <strong>almost equivalent</strong> if the differences between the frequencies of each letter from <code>'a'</code> to <code>'z'</code> between <code>word1</code> and <code>word2</code> is <strong>at most</strong> <code>3</code>.</p>

<p>Given two strings <code>word1</code> and <code>word2</code>, each of length <code>n</code>, return <code>true</code> <em>if </em><code>word1</code> <em>and</em> <code>word2</code> <em>are <strong>almost equivalent</strong>, or</em> <code>false</code> <em>otherwise</em>.</p>

<p>The <strong>frequency</strong> of a letter <code>x</code> is the number of times it occurs in the string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word1 = "aaaa", word2 = "bccb"
<strong>Output:</strong> false
<strong>Explanation:</strong> There are 4 'a's in "aaaa" but 0 'a's in "bccb".
The difference is 4, which is more than the allowed 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word1 = "abcdeef", word2 = "abaaacc"
<strong>Output:</strong> true
<strong>Explanation:</strong> The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 1 time in word1 and 4 times in word2. The difference is 3.
- 'b' appears 1 time in word1 and 1 time in word2. The difference is 0.
- 'c' appears 1 time in word1 and 2 times in word2. The difference is 1.
- 'd' appears 1 time in word1 and 0 times in word2. The difference is 1.
- 'e' appears 2 times in word1 and 0 times in word2. The difference is 2.
- 'f' appears 1 time in word1 and 0 times in word2. The difference is 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> word1 = "cccddabba", word2 = "babababab"
<strong>Output:</strong> true
<strong>Explanation:</strong> The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 2 times in word1 and 4 times in word2. The difference is 2.
- 'b' appears 2 times in word1 and 5 times in word2. The difference is 3.
- 'c' appears 3 times in word1 and 0 times in word2. The difference is 3.
- 'd' appears 2 times in word1 and 0 times in word2. The difference is 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == word1.length == word2.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>word1</code> and <code>word2</code> consist only of lowercase English letters.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkAlmostEquivalent(string s, string t) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int i = 0; i < 26; ++i) {
            if (abs(cnt[i]) > 3) return false;
        }
        return true;
    }
};
```

## Discuss

https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/discuss/1575960/C%2B%2B-Straightforward