# [1698. Number of Distinct Substrings in a String (Medium)](https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/)

<p>Given a string <code>s</code>, return <em>the number of <strong>distinct</strong> substrings of</em>&nbsp;<code>s</code>.</p>

<p>A <strong>substring</strong> of a string is obtained by deleting any number of characters (possibly zero) from the front of the string and any number (possibly zero) from the back of the string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aabbaba"
<strong>Output:</strong> 21
<strong>Explanation:</strong> The set of distinct strings is ["a","b","aa","bb","ab","ba","aab","abb","bab","bba","aba","aabb","abba","bbab","baba","aabba","abbab","bbaba","aabbab","abbaba","aabbaba"]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcdefg"
<strong>Output:</strong> 28
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Can you solve this problem in <code>O(n)</code> time complexity?

**Companies**:  
[Intuit](https://leetcode.com/company/intuit), [Dunzo](https://leetcode.com/company/dunzo)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Trie](https://leetcode.com/tag/trie/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Suffix Array](https://leetcode.com/tag/suffix-array/), [Hash Function](https://leetcode.com/tag/hash-function/)

## Solution 1. Rabin Karp

```cpp
// OJ: https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    int count(string &s, int len) {
        unsigned long long d = 1099511628211, h = 0, p = 1;
        unordered_set<unsigned long long> seen;
        for (int i = 0; i < s.size(); ++i) {
            h = h * d + s[i];
            if (i < len) p *= d;
            else h -= s[i - len] * p;
            if (i >= len - 1) seen.insert(h);
        }
        return seen.size();
    }
public:
    int countDistinct(string s) {
        int ans = 0;
        for (int len = 1; len <= s.size(); ++len) ans += count(s, len);
        return ans;
    }
};
```

## Solution 2. Rabin Karp with Prefix Hash Array

```cpp
// OJ: https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int countDistinct(string s) {
        unsigned long long d = 1099511628211, h[501] = {}, p[501] = {1}, N = s.size();
        for (int i = 0; i < N; ++i) {
            p[i + 1] = p[i] * d;
            h[i + 1] = h[i] * d + s[i];
        }
        unordered_set<unsigned long long> seen;
        for (int len = 1; len <= N; ++len) {
            for (int i = 0; i + len <= N; ++i) {
                seen.insert(h[i + len] - h[i] * p[len]);
            }
        }
        return seen.size();
    }
};
```