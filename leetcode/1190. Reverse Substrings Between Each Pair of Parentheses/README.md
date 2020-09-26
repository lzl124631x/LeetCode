# [1190. Reverse Substrings Between Each Pair of Parentheses (Medium)](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

<p>Given a string <code>s</code> that consists of lower case English letters and brackets.&nbsp;</p>

<p>Reverse the strings&nbsp;in each&nbsp;pair of matching parentheses, starting&nbsp;from the innermost one.</p>

<p>Your result should <strong>not</strong> contain any bracket.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(abcd)"
<strong>Output:</strong> "dcba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "(u(love)i)"
<strong>Output:</strong> "iloveu"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "(ed(et(oc))el)"
<strong>Output:</strong> "leetcode"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "a(bcdefghijkl(mno)p)q"
<strong>Output:</strong> "apmnolkjihgfedcbq"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> only contains lower case English characters and parentheses.</li>
	<li>It's guaranteed that all parentheses are balanced.</li>
</ul>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

## Solution 1. Recursive

We scan through the string. Once we see `(`, we go one layer deeper. Each layer returns once it see a `)` or end of string.

```cpp
// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
private:
    string solve(string &s, int &i) {
        string ans;
        int N = s.size();
        while (i < N) {
            while (i < N && s[i] != '(' && s[i] != ')') ans += s[i++];
            if (i < N) ++i;
            if (i >= N || s[i - 1] == ')') break;
            auto mid = solve(s, i);
            reverse(mid.begin(), mid.end());
            ans += mid;
        }
        return ans;
    }
public:
    string reverseParentheses(string s) {
        int i = 0;
        return solve(s, i);
    }
};
```

## Solution 2. 

There is a pattern in the reversed string. For each pair of parenthesis, when we see `'('` or `')'`, we jump to the corresponding `')'` or `'('` and toggle the direction we scan.

Example:

```
   1   2    3   4
   v   v    v   v
a  ( b ( cd ) e ) f
```

* We scan rightwards initially. `ans = a`
* When we meet the parenthesis `1` from left to right, we jump to its corresponding parenthesis `4` and toggle the direction to be leftwards. `ans = ae`
* When we meet the parenthesis `3` from right to left, we jump to its corresponding parenthesis `2` and toggle direction to be rightwards. `ans = aecd`
* When we meet the parenthesis `3` from left to right, we jump to `2` and toggle direction to be leftwards. `ans = aecdb`.
* When we meet the parenthesis `1` from right to left, we jump to `4` and toggle direction to be rightwards. `ans = aecdbf`.
* We've reached the end. The answer is `aecdbf`.

```cpp
// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(P) where P is the number of pairs of parenthesis in `s`.
// Ref: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/discuss/383670/JavaC%2B%2BPython-Why-not-O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        unordered_map<int, int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                m[i] = st.top();
                m[st.top()] = i;
                st.pop();
            }
        }
        string ans;
        for (int i = 0, d = 1; i < s.size(); i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = m[i];
                d = -d;
            } else ans += s[i];
        }
        return ans;
    }
};
```