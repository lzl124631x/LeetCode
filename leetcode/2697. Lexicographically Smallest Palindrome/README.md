# [2697. Lexicographically Smallest Palindrome (Easy)](https://leetcode.com/problems/lexicographically-smallest-palindrome)

<p>You are given a string <code node="[object Object]">s</code> consisting of <strong>lowercase English letters</strong>, and you are allowed to perform operations on it. In one operation, you can <strong>replace</strong> a character in <code node="[object Object]">s</code> with another lowercase English letter.</p>
<p>Your task is to make <code node="[object Object]">s</code> a <strong>palindrome</strong> with the <strong>minimum</strong> <strong>number</strong> <strong>of operations</strong> possible. If there are <strong>multiple palindromes</strong> that can be <meta charset="utf-8">made using the <strong>minimum</strong> number of operations, <meta charset="utf-8">make the <strong>lexicographically smallest</strong> one.</p>
<p>A string <code>a</code> is lexicographically smaller than a string <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, string <code>a</code> has a letter that appears earlier in the alphabet than the corresponding letter in <code>b</code>.</p>
<p>Return <em>the resulting palindrome string.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "egcfe"
<strong>Output:</strong> "efcfe"
<strong>Explanation:</strong> The minimum number of operations to make "egcfe" a palindrome is 1, and the lexicographically smallest palindrome string we can get by modifying one character is "efcfe", by changing 'g'.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> "abba"
<strong>Explanation:</strong> The minimum number of operations to make "abcd" a palindrome is 2, and the lexicographically smallest palindrome string we can get by modifying two characters is "abba".
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "seven"
<strong>Output:</strong> "neven"
<strong>Explanation:</strong> The minimum number of operations to make "seven" a palindrome is 1, and the lexicographically smallest palindrome string we can get by modifying one character is "neven".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code>&nbsp;consists of only lowercase English letters<b>.</b></li>
</ul>

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/lexicographically-smallest-palindrome
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int i = 0, N = s.size(); i < N / 2; ++i) {
            if (s[i] == s[N - i - 1]) continue;
            s[i] = s[N - i - 1] = min(s[i], s[N - i - 1]);
        }
        return s;
    }
};
```