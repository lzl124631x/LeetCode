# [22. Generate Parentheses (Medium)](https://leetcode.com/problems/generate-parentheses/)

<p>
Given <i>n</i> pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
</p>

<p>
For example, given <i>n</i> = 3, a solution set is:
</p>
<pre>[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
</pre>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber), [Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Yandex](https://leetcode.com/company/yandex)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1. DFS

Let's try to generate the valid parentheses.

Starting from empty string, we have two options in each step:

* insert '(' if we still have '(' available
* insert ')' if there are more ')' available than '('

We keep doing this until there is no '(' and ')' available.

```cpp
// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: github.com/lzl124631x
// Time: O(C(N)) where C(N) is the Nth Catalan number
// Space: O(N)
class Solution {
private:
    vector<string> ans;
    void generate(int leftCnt, int rightCnt, string &s) {
        if (!leftCnt && !rightCnt) {
            ans.push_back(s);
            return;
        }
        if (leftCnt) {
            s.push_back('(');
            generate(leftCnt - 1, rightCnt, s);
            s.pop_back();
        }
        if (rightCnt > leftCnt) {
            s.push_back(')');
            generate(leftCnt, rightCnt - 1, s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(n, n, s);
        return ans;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: github.com/lzl124631x
// Time: O(C(N)) where C(N) is the Nth Catalan number
// Space: O(N)
class Solution {
private:
    vector<string> ans;
    void generate(int leftCnt, int rightCnt, int i, string &s) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        if (leftCnt) {
            s[i] = '(';
            generate(leftCnt - 1, rightCnt, i + 1, s);
        }
        if (rightCnt > leftCnt) {
            s[i] = ')';
            generate(leftCnt, rightCnt - 1, i + 1, s);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s(2 * n, '\0');
        generate(n, n, 0, s);
        return ans;
    }
};
```

## Solution 3.

The idea is that we can generate all the strings given the result of `n - 1` by inserting `()` into the strings.

For example, for `n = 2`, the result is
```
()()
(())
```

We try inserting `()` into each of them

```
()() -> ()()() 0
     -> (())() 1
     -> ()(()) 2
     -> ()()() 3
     -> ()()() 4

(()) -> ()(()) 0
     -> (()()) 1
     -> ((())) 2
     -> (()()) 3
     -> (())() 4
```

And we use `unordered_set` to deduplicate.

```cpp
// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2 * C(N)) where C(N) is the Nth Catalan number
// Space: O(C(N))
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return { "" };
        auto prev = generateParenthesis(n - 1);
        unordered_set<string> s;
        for (int i = 0; i < prev.size(); ++i) {
            for (int j = 0; j < 2 * n - 1; ++j) {
                s.insert(prev[i].substr(0, j) + "()" + prev[i].substr(j));
            }
        }
        return vector<string>(s.begin(), s.end());
    }
};
```