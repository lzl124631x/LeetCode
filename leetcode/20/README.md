# [20. Valid Parentheses (Easy)](https://leetcode.com/problems/valid-parentheses/)

<p>Given a string <code>s</code> containing just the characters <code>'('</code>, <code>')'</code>, <code>'{'</code>, <code>'}'</code>, <code>'['</code> and <code>']'</code>, determine if the input string is valid.</p>

<p>An input string is valid if:</p>

<ol>
	<li>Open brackets must be closed by the same type of brackets.</li>
	<li>Open brackets must be closed in the correct order.</li>
</ol>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "()"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "()[]{}"
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "(]"
<strong>Output:</strong> false
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "([)]"
<strong>Output:</strong> false
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "{[]}"
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of parentheses only <code>'()[]{}'</code>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Generate Parentheses (Medium)](https://leetcode.com/problems/generate-parentheses/)
* [Longest Valid Parentheses (Hard)](https://leetcode.com/problems/longest-valid-parentheses/)
* [Remove Invalid Parentheses (Hard)](https://leetcode.com/problems/remove-invalid-parentheses/)
* [Check If Word Is Valid After Substitutions (Medium)](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            else if (stk.empty() || (c == ')' && stk.top() != '(') || (c == '}' && stk.top() != '{')
                || (c == ']' && stk.top() != '[')) return false;
            else stk.pop();
        }
        return stk.empty();
    }
};
```