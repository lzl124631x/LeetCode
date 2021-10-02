# [301. Remove Invalid Parentheses (Hard)](https://leetcode.com/problems/remove-invalid-parentheses/)

<p>Given a string <code>s</code> that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.</p>

<p>Return <em>all the possible results</em>. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "()())()"
<strong>Output:</strong> ["(())()","()()()"]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "(a)())()"
<strong>Output:</strong> ["(a())()","(a)()()"]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = ")("
<strong>Output:</strong> [""]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 25</code></li>
	<li><code>s</code> consists of lowercase English letters and parentheses <code>'('</code> and <code>')'</code>.</li>
	<li>There will be at most <code>20</code> parentheses in <code>s</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Valid Parentheses (Easy)](https://leetcode.com/problems/valid-parentheses/)
* [Minimum Number of Swaps to Make the String Balanced (Medium)](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)

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

## Solution 2. Backtracking

```cpp
// OJ: https://leetcode.com/problems/remove-invalid-parentheses/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
    int N;
    vector<int> right;
    unordered_set<string> ans;
    string tmp;
    void dfs(string &s, int i, int left) {
        if (i == N) {
            if (left == 0) ans.insert(tmp);
            return;
        }
        if (s[i] == '(') {
            if (left + 1 > right[i + 1]) { // we can remove this '('
                dfs(s, i + 1, left);
            }
            ++left;
        } else if (s[i] == ')') {
            if (right[i] > left) { // we can remove this ')'
                dfs(s, i + 1, left);
            }
            if (left > 0) {
                --left;
            } else return;
        } 
        tmp.push_back(s[i]);
        dfs(s, i + 1, left);
        tmp.pop_back();
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        N = s.size();
        right.assign(N + 1, 0);
        for (int i = N - 1; i >= 0; --i) right[i] = max(0, right[i + 1] + (s[i] == '(' || s[i] == ')' ? (s[i] == ')' ? 1 : -1) : 0));
        dfs(s, 0, 0);
        return vector<string>(begin(ans), end(ans));
    }
};
```