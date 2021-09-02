# [5. Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)

<p>Given a string <code>s</code>, return&nbsp;<em>the longest palindromic substring</em> in <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "babad"
<strong>Output:</strong> "bab"
<strong>Note:</strong> "aba" is also a valid answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "cbbd"
<strong>Output:</strong> "bb"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "a"
<strong>Output:</strong> "a"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "ac"
<strong>Output:</strong> "a"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consist of only digits and English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Wayfair](https://leetcode.com/company/wayfair), [Facebook](https://leetcode.com/company/facebook), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Oracle](https://leetcode.com/company/oracle), [Yahoo](https://leetcode.com/company/yahoo), [Google](https://leetcode.com/company/google), [Docusign](https://leetcode.com/company/docusign), [eBay](https://leetcode.com/company/ebay), [Uber](https://leetcode.com/company/uber), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Salesforce](https://leetcode.com/company/salesforce), [Zoho](https://leetcode.com/company/zoho), [HBO](https://leetcode.com/company/hbo), [Tesla](https://leetcode.com/company/tesla)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Shortest Palindrome (Hard)](https://leetcode.com/problems/shortest-palindrome/)
* [Palindrome Permutation (Easy)](https://leetcode.com/problems/palindrome-permutation/)
* [Palindrome Pairs (Hard)](https://leetcode.com/problems/palindrome-pairs/)
* [Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)
* [Palindromic Substrings (Medium)](https://leetcode.com/problems/palindromic-substrings/)

## Solution 1. DP

Let `dp[i][j]` be `true` if `s[i..j]` is a palindrome. The answer is the substring of the longest length that has `dp[i][j] = true`.

```
dp[i][j] = true 
dp[i][j] = s[i] == s[j] && (i+1 > j-1 || dp[i+1][j-1])
```

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-substring/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size(), start = 0, len = 0;
        bool dp[1001][1001] = {};
        for (int i = N - 1; i >= 0; --i) {
            for (int j = i; j < N; ++j) {
                if (i == j) dp[i][j] = true;
                else dp[i][j] = s[i] == s[j] && (i + 1 > j - 1 || dp[i + 1][j - 1]);
                if (dp[i][j] && j - i + 1 > len) {
                    start = i;
                    len = j - i + 1;
                }
            }
        }
        return s.substr(start, len);
    }
};
```

Since `dp[i][j]` only depends on `dp[i + 1][j - 1]`, we can reduce the space complexity from `O(N^2)` to `O(N)`.

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-substring/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size(), start = 0, len = 0;
        bool dp[1001] = {};
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= i; --j) {
                if (i == j) dp[j] = true;
                else dp[j] = s[i] == s[j] && (i + 1 > j - 1 || dp[j - 1]);
                if (dp[j] && j - i + 1 > len) {
                    start = i;
                    len = j - i + 1;
                }
            }
        }
        return s.substr(start, len);
    }
};
```


## Solution 2. Expanding from Middle

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-substring/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    int expand(string &s, int L, int R) {
        while (L >= 0 && R < s.size() && s[L] == s[R]) --L, ++R;
        return R - L - 1;
    }
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expand(s, i, i), len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};
```

## Solution 3. Manacher

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        string t = "^*";
        for (char c : s) {
            t += c;
            t += '*';
        }
        t += '$'; // inflating the `s` ( example: "abc" becomes "^*a*b*c*$" )
        int M = t.size();
        
        vector<int> r(M); // `r[i]` is the number of palindromes with `t[i]` as the center (aka. the radius of the longest palindrome centered at `t[i]`)
        r[1] = 1;
        int j = 1; // `j` is the index with the furthest reach `j + r[j]`
        for (int i = 2; i <= 2 * N; ++i) {
            int cur = j + r[j] > i ? min(r[2 * j - i], j + r[j] - i) : 1; // `t[2*j-i]` is the symmetry point to `t[i]`
            while (t[i - cur] == t[i + cur]) ++cur; // expanding the current radius
            if (i + cur > j + r[j]) j = i;
            r[i] = cur;
        }
        
        int len = 1, start = 0;
        for (int i = 2; i <= 2 * N; ++i) {
            if (r[i] - 1 > len) {
                len = r[i] - 1;
                start = (i - r[i]) / 2;
            }
        }
        return s.substr(start, len);
    }
};
```