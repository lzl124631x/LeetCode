# [214. Shortest Palindrome (Hard)](https://leetcode.com/problems/shortest-palindrome/)

<p>You are given a string <code>s</code>. You can convert <code>s</code> to a palindrome by adding characters in front of it.</p>

<p>Return <em>the shortest palindrome you can find by performing this transformation</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aacecaaa"
<strong>Output:</strong> "aaacecaaa"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> "dcbabcd"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [String Matching](https://leetcode.com/tag/string-matching/), [Hash Function](https://leetcode.com/tag/hash-function/)

**Similar Questions**:
* [Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)
* [Implement strStr() (Easy)](https://leetcode.com/problems/implement-strstr/)
* [Palindrome Pairs (Hard)](https://leetcode.com/problems/palindrome-pairs/)

## Solution 1. Rolling Hash

Find the longest palindrome starting at index 0.

```cpp
// OJ: https://leetcode.com/problems/shortest-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) ignoring the space taken by the answer
class Solution {
public:
    string shortestPalindrome(string s) {
        unsigned d = 16777619, h = 0, rh = 0, p = 1, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            h = h * d + s[i] - 'a';
            rh += (s[i] - 'a') * p;
            p *= d;
            if (h == rh) maxLen = i + 1;
        }
        return string(rbegin(s), rbegin(s) + s.size() - maxLen) + s;
    }
};
```

## Solution 2. Manacher

```cpp
// OJ: https://leetcode.com/problems/shortest-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string shortestPalindrome(string s) {
        int N = s.size();
        string t = "^*";
        for (char c : s) {
            t += c;
            t += '*';
        }
        t += '$';
        vector<int> r(t.size(), 1);
        int j = 1, len = 0;
        for (int i = 2; i <= 2 * N; ++i) {
            int cur = j + r[j] > i ? min(r[2 * j - i], j + r[j] - i) : 1;
            while (t[i - cur] == t[i + cur]) ++cur;
            if (i + cur > j + r[j]) j = i;
            r[i] = cur;
            if (i - cur == 0) len = i - 1;
        }
        return string(rbegin(s), rbegin(s) + N - len) + s;
    }
};
```