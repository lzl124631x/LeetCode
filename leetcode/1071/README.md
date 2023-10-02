# [1071. Greatest Common Divisor of Strings (Easy)](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

<p>For two strings <code>s</code> and <code>t</code>, we say "<code>t</code> divides <code>s</code>" if and only if <code>s = t + ... + t</code>&nbsp; (<code>t</code> concatenated with itself 1 or more times)</p>

<p>Given two strings str1 and str2, return the largest string <code>x</code> such that <code>x</code> divides both&nbsp;<code><font face="monospace">str1</font></code>&nbsp;and <code><font face="monospace">str2</font></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> str1 = "ABCABC", str2 = "ABC"
<strong>Output:</strong> "ABC"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> str1 = "ABABAB", str2 = "ABAB"
<strong>Output:</strong> "AB"
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> str1 = "LEET", str2 = "CODE"
<strong>Output:</strong> ""
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> str1 = "ABCDEF", str2 = "ABC"
<strong>Output:</strong> ""
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= str1.length &lt;= 1000</code></li>
	<li><code>1 &lt;= str2.length &lt;= 1000</code></li>
	<li><code>str1</code>&nbsp;and <code>str2</code>&nbsp;consist of&nbsp;English uppercase letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Author: github.com/lzl124631x
// Time: O(S^2)
// Space: O(S)
class Solution {
private:
    bool divisible(string a, string b) {
        int i = 0, j = 0, M = a.size(), N = b.size();
        for (; i < M; ++i) {
            if (a[i] != b[j]) return false;
            if (++j == N) j = 0;
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string d = str1.size() < str2.size() ? str1 : str2;
        for (; d.size(); d.pop_back()) {
            if (str1.size() % d.size() || str2.size() % d.size()) continue;
            if (divisible(str1, d) && divisible(str2, d)) return d;
        }
        return d;
    }
};
```

## Solution 2. GCD

```cpp
// OJ: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Author: github.com/lzl124631x
// Time: O(SH) where S is string length and H is depth of recursion
// Space: O(SH)
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if (str2.empty()) return str1;
        auto d = str1.substr(0, str2.size());
        return d == str2 ? gcdOfStrings(str1.substr(str2.size()), str2) : "";
    }
};
```