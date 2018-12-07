# [678. Valid Parenthesis String (Medium)](https://leetcode.com/problems/valid-parenthesis-string/)

<p>
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
</p><ol>
<li>Any left parenthesis <code>'('</code> must have a corresponding right parenthesis <code>')'</code>.</li>
<li>Any right parenthesis <code>')'</code> must have a corresponding left parenthesis <code>'('</code>.</li>
<li>Left parenthesis <code>'('</code> must go before the corresponding right parenthesis <code>')'</code>.</li>
<li><code>'*'</code> could be treated as a single right parenthesis <code>')'</code> or a single left parenthesis <code>'('</code> or an empty string.</li>
<li>An empty string is also valid.</li>
</ol>
<p></p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "()"
<b>Output:</b> True
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "(*)"
<b>Output:</b> True
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> "(*))"
<b>Output:</b> True
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The string size will be in the range [1, 100].</li>
</ol>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Special Binary String (Hard)](https://leetcode.com/problems/special-binary-string/)

## Solution 1.

This solution is not performant if `s` contains lots of `"*"`.

```cpp
// OJ: https://leetcode.com/problems/valid-parenthesis-string/
// Author: github.com/lzl124631x
// Time: O(3^S) where S is the length of string s. In the worst case every character
//       is "*", so every step has 3 choices.
// Space: O(S)
class Solution {
private:
    bool dfs(string &s, int start, int leftParenCnt) {
        if (start == s.size()) return !leftParenCnt;
        if (s[start] == '(') {
            return dfs(s, start + 1, leftParenCnt + 1);
        } else if (s[start] == ')') {
            if (--leftParenCnt < 0) return false;
            return dfs(s, start + 1, leftParenCnt);
        } else {
            if (dfs(s, start + 1, leftParenCnt + 1)) return true;
            if (leftParenCnt >= 1 && dfs(s, start + 1, leftParenCnt - 1)) return true;
            return dfs(s, start + 1, leftParenCnt);
        }
    }
public:
    bool checkValidString(string s) {
        return dfs(s, 0, 0);
    }
};
```