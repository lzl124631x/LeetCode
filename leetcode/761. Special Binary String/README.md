# [761. Special Binary String (Hard)](https://leetcode.com/problems/special-binary-string/)

<p><strong>Special binary strings</strong> are binary strings with the following two properties:</p>

<ul>
	<li>The number of <code>0</code>'s is equal to the number of <code>1</code>'s.</li>
	<li>Every prefix of the binary string has at least as many <code>1</code>'s as <code>0</code>'s.</li>
</ul>

<p>You are given a <strong>special binary</strong> string <code>s</code>.</p>

<p>A move consists of choosing two consecutive, non-empty, special substrings of <code>s</code>, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.</p>

<p>Return <em>the lexicographically largest resulting string possible after applying the mentioned operations on the string</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "11011000"
<strong>Output:</strong> "11100100"
<strong>Explanation:</strong> The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "10"
<strong>Output:</strong> "10"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>s</code> is a special binary string.</li>
</ul>


**Companies**:  
[Citrix](https://leetcode.com/company/citrix), [Visa](https://leetcode.com/company/visa), [Quip (Salesforce)](https://leetcode.com/company/quip), [Coursera](https://leetcode.com/company/coursera)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Valid Parenthesis String (Medium)](https://leetcode.com/problems/valid-parenthesis-string/)

## Solution 1. Recursion

```cpp
// OJ: https://leetcode.com/problems/special-binary-string/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/special-binary-string/solution/
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) return "";
        int N = s.size(), anchor = 0, cnt = 0;
        vector<string> v;
        for (int i = 0; i < N; ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                v.push_back("1" + makeLargestSpecial(s.substr(anchor + 1, i - anchor - 1)) + "0");
                anchor = i + 1;
            }
        }
        sort(begin(v), end(v), greater<>());
        string ans;
        for (auto &m : v) ans += m;
        return ans;
    }
};
```