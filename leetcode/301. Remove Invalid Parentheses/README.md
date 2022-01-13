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
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Valid Parentheses (Easy)](https://leetcode.com/problems/valid-parentheses/)
* [Minimum Number of Swaps to Make the String Balanced (Medium)](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)

## Solution 1. Backtracking

1. Count the number of invalid left and right parenthesis.
2. Use an `unordered_set` to keep track of the answers.
3. Use backtracking to build the answer.
4. Use `balance` to keep track of the number of `(` minus number of `)` in the `tmp` string. `balance` is always `>= 0`.

```cpp
// OJ: https://leetcode.com/problems/remove-invalid-parentheses/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c != '(' && c != ')') continue;
            left += c == '(' ? 1 : -1;
            if (left < 0) left = 0, ++right;
        }
        unordered_set<string> ans;
        string tmp;
        function<void(int, int, int, int)> dfs = [&](int i, int balance, int left, int right) {
            if (i == s.size()) {
                if (balance == 0) ans.insert(tmp); // add `tmp` to answer if we reached the end and the string is balanced.
                return;
            }
            if (s[i] == '(') {
                if (left) dfs(i + 1, balance, left - 1, right); // If there are still invalid left parenthesis, skip this `(`
                tmp.push_back('('); // don't skip this `(`
                dfs(i + 1, balance + 1, left, right);
                tmp.pop_back();
            } else if (s[i] == ')') {
                if (right) dfs(i + 1, balance, left, right - 1); // If there are still invalid right parenthesis, skip this `)`
                if (balance > 0) { // don't skip this `)` if it won't result in negative balance -- the current balance > 0
                    tmp.push_back(')');
                    dfs(i + 1, balance - 1, left, right);
                    tmp.pop_back();
                }
            } else { // For other characters, always append
                tmp.push_back(s[i]);
                dfs(i + 1, balance, left, right);
                tmp.pop_back();
            }
        };
        dfs(0, 0, left, right);
        return vector<string>(begin(ans), end(ans));
    }
};
```

## Solution 2. Backtracking

In Solution 1, we might get some unbalanced `tmp` string when `i == s.size()` meaning that we didn't skip all impossible cases as early as possible.

Assume we have `remainingLeft` `(`s to scan and `invalidLeft` `(`s to remove. `remainingLeft >= invalidLeft`

If `remainingLeft == invalidLeft`, we must remove `(`. Otherwise (`remainingLeft > invalidLeft`), we can either remove it or keep it.

`(` is removable: `invalidLeft > 0` and the number of remaining `(` is greater than what we need, i.e. `remainingLeft > remainingRight - invalidRight - balance`

`(` is keepable: `remainingLeft > invalidLeft`.

```cpp
// OJ: https://leetcode.com/problems/remove-invalid-parentheses/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0, totalLeft = 0, totalRight = 0;
        for (char c : s) {
            if (c != '(' && c != ')') continue;
            left += c == '(' ? 1 : -1;
            totalLeft += c == '(';
            totalRight += c == ')';
            if (left < 0) left = 0, ++right;
        }
        if (s.size() == left + right) return {""};
        unordered_set<string> ans;
        string tmp;
        function<void(int, int, int, int, int, int)> dfs = [&](int i, int balance, int invalidLeft, int invalidRight, int remainingLeft, int remainingRight) {
            if (i == s.size()) {
                ans.insert(tmp);
                return;
            }
            if (s[i] == '(') {
                if (invalidLeft > 0 && remainingLeft > remainingRight - invalidRight - balance) dfs(i + 1, balance, invalidLeft - 1, invalidRight, remainingLeft - 1, remainingRight); // If there are still invalid left parenthesis, skip this `(`
                if (remainingLeft > invalidLeft) { // we can only keep this `(` if `remainingLeft > invalidLeft`. If `remainingLeft == invalidLeft`, we can only skip.
                    tmp.push_back('('); // don't skip this `(`
                    dfs(i + 1, balance + 1, invalidLeft, invalidRight, remainingLeft - 1, remainingRight);
                    tmp.pop_back();
                }
            } else if (s[i] == ')') {
                if (invalidRight > 0 && remainingRight > remainingLeft - invalidLeft + balance) dfs(i + 1, balance, invalidLeft, invalidRight - 1, remainingLeft, remainingRight - 1); // If there are still invalid right parenthesis, skip this `)`
                if (balance > 0 && remainingRight > invalidRight) { // don't skip this `)` if it won't result in negative balance -- the current balance > 0
                    tmp.push_back(')');
                    dfs(i + 1, balance - 1, invalidLeft, invalidRight, remainingLeft, remainingRight - 1);
                    tmp.pop_back();
                }
            } else { // For other characters, always append
                tmp.push_back(s[i]);
                dfs(i + 1, balance, invalidLeft, invalidRight, remainingLeft, remainingRight);
                tmp.pop_back();
            }
        };
        dfs(0, 0, left, right, totalLeft, totalRight);
        return vector<string>(begin(ans), end(ans));
    }
};
```

## Solution 3. Backtracking

```cpp
// OJ: https://leetcode.com/problems/remove-invalid-parentheses/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int N = s.size();
        vector<int> right(N + 1);
        for (int i = N - 1; i >= 0; --i) right[i] = max(0, right[i + 1] + (s[i] == '(' || s[i] == ')' ? (s[i] == ')' ? 1 : -1) : 0));
        unordered_set<string> ans;
        string tmp;
        function<void(int, int)> dfs = [&](int i, int left) {
            if (i == N) {
                if (left == 0) ans.insert(tmp);
                return;
            }
            if (s[i] == '(') {
                if (left + 1 > right[i + 1]) { // we can remove this '('
                    dfs(i + 1, left);
                }
                ++left;
            } else if (s[i] == ')') {
                if (right[i] > left) { // we can remove this ')'
                    dfs(i + 1, left);
                }
                if (left > 0) {
                    --left;
                } else return;
            } 
            tmp.push_back(s[i]);
            dfs(i + 1, left);
            tmp.pop_back();
        };
        dfs(0, 0);
        return vector<string>(begin(ans), end(ans));
    }
};
```