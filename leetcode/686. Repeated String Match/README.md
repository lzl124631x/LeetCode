# [686. Repeated String Match (Medium)](https://leetcode.com/problems/repeated-string-match/)

<p>Given two strings&nbsp;<code>a</code> and <code>b</code>, return the minimum number of times you should repeat string&nbsp;<code>a</code>&nbsp;so that string&nbsp;<code>b</code>&nbsp;is a substring of it. If it is&nbsp;impossible for&nbsp;<code>b</code>​​​​​​ to be a substring of&nbsp;<code>a</code> after repeating it, return&nbsp;<code>-1</code>.</p>

<p><strong>Notice:</strong>&nbsp;string&nbsp;<code>"abc"</code>&nbsp;repeated 0 times is&nbsp;<code>""</code>,&nbsp; repeated 1 time is&nbsp;<code>"abc"</code>&nbsp;and repeated 2 times is&nbsp;<code>"abcabc"</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> a = "abcd", b = "cdabcdab"
<strong>Output:</strong> 3
<strong>Explanation:</strong> We return 3 because by repeating a three times "ab<strong>cdabcdab</strong>cd", b is a substring of it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> a = "a", b = "aa"
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> a = "a", b = "a"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> a = "abc", b = "wxyz"
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= b.length &lt;= 10<sup>4</sup></code></li>
	<li><code>a</code>&nbsp;and&nbsp;<code>b</code>&nbsp;consist of lower-case English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Repeated Substring Pattern (Easy)](https://leetcode.com/problems/repeated-substring-pattern/)

## Solution 1.

We try to see if `A * k` contains `B` where `k` is the answer. So we keep concatenating `a` to an empty string `s` until `s` is not shorter than `b`. Assume we repeated `a` `k` times.

* If `s` contains `b`, then return `k`.
* Otherwise, if `s + a` contains `b`, return `k + 1`.
* Otherwise, return `-1`.

```cpp
// OJ: https://leetcode.com/problems/repeated-string-match/
// Author: github.com/lzl124631x
// Time: O(B * (A + B))
// Space: O(A + B)
// Ref: https://leetcode.com/problems/repeated-string-match/solution/
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int k = 1;
        string s = a;
        for (; s.size() < b.size(); ++k) s += a;
        if (s.find(b) != string::npos) return k;
        return (s + a).find(b) != string::npos ? k + 1 : -1;
    }
};
```

## Solution 2. Rabin-Karp

We keep finding `B` in repeated `A` string using Rabin-Karp algorithm (or Rolling Hash).

```cpp
// OJ: https://leetcode.com/problems/repeated-string-match/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
    unsigned prime = 16777619;
    bool equal(string &a, string &b, unsigned offset) {
        for (int i = 0; i < b.size(); ++i) {
            if (a[(i + offset) % a.size()] != b[i]) return false;
        }
        return true;
    }
    pair<unsigned, unsigned> hashStr(string &s) {
        unsigned h = 0, p = 1, sq = prime;
        for (char c : s) h = h * prime + c;
        for (int i = s.size(); i > 0; i >>= 1) {
            if (i & 1) p *= sq;
            sq *= sq;
        }
        return { h, p };
    }
public:
    int repeatedStringMatch(string a, string b) {
        auto [hb, p] = hashStr(b);
        unsigned A = a.size(), B = b.size(), ha = 0, i = 0;
        for (; i < B; ++i) ha = ha * prime + a[i % A];
        if (ha == hb && equal(a, b, 0)) return (i + A - 1) / A;
        while (i < 2 * A + B) {
            ha = ha * prime + a[i % A] - p * a[(i - B) % A];
            ++i;
            if (ha == hb && equal(a, b, (i - B) % A)) return (i + A - 1) / A;
        }
        return -1;
    }
};
```
