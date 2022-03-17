# [856. Score of Parentheses (Medium)](https://leetcode.com/problems/score-of-parentheses/)

<p>Given a balanced parentheses string <code>s</code>, return <em>the <strong>score</strong> of the string</em>.</p>

<p>The <strong>score</strong> of a balanced parentheses string is based on the following rule:</p>

<ul>
	<li><code>"()"</code> has score <code>1</code>.</li>
	<li><code>AB</code> has score <code>A + B</code>, where <code>A</code> and <code>B</code> are balanced parentheses strings.</li>
	<li><code>(A)</code> has score <code>2 * A</code>, where <code>A</code> is a balanced parentheses string.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "()"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "(())"
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "()()"
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 50</code></li>
	<li><code>s</code> consists of only <code>'('</code> and <code>')'</code>.</li>
	<li><code>s</code> is a balanced parentheses string.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1. Divide and Conquer

```cpp
// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int scoreOfParentheses(string S) {
        if (S == "()") return 1;
        int i = 0, left = 0;
        do {
            left += S[i++] == '(' ? 1 : -1;
        } while (left);
        if (i == S.size()) return 2 * scoreOfParentheses(S.substr(1, S.size() - 2));
        return scoreOfParentheses(S.substr(0, i)) + scoreOfParentheses(S.substr(i));
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    int score(string &S, int begin, int end) {
        if (begin + 2 == end) return 1;
        int i = begin, left = 0;
        do {
            left += S[i++] == '(' ? 1 : -1;
        } while (left);
        if (i == end) return 2 * score(S, begin + 1, end - 1);
        return score(S, begin, i) + score(S, i, end);
    }
public:
    int scoreOfParentheses(string S) {
        return score(S, 0, S.size());
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/score-of-parentheses/solution/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int i = 0, N = s.size();
        function<int()> dfs = [&]() {
            int ans = 0;
            while (i < N && s[i] == '(') {
                if (s[i + 1] == ')') {
                    ans++;
                    i += 2;
                } else {
                    ++i;
                    ans += 2 * dfs();
                    ++i;
                }
            }
            return ans;
        };
        return dfs();
    }
};
```

## Soltuion 3. Stack

```cpp
// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st{{0}};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                if (s[i + 1] == ')') {
                    ++i;
                    st.top()++;
                } else st.push(0);
            } else {
                int val = 2 * st.top();
                st.pop();
                st.top() += val;
            }
        }
        return st.top();
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st{{0}};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(0);
            else {
                int val = max(2 * st.top(), 1);
                st.pop();
                st.top() += val;
            }
        }
        return st.top();
    }
};
```

## Solution 4.

We only add to the answer when we see `()`. Assume it's at `depth` depth, we add `2^depth` to the answer.

```cpp
// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/score-of-parentheses/solution/
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, depth = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                if (s[i + 1] == ')') ans += (1 << depth), ++i;
                else ++depth;
            } else --depth;
        }
        return ans;
    }
};
```