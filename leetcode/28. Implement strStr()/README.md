# [28. Implement strStr() (Easy)](https://leetcode.com/problems/implement-strstr/)

<p>Implement <a href="http://www.cplusplus.com/reference/cstring/strstr/" target="_blank">strStr()</a>.</p>

<p>Return the index of the first occurrence of needle in haystack, or <strong>-1</strong> if needle is not part of haystack.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> haystack = "hello", needle = "ll"
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> haystack = "aaaaa", needle = "bba"
<strong>Output:</strong> -1
</pre>

<p><strong>Clarification:</strong></p>

<p>What should we return when <code>needle</code> is an empty string? This is a great question to ask during an interview.</p>

<p>For the purpose of this problem, we will return 0 when <code>needle</code> is an empty string. This is consistent to C's&nbsp;<a href="http://www.cplusplus.com/reference/cstring/strstr/" target="_blank">strstr()</a> and Java's&nbsp;<a href="https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)" target="_blank">indexOf()</a>.</p>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/implement-strstr/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
            int j = 0;
            for (; j < needle.size() && haystack[i + j] == needle[j]; ++j);
            if (j == needle.size()) return i;
        }
        return -1;
    }
};
```

## Solution 2. Rabin Karp

See [Rabin Karp Algorithm](https://github.com/lzl124631x/LeetCode/blob/master/notes/string/rabin-karp.md)

```cpp
// OJ: https://leetcode.com/problems/implement-strstr/
// Author: github.com/lzl124631x
// Time: average O(S+T), worst O(ST)
// Space: O(1)
class Solution {
    typedef long long LL;
public:
    int strStr(string s, string t) {
        int S = s.size(), T = t.size(), d = 128; 
        if (!S || !T || T > S) return T ? -1 : 0;
        LL m = 1e9+7, p = 1, hs = s[0], ht = t[0];
        for (int i = 1; i < T; ++i) {
            p = (p * d) % m; // we need d^(T-1)
            ht = (ht * d + t[i]) % m;
            hs = (hs * d + s[i]) % m;
        }
        for (int i = 0; i <= S - T; ++i) { // Loop for each start/pop point
            if (hs == ht) { // in case of collision, check the equity.
                int j = 0;
                for (; j < T && s[i + j] == t[j]; ++j);
                if (j == T) return i;
            }
            if (i < S - T) hs = ((hs - s[i] * p) * d + s[i + T]) % m;
            if (hs < 0) hs += m; // we might get negative hs, converting it to positive
        }
        return -1;
    }
};
```

## Solution 3. KMP

See [KMP Algorithm](https://github.com/lzl124631x/LeetCode/blob/master/notes/string/kmp.md)

```cpp
// OJ: https://leetcode.com/problems/implement-strstr/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(N)
class Solution {
    vector<int> getLps(string &s) {
        int N = s.size(), j = 0;
        vector<int> lps(N);
        for (int i = 1; i < N; ++i) {
            while (j > 0 && s[i] != s[j]) j = lps[j - 1];
            j += s[i] == s[j];
            lps[i] = j;
        }
        return lps;
    }
public:
    int strStr(string s, string t) {
        if (t.empty()) return 0;
        int M = s.size(), N = t.size(), i = 0, j = 0;
        auto lps = getLps(t);
        while (i < M) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            }
            if (j == N) return i - j;
            if (i < M && s[i] != t[j]) {
                if (j) j = lps[j - 1];
                else ++i;
            }
        }
        return -1;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/implement-strstr/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(N)
class Solution {
    vector<int> getLps(string &s) {
        int N = s.size(), j = -1;
        vector<int> lps(N + 1, -1);
        for (int i = 1; i <= N; ++i) {
            while (j >= 0 && s[i - 1] != s[j]) j = lps[j];
            lps[i] = ++j;
        }
        return lps;
    }
public:
    int strStr(string s, string t) {
        if (t.empty()) return 0;
        int M = s.size(), N = t.size(), i = 0, j = 0;
        auto lps = getLps(t);
        while (i < M) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            }
            if (j == N) return i - j;
            if (i < M && s[i] != t[j]) {
                if (j) j = lps[j];
                else ++i;
            }
        }
        return -1;
    }
};
```