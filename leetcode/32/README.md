# [32. Longest Valid Parentheses (Hard)](https://leetcode.com/problems/longest-valid-parentheses/)

<p>Given a string containing just the characters <code>'('</code> and <code>')'</code>, find the length of the longest valid (well-formed) parentheses substring.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> "(()"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest valid parentheses substring is <code>"()"</code>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> "<code>)()())</code>"
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest valid parentheses substring is <code>"()()"</code>
</pre>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Valid Parentheses (Easy)](https://leetcode.com/problems/valid-parentheses/)

## Solution 1. DP

Let `dp[i + 1]` be the length of the longest valid parentheses ending at `s[i]`.

When `s[i] == ')'`:
```
dp[i + 1] = dp[i] + 2 + dp[start]   If s[start] == '('
          = 0                       If s[start] != '('
          where start = i - dp[i] - 1
```

When `s[i] == '('`:
```
dp[i + 1] = 0
```

Trivial case:
```
dp[0] = 0
```

The answer is the max value in `dp` array.

```cpp
// OJ: https://leetcode.com/problems/longest-valid-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size() + 1, 0);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') continue;
            int start = i - dp[i] - 1;
            if (start >= 0 && s[start] == '(')
                dp[i + 1] = dp[i] + 2 + dp[start];
            ans = max(ans, dp[i + 1]);
        }
        return ans;
    }
};
```

## Solution 2. Stack

We try to leave invalid parentheses in the stack `st`.

* If `s[i] == '('`, we push it into stack
* If `s[i] == ')'`:
  * If `s[st.top()] == '('`, then `st.top()` is a valid left parenthesis, we pop it. The length of the parenthesis string we just formed is `i - st.top()`.
  * otherwise, this `s[i]` can't form a valid parenthesis. Push it into stack.

```cpp
// OJ: https://leetcode.com/problems/longest-valid-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' && st.top() != -1 && s[st.top()] == '(') {
                st.pop();
                ans = max(ans, i - st.top());
            } else st.push(i);
        }
        return ans;
    }
};
```

## Solution 3. Counters

```cpp
// OJ: https://leetcode.com/problems/longest-valid-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/longest-valid-parentheses/solution/
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            left += s[i] == '(';
            right += s[i] == ')';
            if (left == right) ans = max(ans, left + right);
            else if (right > left) left = right = 0;
        }
        left = 0, right = 0;
        for (int i = N - 1; i >= 0; --i) {
            left += s[i] == '(';
            right += s[i] == ')';
            if (left == right) ans = max(ans, left + right);
            else if (left > right) left = right = 0;
        }
        return ans;
    }
};
```