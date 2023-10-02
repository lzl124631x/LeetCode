# [241. Different Ways to Add Parentheses (Medium)](https://leetcode.com/problems/different-ways-to-add-parentheses/)

<p>Given a string <code>expression</code> of numbers and operators, return <em>all possible results from computing all the different possible ways to group numbers and operators</em>. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> expression = "2-1-1"
<strong>Output:</strong> [0,2]
<strong>Explanation:</strong>
((2-1)-1) = 0 
(2-(1-1)) = 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> expression = "2*3-4*5"
<strong>Output:</strong> [-34,-14,-10,-10,10]
<strong>Explanation:</strong>
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 20</code></li>
	<li><code>expression</code> consists of digits and the operator <code>'+'</code>, <code>'-'</code>, and <code>'*'</code>.</li>
	<li>All the integer values in the input expression are in the range <code>[0, 99]</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Samsung](https://leetcode.com/company/samsung)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Recursion](https://leetcode.com/tag/recursion/), [Memoization](https://leetcode.com/tag/memoization/)

**Similar Questions**:
* [Unique Binary Search Trees II (Medium)](https://leetcode.com/problems/unique-binary-search-trees-ii/)
* [Basic Calculator (Hard)](https://leetcode.com/problems/basic-calculator/)
* [Expression Add Operators (Hard)](https://leetcode.com/problems/expression-add-operators/)
* [The Score of Students Solving Math Expression (Hard)](https://leetcode.com/problems/the-score-of-students-solving-math-expression/)

## Solution 1. Divide And Conquer (+ Memoization)

> Tip: find the pattern of the length of output given `N` operators in `input`.
> |0|1|2|3|4|...|
> |---|---|---|---|---|---|
> |1|1|2|5|14|...|
> 
> This is a Catalan Number Sequence. For this sequence, it's very likely that you can use "Divide and Conquer" -- separating the input as two parts, solve the subproblem of the smaller parts and merge them.

For each operator, use it to separate the expression into two parts. Compute the `diffWaysToCompute` for both the left and right parts, and merge the results.

We can optionally add memoization to avoid computing the same expression multiple times.

```cpp
// OJ: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author: github.com/lzl124631x
// Time: O(S * C(N))
//          where S is the length of `input`,
//          N is the count of operators in `input` and C(N) is the Nth Catalan Number
// Space: O(S * SUM( C(i) | 1 <= i <= N ))
class Solution {
    unordered_map<string, vector<int>> m;
public:
    vector<int> diffWaysToCompute(string s) {
        if (m.count(s)) return m[s];
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) continue;
            auto A = diffWaysToCompute(s.substr(0, i));
            auto B = diffWaysToCompute(s.substr(i + 1));
            for (int a : A) {
                for (int b : B) {
                    switch (s[i]) {
                        case '+': ans.push_back(a + b); break;
                        case '-': ans.push_back(a - b); break;
                        case '*': ans.push_back(a * b); break;
                    }
                }
            }
        }
        return m[s] = ans.size() ? ans : vector<int>{stoi(s)};
    }
};
```

## Discuss

https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/303491/C++-O(C(N))-Divide-and-Conquer-with-tipexplanation