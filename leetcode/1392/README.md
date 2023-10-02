# [1392. Longest Happy Prefix (Hard)](https://leetcode.com/problems/longest-happy-prefix/)

<p>A string is called a&nbsp;<em>happy prefix</em>&nbsp;if is a <strong>non-empty</strong> prefix which is also a suffix (excluding itself).</p>

<p>Given a string <code>s</code>. Return the <strong>longest happy prefix</strong>&nbsp;of <code>s</code>&nbsp;.</p>

<p>Return an empty string if no such prefix exists.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "level"
<strong>Output:</strong> "l"
<strong>Explanation:</strong> s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "ababab"
<strong>Output:</strong> "abab"
<strong>Explanation:</strong> "abab" is the largest prefix which is also suffix. They can overlap in the original string.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "leetcodeleet"
<strong>Output:</strong> "leet"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "a"
<strong>Output:</strong> ""
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. Brute Force with string_view

```cpp
// OJ: https://leetcode.com/problems/longest-happy-prefix/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
        string longestPrefix(string s) {
        int n = s.size();
        string_view sv = s;
        for(int len = n-1; len>=1; len--){
            if (sv.substr(0, len) == sv.substr(n-len))
                return s.substr(0, len);
        }
        return "";
    }
};
```

## Solution 2. Rolling Hash

```cpp
// OJ: https://leetcode.com/problems/longest-happy-prefix/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/longest-happy-prefix/discuss/547446/C%2B%2BJava-with-picture-incremental-hash-and-DP
class Solution {
    typedef unsigned long long ULL;
public:
    string longestPrefix(string s) {
        ULL N = s.size(), len = 0, mod = 1e9+7, L = 0 , R = 0, mul = 1;
        for (int i = 0; i < N - 1; ++i) {
            L = (L * 26 + s[i] - 'a') % mod;
            R = (R + mul * (s[N - 1 - i] - 'a')) % mod;
            if (L == R) len = i + 1;
            mul = mul * 26 % mod;
        }
        return s.substr(0, len);
    }
};
```