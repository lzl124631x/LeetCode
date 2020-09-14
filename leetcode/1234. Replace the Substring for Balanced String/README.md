# [1234. Replace the Substring for Balanced String (Medium)](https://leetcode.com/problems/replace-the-substring-for-balanced-string/)

<p>You are given a string containing only 4&nbsp;kinds of characters <code>'Q',</code> <code>'W', 'E'</code> and&nbsp;<code>'R'</code>.</p>

<p>A string is said to be&nbsp;<strong>balanced</strong><em>&nbsp;</em>if each of its characters appears&nbsp;<code>n/4</code> times where <code>n</code> is the length of the string.</p>

<p>Return the minimum length of the substring that can be replaced with <strong>any</strong> other string of the same length to make the original string <code>s</code>&nbsp;<strong>balanced</strong>.</p>

<p>Return 0 if the string is already <strong>balanced</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "QWER"
<strong>Output:</strong> 0
<strong>Explanation: </strong>s is already balanced.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "QQWE"
<strong>Output:</strong> 1
<strong>Explanation: </strong>We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "QQQW"
<strong>Output:</strong> 2
<strong>Explanation: </strong>We can replace the first "QQ" to "ER". 
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "QQQQ"
<strong>Output:</strong> 3
<strong>Explanation: </strong>We can replace the last 3 'Q' to make s = "QWER".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s.length</code> is a multiple of <code>4</code></li>
	<li><code>s&nbsp;</code>contains only <code>'Q'</code>, <code>'W'</code>, <code>'E'</code> and&nbsp;<code>'R'</code>.</li>
</ul>


**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

## Solution 1. Sliding Window

Count the frequency of each characters. Those characters with frequency greater than `N / 4` must be replaced. Find the minimum window which covers those characters that should be replaced.

```cpp
// OJ: https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int balancedString(string s) {
        int N = s.size(), ans = N, i = 0, j = 0, replace = 0;
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        for (auto &[c, cnt] : m) {
            if ((m[c] = max(0, cnt - N / 4)) > 0) ++replace;
        }
        if (replace == 0) return 0;
        while (j < N) {
            replace -= --m[s[j++]] == 0;
            while (replace <= 0) {
                ans = min(ans, j - i);
                replace += m[s[i++]]++ == 0;
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/replace-the-substring-for-balanced-string/discuss/408978/JavaC%2B%2BPython-Sliding-Window
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> m;
        int N = s.size(), ans = N, i = 0, k = N / 4;
        for (char c : s) ++m[c];
        for (int j = 0; j < N; ++j) {
            --m[s[j]];
            while (i < N && m['Q'] <= k && m['W'] <= k && m['E'] <= k && m['R'] <= k) {
                ans = min(ans, j - i + 1);
                ++m[s[i++]];
            }
        }
        return ans;
    }
};
```