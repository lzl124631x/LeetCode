# [1249. Minimum Remove to Make Valid Parentheses (Medium)](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)

<p>Given a string <font face="monospace">s</font>&nbsp;of&nbsp;<code>'('</code>&nbsp;,&nbsp;<code>')'</code>&nbsp;and lowercase English characters.&nbsp;</p>

<p>Your task is to remove the minimum number of parentheses (&nbsp;<code>'('</code>&nbsp;or&nbsp;<code>')'</code>,&nbsp;in any positions ) so that the resulting <em>parentheses string</em> is valid and return <strong>any</strong> valid string.</p>

<p>Formally, a <em>parentheses string</em> is valid if and only if:</p>

<ul>
	<li>It is the empty string, contains only lowercase characters, or</li>
	<li>It can be written as&nbsp;<code>AB</code>&nbsp;(<code>A</code>&nbsp;concatenated with&nbsp;<code>B</code>), where&nbsp;<code>A</code>&nbsp;and&nbsp;<code>B</code>&nbsp;are valid strings, or</li>
	<li>It can be written as&nbsp;<code>(A)</code>, where&nbsp;<code>A</code>&nbsp;is a valid string.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "lee(t(c)o)de)"
<strong>Output:</strong> "lee(t(c)o)de"
<strong>Explanation:</strong> "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "a)b(c)d"
<strong>Output:</strong> "ab(c)d"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "))(("
<strong>Output:</strong> ""
<strong>Explanation:</strong> An empty string is also valid.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "(a(b(c)d)"
<strong>Output:</strong> "a(b(c)d)"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s[i]</code>&nbsp;is one&nbsp;of&nbsp;&nbsp;<code>'('</code> , <code>')'</code> and&nbsp;lowercase English letters<code>.</code></li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1. Scan Left to Right then Right to Left

```cpp
// OJ: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int j = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') ++left;
            else if (s[i] == ')') {
                if (left == 0) continue;
                --left;
            }
            s[j++] = s[i];
        }
        s.resize(j);
        reverse(begin(s), end(s));
        j = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') ++left;
            else if (s[i] == '(') {
                if (left == 0) continue;
                --left;
            }
            s[j++] = s[i];
        }
        s.resize(j);
        reverse(begin(s), end(s));
        return s;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            if (isalpha(s[i])) continue;
            if (s[i] == '(') ++left;
            else if (left) --left;
            else s[i] = ' ';
        }
        left = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (isalpha(s[i]) || s[i] == ' ') continue;
            if (s[i] == ')') ++left;
            else if (left) --left;
            else s[i] = ' ';
        }
        s.erase(remove(begin(s), end(s), ' '), end(s));
        return s;
    }
};
```

## Solution 2. Stack

```cpp
// OJ: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (st.empty()) s[i] = ' ';
                else st.pop();
            }
        }
        while (st.size()) {
            s[st.top()] = ' ';
            st.pop();
        }
        s.erase(remove(begin(s), end(s), ' '), end(s));
        return s;
    }
};
```