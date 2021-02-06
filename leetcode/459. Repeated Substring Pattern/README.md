# [459. Repeated Substring Pattern (Easy)](https://leetcode.com/problems/repeated-substring-pattern/)

<p>Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.</p>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> "abab"
<b>Output:</b> True
<b>Explanation:</b> It's the substring "ab" twice.
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> "aba"
<b>Output:</b> False
</pre>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> "abcabcabcabc"
<b>Output:</b> True
<b>Explanation:</b> It's the substring "abc" four times. (And the substring "abcabc" twice.)
</pre>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

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
        int k = -1, N = s.size();
        vector<int> pi(N + 1, -1);
        for (int i = 1; i <= N; ++i) {
            while (k >= 0 && s[k] != s[i - 1]) k = pi[k];
            pi[i] = ++k;
        }
        return pi[N] && (pi[N] % (N - pi[N]) == 0);
    }
};
```