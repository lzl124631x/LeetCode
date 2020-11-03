# [1513. Number of Substrings With Only 1s (Medium)](https://leetcode.com/problems/number-of-substrings-with-only-1s/)

<p>Given a binary string&nbsp;<code>s</code>&nbsp;(a string consisting only of '0' and '1's).</p>

<p>Return the number of substrings with all characters 1's.</p>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo&nbsp;10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "0110111"
<strong>Output:</strong> 9
<strong>Explanation: </strong>There are 9 substring in total with only 1's characters.
"1" -&gt; 5 times.
"11" -&gt; 3 times.
"111" -&gt; 1 time.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "101"
<strong>Output:</strong> 2
<strong>Explanation: </strong>Substring "1" is shown 2 times in s.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "111111"
<strong>Output:</strong> 21
<strong>Explanation: </strong>Each substring contains only 1's characters.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "000"
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s[i] == '0'</code> or <code>s[i] == '1'</code></li>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

## Solution 1. Two pointers

Find all the strings formed with all ones. For a substring of length `len`, there are `total = 1 + 2 + ... + len = len * (len + 1) / 2` sub-substrings. The answer is the sum of all the `total`s mod by `1e9+7`.

Since the length of `s` is at most `1e5`, so `len * (len + 1)` is at most around `1e10` which is greater than what can be hold in a 32bit integer (`INT_MAX` is  `2,147,483,647 ~= 2e9`), so we use `long long` here.

```cpp
// OJ: https://leetcode.com/problems/number-of-substrings-with-only-1s/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSub(string s) {
        long long ans = 0, i = 0, N = s.size(), mod = 1e9+7;
        while (i < N) {
            while (i < N && s[i] == '0') ++i;
            long j = i;
            while (j < N && s[j] == '1') ++j;
            long len = j - i;
            ans = (ans + len * (len + 1) / 2 % mod) % mod;
            i = j;
        }
        return ans;
    }
};
```

## Solution 2. Count

```cpp
// OJ: https://leetcode.com/problems/number-of-substrings-with-only-1s/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSub(string s) {
        long ans = 0, cnt = 0, mod = 1e9+7;
        for (char c : s) {
            cnt = c == '1' ? 1 + cnt : 0;
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};
```