# [1190. Reverse Substrings Between Each Pair of Parentheses (Medium)](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

<p>Given a string <code>s</code> that consists of lower case English letters and brackets.&nbsp;</p>

<p>Reverse the strings&nbsp;in each&nbsp;pair of matching parentheses, starting&nbsp;from the innermost one.</p>

<p>Your result should <strong>not</strong> contain any bracket.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(abcd)"
<strong>Output:</strong> "dcba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "(u(love)i)"
<strong>Output:</strong> "iloveu"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "(ed(et(oc))el)"
<strong>Output:</strong> "leetcode"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "a(bcdefghijkl(mno)p)q"
<strong>Output:</strong> "apmnolkjihgfedcbq"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> only contains lower case English characters and parentheses.</li>
	<li>It's guaranteed that all parentheses are balanced.</li>
</ul>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

## Solution 1. Recursive

We scan through the string. Once we see `(`, we go one layer deeper. Each layer returns once it see a `)` or end of string.

```cpp
// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
private:
    string helper(string &s, int &i) {
        string ans;
        int N = s.size();
        while (i < N) {
            while (i < N && s[i] != '(' && s[i] != ')') ans += s[i++];
            if (i >= N || s[i] == ')') break;
            ++i;
            string mid = helper(s, i);
            reverse(mid.begin(), mid.end());
            ans += mid;
            while (i < N && s[i] != ')') ans += s[i++];
            if (i >= N) break;
            ++i;
        }
        return ans;
    }
public:
    string reverseParentheses(string s) {
        int i = 0;
        return helper(s, i);
    }
};
```