# [1249. Minimum Remove to Make Valid Parentheses (Medium)](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)

<p>Given a string <font face="monospace">s</font> of <code>'('</code> , <code>')'</code> and lowercase English characters.</p>

<p>Your task is to remove the minimum number of parentheses ( <code>'('</code> or <code>')'</code>, in any positions ) so that the resulting <em>parentheses string</em> is valid and return <strong>any</strong> valid string.</p>

<p>Formally, a <em>parentheses string</em> is valid if and only if:</p>

<ul>
	<li>It is the empty string, contains only lowercase characters, or</li>
	<li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are valid strings, or</li>
	<li>It can be written as <code>(A)</code>, where <code>A</code> is a valid string.</li>
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

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either<code>'('</code> , <code>')'</code>, or lowercase English letter<code>.</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Amazon](https://leetcode.com/company/amazon), [tiktok](https://leetcode.com/company/tiktok), [Microsoft](https://leetcode.com/company/microsoft), [Snapchat](https://leetcode.com/company/snapchat)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Minimum Number of Swaps to Make the String Balanced (Medium)](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)
* [Check if a Parentheses String Can Be Valid (Medium)](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)

## Solution 1. Scan Left to Right then Right to Left

```cpp
// OJ: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) if changing input string is allowed; otherwise O(N)
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
// Space: O(1) if changing input string is allowed; otherwise O(N)
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