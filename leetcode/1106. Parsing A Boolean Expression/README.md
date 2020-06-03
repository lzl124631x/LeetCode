# [1106. Parsing A Boolean Expression (Hard)](https://leetcode.com/problems/parsing-a-boolean-expression/)

<p>Return the result of evaluating a given boolean <code>expression</code>, represented as a string.</p>

<p>An expression can either be:</p>

<ul>
	<li><code>"t"</code>, evaluating to <code>True</code>;</li>
	<li><code>"f"</code>, evaluating to <code>False</code>;</li>
	<li><code>"!(expr)"</code>, evaluating to the logical NOT of the inner expression <code>expr</code>;</li>
	<li><code>"&amp;(expr1,expr2,...)"</code>, evaluating to the logical AND of 2 or more inner expressions <code>expr1, expr2, ...</code>;</li>
	<li><code>"|(expr1,expr2,...)"</code>, evaluating to the logical OR of 2 or more inner expressions <code>expr1, expr2, ...</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> expression = "!(f)"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> expression = "|(f,t)"
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> expression = "&amp;(t,f)"
<strong>Output:</strong> false
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> expression = "|(&amp;(t,f,t),!(t))"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 20000</code></li>
	<li><code>expression[i]</code>&nbsp;consists of characters in <code>{'(', ')', '&amp;', '|', '!', 't', 'f', ','}</code>.</li>
	<li><code>expression</code> is a valid expression representing a boolean, as given in the description.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/parsing-a-boolean-expression/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H) where H is the maximum depth of the expression
class Solution {
    int i = 0;
    bool dfs(string &s) {
        if (s[i] == 't' || s[i] == 'f') return s[i++] == 't';
        char op = s[i++];
        ++i; // (
        bool ans;
        if (op == '!') ans = !dfs(s);
        else {
            ans = op == '&';
            while (s[i] != ')') {
                if (s[i] == ',') ++i;
                if (op == '&') ans = dfs(s) && ans;
                else ans = dfs(s) || ans;
            }
        }
        ++i; // )
        return ans;
    }
public:
    bool parseBoolExpr(string s) {
        return dfs(s);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/parsing-a-boolean-expression/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H) where H is the maximum depth of the expression
class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> op;
        stack<bool> ans;
        int i = 0, N = s.size();
        while (i < N) {
            if (s[i] == 't' || s[i] == 'f') ans.push(s[i++] == 't');
            else if (s[i] == '!' || s[i] == '&' || s[i] == '|') {
                op.push(s[i]);
                if (s[i] != '!') ans.push(op.top() == '&');
                i += 2;
            } else if (s[i] == ',' || s[i] == ')') {
                if (op.top() == '&' || op.top() == '|') {
                    bool val = ans.top();
                    ans.pop();
                    if (op.top() == '&') ans.top() = ans.top() && val;
                    else ans.top() = ans.top() || val;
                } else ans.top() = !ans.top();
                if (s[i] == ')') op.pop();
                ++i;
            }
        }
        return ans.top();
    }
};
```