# [736. Parse Lisp Expression (Hard)](https://leetcode.com/problems/parse-lisp-expression/)

<p>You are given a string expression representing a Lisp-like expression to return the integer value of.</p>

<p>The syntax for these expressions is given as follows.</p>

<ul>
	<li>An expression is either an integer, let expression, add expression, mult expression, or an assigned variable. Expressions always evaluate to a single integer.</li>
	<li>(An integer could be positive or negative.)</li>
	<li>A let expression takes the form <code>"(let v<sub>1</sub> e<sub>1</sub> v<sub>2</sub> e<sub>2</sub> ... v<sub>n</sub> e<sub>n</sub> expr)"</code>, where let is always the string <code>"let"</code>, then there are one or more pairs of alternating variables and expressions, meaning that the first variable <code>v<sub>1</sub></code> is assigned the value of the expression <code>e<sub>1</sub></code>, the second variable <code>v<sub>2</sub></code> is assigned the value of the expression <code>e<sub>2</sub></code>, and so on sequentially; and then the value of this let expression is the value of the expression <code>expr</code>.</li>
	<li>An add expression takes the form <code>"(add e<sub>1</sub> e<sub>2</sub>)"</code> where add is always the string <code>"add"</code>, there are always two expressions <code>e<sub>1</sub></code>, <code>e<sub>2</sub></code> and the result is the addition of the evaluation of <code>e<sub>1</sub></code> and the evaluation of <code>e<sub>2</sub></code>.</li>
	<li>A mult expression takes the form <code>"(mult e<sub>1</sub> e<sub>2</sub>)"</code> where mult is always the string <code>"mult"</code>, there are always two expressions <code>e<sub>1</sub></code>, <code>e<sub>2</sub></code> and the result is the multiplication of the evaluation of e1 and the evaluation of e2.</li>
	<li>For this question, we will use a smaller subset of variable names. A variable starts with a lowercase letter, then zero or more lowercase letters or digits. Additionally, for your convenience, the names <code>"add"</code>, <code>"let"</code>, and <code>"mult"</code> are protected and will never be used as variable names.</li>
	<li>Finally, there is the concept of scope. When an expression of a variable name is evaluated, within the context of that evaluation, the innermost scope (in terms of parentheses) is checked first for the value of that variable, and then outer scopes are checked sequentially. It is guaranteed that every expression is legal. Please see the examples for more details on the scope.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))"
<strong>Output:</strong> 14
<strong>Explanation:</strong> In the expression (add x y), when checking for the value of the variable x,
we check from the innermost scope to the outermost in the context of the variable we are trying to evaluate.
Since x = 3 is found first, the value of x is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> expression = "(let x 3 x 2 x)"
<strong>Output:</strong> 2
<strong>Explanation:</strong> Assignment in let statements is processed sequentially.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> expression = "(let x 1 y 2 x (add x y) (add x y))"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The first (add x y) evaluates as 3, and is assigned to x.
The second (add x y) evaluates as 3+2 = 5.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> expression = "(let x 2 (add (let x 3 (let x 4 x)) x))"
<strong>Output:</strong> 6
<strong>Explanation:</strong> Even though (let x 4 x) has a deeper scope, it is outside the context
of the final x in the add-expression.  That final x will equal 2.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> expression = "(let a1 3 b2 (add a1 1) b2)"
<strong>Output:</strong> 4
<strong>Explanation:</strong> Variable names can contain digits after the first character.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 2000</code></li>
	<li>There are no leading or trailing spaces in <code>exprssion</code>.</li>
	<li>All tokens are separated by a single space in <code>expressoin</code>.</li>
	<li>The answer and all intermediate calculations of that answer are guaranteed to fit in a <strong>32-bit</strong> integer.</li>
	<li>The expression is guaranteed to be legal and evaluate to an integer.</li>
</ul>


**Companies**:  
[Snapchat](https://leetcode.com/company/snapchat)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Ternary Expression Parser (Medium)](https://leetcode.com/problems/ternary-expression-parser/)
* [Number of Atoms (Hard)](https://leetcode.com/problems/number-of-atoms/)
* [Basic Calculator IV (Hard)](https://leetcode.com/problems/basic-calculator-iv/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/parse-lisp-expression/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
struct Token;
struct Expression {
    vector<Token> tokens;
};
struct Token {
    int type = -1; // 0 plaintext, 1 expression
    string text;
    Expression *exp;
    Token (Expression *exp) : type(1), exp(exp) {}
    Token (string text) : type(0), text(text) {}
};
class Solution {
    Expression *parse(string &s) {
        int i = 0, N = s.size();
        stack<Expression*> exps;
        exps.push(new Expression());
        while (i < N) {
            if (s[i] == ' ') ++i;
            else if (s[i] == '(') {
                auto &prev = exps.top();
                exps.push(new Expression());
                prev->tokens.emplace_back(exps.top());
                string op;
                ++i;
                if (s[i] == 'l') op = "let", i += 4;
                else if (s[i] == 'm') op = "mult", i += 5;
                else if (s[i] == 'a') op = "add", i += 4;
                exps.top()->tokens.push_back(op);
            } else if (s[i] == ')') exps.pop(), ++i;
            else {
                string text;
                while (s[i] != '(' && s[i] != ')' && s[i] != ' ') text += s[i++];
                exps.top()->tokens.emplace_back(text);
            }
        }
        return exps.top()->tokens[0].exp; 
    }
    int evalToken(const Token &token, unordered_map<string, int> &ctx) {
        if (token.type == 1) return eval(token.exp, ctx);
        if (ctx.count(token.text)) return ctx[token.text];
        return stoi(token.text);
    }
    int eval(const Expression *exp, unordered_map<string, int> ctx = {}) {
        auto &tokens = exp->tokens;
        if (tokens.size() == 1) return stoi(tokens[0].text);
        int ans = 0, N = tokens.size();
        string op = tokens[0].text;
        if (op == "let") {
            unordered_map<string, int> m = ctx;
            for (int i = 1; i + 1 < N; i += 2) {
                string var = tokens[i].text;
                if (tokens[i + 1].type == 1) m[var] = eval(tokens[i + 1].exp, m);
                else m[var] = evalToken(tokens[i + 1], m);
            }
            return evalToken(tokens.back(), m);
        } else if (op == "add") {
            return evalToken(tokens[1], ctx) + evalToken(tokens[2], ctx);
        } else {
            return evalToken(tokens[1], ctx) * evalToken(tokens[2], ctx);
        }
        return ans;
    }
public:
    int evaluate(string s) {
        if (s[0] != '(') return stoi(s);
        return eval(parse(s));
    }
};
```