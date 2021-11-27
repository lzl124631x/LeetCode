# [459. Repeated Substring Pattern (Easy)](https://leetcode.com/problems/repeated-substring-pattern/)

<p>Given a string <code>s</code>, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abab"
<strong>Output:</strong> true
<strong>Explanation:</strong> It is the substring "ab" twice.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aba"
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abcabcabcabc"
<strong>Output:</strong> true
<strong>Explanation:</strong> It is the substring "abc" four times or the substring "abcabc" twice.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Salesforce](https://leetcode.com/company/salesforce)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [String Matching](https://leetcode.com/tag/string-matching/)

**Similar Questions**:
* [Implement strStr() (Easy)](https://leetcode.com/problems/implement-strstr/)
* [Repeated String Match (Medium)](https://leetcode.com/problems/repeated-string-match/)
## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/repeated-substring-pattern/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int N = s.size();
        for (int len = 1; len <= N / 2; ++len) {
            if (N % len) continue;
            int i = len;
            for (; i < N; ++i) {
                if (s[i] != s[i % len]) break;
            }
            if (i == N) return true;
        }
        return false;
    }
};
```

## Solution 2. Brute force with string_view

```cpp
// OJ: https://leetcode.com/problems/repeated-substring-pattern/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string_view p = s, sv = s;
        for (int len = s.size() / 2; len >= 1; --len) {
            if (s.size() % len) continue;
            p = p.substr(0, len);
            int i = s.size() / len - 1;
            for (; i >= 0 && p == sv.substr(i * len, len); --i);
            if (i < 0) return true;
        }
        return false;
    }
};
```

## Solution 3. KMP

```cpp
// OJ: https://leetcode.com/problems/repeated-substring-pattern/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/repeated-substring-pattern/discuss/94397/C%2B%2B-O(n)-using-KMP-32ms-8-lines-of-code-with-brief-explanation.
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int N = s.size(), j = -1;
        vector<int> lps(N + 1, -1);
        for (int i = 1; i <= N; ++i) {
            while (j >= 0 && s[i - 1] != s[j]) j = lps[j];
            lps[i] = ++j;
        }
        return lps[N] && (lps[N] % (N - lps[N])) == 0;
    }
};
```