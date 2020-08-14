# [301. Remove Invalid Parentheses (Hard)](https://leetcode.com/problems/remove-invalid-parentheses/)

<p>Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.</p>

<p><strong>Note:</strong>&nbsp;The input string may contain letters other than the parentheses <code>(</code> and <code>)</code>.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> "()())()"
<b>Output:</b> ["()()()", "(())()"]
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> "(a)())()"
<b>Output:</b> ["(a)()()", "(a())()"]
</pre>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> ")("
<b>Output: </b>[""]
</pre>

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Valid Parentheses (Easy)](https://leetcode.com/problems/valid-parentheses/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/remove-invalid-parentheses/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
    unordered_set<string> ans;
    string tmp;
    int totalLeft = 0, totalRight = 0;
    void dfs(string &s, int i, int invalidLeft, int invalidRight, int visitedLeft, int visitedRight, int curLeft, int curRight) {
        if (curRight > curLeft) return;
        if (i == s.size()) {
            if (curLeft != curRight) return;
            ans.insert(tmp);
            return;
        }
        if ((s[i] != '(' && s[i] != ')')
            || (s[i] == '(' && invalidLeft == 0)
            || (s[i] == ')' && invalidRight == 0)) {
            tmp.push_back(s[i]);
            dfs(s, i + 1, invalidLeft, invalidRight, visitedLeft + (s[i] == '('), visitedRight + (s[i] == ')'), curLeft + (s[i] == '('), curRight + (s[i] == ')') );
            tmp.pop_back();
            return;
        }
        if (s[i] == '(') {
            if (totalLeft - visitedLeft >= invalidLeft) dfs(s, i + 1, invalidLeft - 1, invalidRight, visitedLeft + 1, visitedRight, curLeft, curRight);
            tmp.push_back(s[i]);
            dfs(s, i + 1, invalidLeft, invalidRight, visitedLeft + 1, visitedRight, curLeft + 1, curRight);
            tmp.pop_back();
        } else {
            if (totalRight - visitedRight >= invalidRight) dfs(s, i + 1, invalidLeft, invalidRight - 1, visitedLeft, visitedRight + 1, curLeft, curRight);
            tmp.push_back(s[i]);
            dfs(s, i + 1, invalidLeft, invalidRight, visitedLeft, visitedRight + 1, curLeft, curRight + 1);
            tmp.pop_back();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c != '(' && c != ')') continue;
            totalLeft += c == '(';
            totalRight += c == ')';
            if (c == '(') ++left;
            else if (!left) ++right;
            else --left;
        }
        if (s.size() == left + right) return {""};
        dfs(s, 0, left, right, 0, 0, 0, 0);
        return vector<string>(begin(ans), end(ans));
    }
};
```