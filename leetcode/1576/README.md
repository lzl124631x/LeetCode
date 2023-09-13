# [1576. Replace All ?'s to Avoid Consecutive Repeating Characters (Easy)](https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/)

<p>Given a string&nbsp;<code>s</code><var>&nbsp;</var>containing only lower case English letters&nbsp;and the '?'&nbsp;character, convert <strong>all </strong>the '?' characters into lower case letters such that the final string does not contain any <strong>consecutive repeating&nbsp;</strong>characters.&nbsp;You <strong>cannot </strong>modify the non '?' characters.</p>

<p>It is <strong>guaranteed </strong>that there are no consecutive repeating characters in the given string <strong>except </strong>for '?'.</p>

<p>Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them.&nbsp;It can be shown that an answer is always possible with the given constraints.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "?zs"
<strong>Output:</strong> "azs"
<strong>Explanation</strong>: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "ubv?w"
<strong>Output:</strong> "ubvaw"
<strong>Explanation</strong>: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "j?qg??b"
<strong>Output:</strong> "jaqgacb"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "??yw?ipkj?"
<strong>Output:</strong> "acywaipkja"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>
	<p><code>1 &lt;= s.length&nbsp;&lt;= 100</code></p>
	</li>
	<li>
	<p><code>s</code> contains&nbsp;only lower case English letters and '?'.</p>
	</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

When we see a `s[i] == '?'`, we set it as `s[i - 1] + 1` and round it to `'a'` if necessary.

When `s[i] == '?' && s[i + 1] != '?'`, there is a chance of conflict with `s[i + 1]`. If there is a conflict, we simply increment and round `s[i]` again.

```cpp
// OJ: https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string modifyString(string s) {
        int i = 0, N = s.size();
        while (i < N) {
            while (i < N && s[i] != '?') ++i;
            int c = (i == 0 ? 0 : (s[i - 1] - 'a' + 1) % 26);
            while (i < N && s[i] == '?') {
                s[i] = c + 'a';
                c = (c + 1) % 26;
                if (i + 1 < N && s[i + 1] != '?' && s[i] == s[i + 1]) s[i] = c + 'a';
            }
        }
        return s;
    }
};
```