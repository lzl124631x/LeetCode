# [770. Basic Calculator IV (Hard)](https://leetcode.com/problems/basic-calculator-iv/)

<p>Given an <code>expression</code>&nbsp;such as <code>expression = "e + 8 - a + 5"</code> and an evaluation map such as <code>{"e": 1}</code> (given in terms of <code>evalvars = ["e"]</code> and <code>evalints = [1]</code>), return a list of tokens representing the simplified expression, such as <code>["-1*a","14"]</code></p>

<ul>
	<li>An expression alternates chunks and symbols, with a space separating each chunk and symbol.</li>
	<li>A chunk is either an expression in parentheses, a variable, or a non-negative integer.</li>
	<li>A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like <code>"2x"</code> or <code>"-x"</code>.</li>
</ul>

<p>Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction. For example, <code>expression = "1 + 2 * 3"</code> has an answer of <code>["7"]</code>.</p>

<p>The format of the output is as follows:</p>

<ul>
	<li>For each term of free variables with non-zero coefficient, we write the free variables within a term in sorted order lexicographically. For example, we would never write a term like <code>"b*a*c"</code>, only <code>"a*b*c"</code>.</li>
	<li>Terms have degree equal to the number of free variables being multiplied, counting multiplicity. (For example, <code>"a*a*b*c"</code> has degree 4.) We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.</li>
	<li>The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.)&nbsp; A leading coefficient of 1 is still printed.</li>
	<li>An example of a well formatted answer is <code>["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"]</code>&nbsp;</li>
	<li>Terms (including constant terms) with coefficient 0 are not included.&nbsp; For example, an expression of "0" has an output of [].</li>
</ul>

<p><strong>Examples:</strong></p>

<pre><strong>Input:</strong> expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
<strong>Output:</strong> ["-1*a","14"]

<strong>Input:</strong> expression = "e - 8 + temperature - pressure",
evalvars = ["e", "temperature"], evalints = [1, 12]
<strong>Output:</strong> ["-1*pressure","5"]

<strong>Input:</strong> expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
<strong>Output:</strong> ["1*e*e","-64"]

<strong>Input:</strong> expression = "7 - 7", evalvars = [], evalints = []
<strong>Output:</strong> []

<strong>Input:</strong> expression = "a * b * c + b * a * c * 4", evalvars = [], evalints = []
<strong>Output:</strong> ["5*a*b*c"]

<strong>Input:</strong> expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))",
evalvars = [], evalints = []
<strong>Output:</strong> ["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c","-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c","2*b*b*c*c","-1*b*c*c*c","2*a*a*b","-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c","1*b*c*c","-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>expression</code> will have length in range <code>[1, 250]</code>.</li>
	<li><code>evalvars, evalints</code> will have equal lengths in range <code>[0, 100]</code>.</li>
</ol>


**Companies**:  
[Intuit](https://leetcode.com/company/intuit), [Pinterest](https://leetcode.com/company/pinterest), [Roblox](https://leetcode.com/company/roblox)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Parse Lisp Expression (Hard)](https://leetcode.com/problems/parse-lisp-expression/)
* [Basic Calculator III (Hard)](https://leetcode.com/problems/basic-calculator-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/basic-calculator-iv
// Author: github.com/lzl124631x
class Solution {
private:
    vector<string> tokenize(string &expression) {
        vector<string> tokens;
        for (int i = 0; i < expression.size();) {
            string token;
            if (isalnum(expression[i])) {
                while (i < expression.size() && isalnum(expression[i])) {
                    token += expression[i++];
                }
            } else token += expression[i++];
            tokens.push_back(token);
            while (i < expression.size() && expression[i] == ' ') ++i;
        }
        return tokens;
    }
    vector<string> inject(vector<string> &tokens, unordered_map<string, string> &m) {
        for (auto &token : tokens) {
            if (m.find(token) != m.end()) token = m[token];
        }
        return tokens;
    }
    vector<string> toRPN(vector<string> &tokens) {
        stack<string> ops;
        vector<string> ans;
        for (auto &token : tokens) {
            switch(token.back()) {
                case '+':
                case '-':
                    while (ops.size() && ops.top() != "(") {
                        ans.push_back(ops.top());
                        ops.pop();
                    }
                    ops.push(token);
                    break;
                case '*':
                    if (ops.size() && ops.top() == "*") {
                        ans.push_back(ops.top());
                        ops.pop();
                    }
                    ops.push(token);
                    break;
                case '(':
                    ops.push(token);
                    break;
                case ')':
                    while (ops.size() && ops.top() != "(") {
                        ans.push_back(ops.top());
                        ops.pop();
                    }
                    if (ops.size()) ops.pop();
                    break;
                default:
                    ans.push_back(token);
                    break;
            }
        }
        while (ops.size()) {
            ans.push_back(ops.top());
            ops.pop();
        }
        return ans;
    }
    vector<string> splitSymbols(string exp) {
        istringstream s(exp);
        vector<string> ans;
        string symbol;
        while (getline(s, symbol, '*')) ans.push_back(symbol);
        return ans;
    }
    vector<string> evaluate(vector<string> &tokens) {
        stack<map<string, int>> s;
        for (auto &token : tokens) {
            switch(token.back()) {
                case '+':
                case '-': {
                    int sign = token[0] == '+' ? 1 : -1;
                    auto b = s.top(); s.pop();
                    auto a = s.top(); s.pop();
                    map<string, int> m;
                    for (auto &p : a) {
                        m[p.first] += p.second;
                    }
                    for (auto &p : b) {
                        m[p.first] += sign * p.second;
                    }
                    s.push(m);
                    break;
                }
                case '*': {
                    auto b = s.top(); s.pop();
                    auto a = s.top(); s.pop();
                    map<string, int> m;
                    for (auto &p : a) {
                        auto symbol1 = splitSymbols(p.first);
                        for (auto &q : b) {
                            istringstream sb(q.first);
                            auto symbol2 = splitSymbols(q.first);
                            string symbol;
                            if (symbol1.size() == 1 && symbol1[0] == "1") {
                                symbol = q.first;
                            } else if (symbol2.size() == 1 && symbol2[0] == "1") {
                                symbol = p.first;
                            } else {
                                for (int i = 0, j = 0; i < symbol1.size() || j < symbol2.size();) {
                                    if (symbol.size()) symbol += "*";
                                    if (i >= symbol1.size()) {
                                        symbol += symbol2[j++];
                                    } else if (j >= symbol2.size()) {
                                        symbol += symbol1[i++];
                                    } else if (symbol1[i] < symbol2[j]){
                                        symbol += symbol1[i++];
                                    } else {
                                        symbol += symbol2[j++];
                                    }
                                }
                            }
                            m[symbol] += p.second * q.second;
                        }
                    }
                    s.push(m);
                    break;
                }
                default: {
                    map<string, int> m;
                    if (isdigit(token.back())) {
                        m["1"] = stoi(token);
                    } else {
                        m[token] = 1;
                    }
                    s.push(m);
                    break;
                }
            }
        }
        vector<string> ans;
        for (auto &p : s.top()) {
            if (!p.second) continue;
            ans.push_back(to_string(p.second) + (p.first == "1" ? "" : "*" + p.first));
        }
        stable_sort(ans.begin(), ans.end(), [&](string a, string b) {
            return count(a.begin(), a.end(), '*') > count(b.begin(), b.end(), '*');
        });
        return ans;
    }
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, string> m;
        for (int i = 0; i < evalvars.size(); ++i) {
            m[evalvars[i]] = to_string(evalints[i]);
        }
        auto tokens = tokenize(expression);
        tokens = inject(tokens, m);
        tokens = toRPN(tokens);
        tokens = evaluate(tokens);
        return tokens;
    }
};
```