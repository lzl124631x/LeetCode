# [1790. Check if One String Swap Can Make Strings Equal (Easy)](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)

<p>You are given two strings <code>s1</code> and <code>s2</code> of equal length. A <strong>string swap</strong> is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.</p>

<p>Return <code>true</code> <em>if it is possible to make both strings equal by performing <strong>at most one string swap </strong>on <strong>exactly one</strong> of the strings. </em>Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "bank", s2 = "kanb"
<strong>Output:</strong> true
<strong>Explanation:</strong> For example, swap the first character with the last character of s2 to make "bank".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "attack", s2 = "defend"
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to make them equal with one string swap.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s1 = "kelb", s2 = "kelb"
<strong>Output:</strong> true
<strong>Explanation:</strong> The two strings are already equal, so no string swap operation is required.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s1 = "abcd", s2 = "dcba"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 100</code></li>
	<li><code>s1.length == s2.length</code></li>
	<li><code>s1</code> and <code>s2</code> consist of only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Buddy Strings (Easy)](https://leetcode.com/problems/buddy-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool areAlmostEqual(string a, string b) {
        int cnt[26] = {}, diff = 0;
        for (char c : a) cnt[c - 'a'] ++;
        for (char c : b) cnt[c - 'a']--;
        for (int n : cnt) {
            if (n) return false;
        }
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++diff;
        }
        return diff == 0 || diff == 2;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool areAlmostEqual(string a, string b) {
        int x = -1, y = -1;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) continue;
            if (x == -1) x = i;
            else if (y == -1) y = i;
            else return false;
        }
        return (x == -1 && y == -1) || (y != -1 && a[x] == b[y] && a[y] == b[x]);
    }
};
```