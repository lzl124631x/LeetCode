# [1071. Greatest Common Divisor of Strings (Easy)](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

<p>For strings <code>S</code> and <code>T</code>, we say "<code>T</code> divides <code>S</code>" if and only if <code>S = T + ... + T</code>&nbsp; (<code>T</code> concatenated with itself 1 or more times)</p>

<p>Return the largest string <code>X</code> such that <code>X</code> divides <font face="monospace">str1</font>&nbsp;and <code>X</code> divides <font face="monospace">str2</font>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>str1 = <span id="example-input-1-1">"ABCABC"</span>, str2 = <span id="example-input-1-2">"ABC"</span>
<strong>Output: </strong><span id="example-output-1">"ABC"</span>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>str1 = <span id="example-input-2-1">"ABABAB"</span>, str2 = <span id="example-input-2-2">"ABAB"</span>
<strong>Output: </strong><span id="example-output-2">"AB"</span>
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>str1 = <span id="example-input-3-1">"LEET"</span>, str2 = <span id="example-input-3-2">"CODE"</span>
<strong>Output: </strong><span id="example-output-3">""</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= str1.length &lt;= 1000</code></li>
	<li><code>1 &lt;= str2.length &lt;= 1000</code></li>
	<li><code>str1[i]</code> and <code>str2[i]</code> are English uppercase letters.</li>
</ol>

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