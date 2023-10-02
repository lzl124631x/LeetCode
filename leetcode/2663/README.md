# [2663. Lexicographically Smallest Beautiful String (Hard)](https://leetcode.com/problems/lexicographically-smallest-beautiful-string)

<p>A string is <strong>beautiful</strong> if:</p>
<ul>
	<li>It consists of the first <code>k</code> letters of the English lowercase alphabet.</li>
	<li>It does not contain any substring of length <code>2</code> or more which is a palindrome.</li>
</ul>
<p>You are given a beautiful string <code>s</code> of length <code>n</code> and a positive integer <code>k</code>.</p>
<p>Return <em>the lexicographically smallest string of length </em><code>n</code><em>, which is larger than </em><code>s</code><em> and is <strong>beautiful</strong></em>. If there is no such string, return an empty string.</p>
<p>A string <code>a</code> is lexicographically larger than a string <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, <code>a</code> has a character strictly larger than the corresponding character in <code>b</code>.</p>
<ul>
	<li>For example, <code>"abcd"</code> is lexicographically larger than <code>"abcc"</code> because the first position they differ is at the fourth character, and <code>d</code> is greater than <code>c</code>.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abcz", k = 26
<strong>Output:</strong> "abda"
<strong>Explanation:</strong> The string "abda" is beautiful and lexicographically larger than the string "abcz".
It can be proven that there is no string that is lexicographically larger than the string "abcz", beautiful, and lexicographically smaller than the string "abda".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "dc", k = 4
<strong>Output:</strong> ""
<strong>Explanation:</strong> It can be proven that there is no string that is lexicographically larger than the string "dc" and is beautiful.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n == s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>4 &lt;= k &lt;= 26</code></li>
	<li><code>s</code> is a beautiful string.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Smallest String With Swaps (Medium)](https://leetcode.com/problems/smallest-string-with-swaps/)
* [Find Palindrome With Fixed Length (Medium)](https://leetcode.com/problems/find-palindrome-with-fixed-length/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/lexicographically-smallest-beautiful-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int N = s.size(), changed = false;
        function<bool(int)> dfs = [&](int i) {
            if (i == N) return true;
            char mn = changed ? 'a' : (s[i] + (i == N - 1)), init = s[i];
            for (char c = mn; c <= 'a' + k - 1; ++c) {
                if ((i - 1 >= 0 && s[i - 1] == c) || (i - 2 >= 0 && s[i - 2] == c)) continue;
                changed |= init != c;
                s[i] = c;
                if (dfs(i + 1)) return true;
            }
            return false;
        };
        return dfs(0) ? s : "";
    }
};
```

## Solution 2. Greedy

```cpp
// OJ: https://leetcode.com/problems/lexicographically-smallest-beautiful-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) if changing in-place in `s` is allowed; otherwise O(N)
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int N = s.size();
        auto valid = [&](int i) {
            return (i - 1 < 0 || s[i] != s[i - 1]) && (i - 2 < 0 || s[i] != s[i - 2]);
        };
        for (int i = N - 1; i >= 0; --i) {
            ++s[i];
            while (!valid(i)) ++s[i];
            if (s[i] < 'a' + k) {
                for (++i; i < N; ++i) {
                    for (s[i] = 'a'; !valid(i); ++s[i]);
                }
                return s;
            }
        };
        return "";
    }
};
```