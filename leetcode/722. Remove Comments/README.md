# [722. Remove Comments (Medium)](https://leetcode.com/problems/remove-comments/)

<p>Given a C++ program, remove comments from it. The program source is an array of strings <code>source</code> where <code>source[i]</code> is the <code>i<sup>th</sup></code> line of the source code. This represents the result of splitting the original source code string by the newline character <code>'\n'</code>.</p>

<p>In C++, there are two types of comments, line comments, and block comments.</p>

<ul>
	<li>The string <code>"//"</code> denotes a line comment, which represents that it and the rest of the characters to the right of it in the same line should be ignored.</li>
	<li>The string <code>"/*"</code> denotes a block comment, which represents that all characters until the next (non-overlapping) occurrence of <code>"*/"</code> should be ignored. (Here, occurrences happen in reading order: line by line from left to right.) To be clear, the string <code>"/*/"</code> does not yet end the block comment, as the ending would be overlapping the beginning.</li>
</ul>

<p>The first effective comment takes precedence over others.</p>

<ul>
	<li>For example, if the string <code>"//"</code> occurs in a block comment, it is ignored.</li>
	<li>Similarly, if the string <code>"/*"</code> occurs in a line or block comment, it is also ignored.</li>
</ul>

<p>If a certain line of code is empty after removing comments, you must not output that line: each string in the answer list will be non-empty.</p>

<p>There will be no control characters, single quote, or double quote characters.</p>

<ul>
	<li>For example, <code>source = "string s = "/* Not a comment. */";"</code> will not be a test case.</li>
</ul>

<p>Also, nothing else such as defines or macros will interfere with the comments.</p>

<p>It is guaranteed that every open block comment will eventually be closed, so <code>"/*"</code> outside of a line or block comment always starts a new comment.</p>

<p>Finally, implicit newline characters can be deleted by block comments. Please see the examples below for details.</p>

<p>After removing the comments from the source code, return <em>the source code in the same format</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> source = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]
<strong>Output:</strong> ["int main()","{ ","  ","int a, b, c;","a = b + c;","}"]
<strong>Explanation:</strong> The line by line code is visualized as below:
/*Test program */
int main()
{ 
  // variable declaration 
int a, b, c;
/* This is a test
   multiline  
   comment for 
   testing */
a = b + c;
}
The string /* denotes a block comment, including line 1 and lines 6-9. The string // denotes line 4 as comments.
The line by line output code is visualized as below:
int main()
{ 
  
int a, b, c;
a = b + c;
}
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> source = ["a/*comment", "line", "more_comment*/b"]
<strong>Output:</strong> ["ab"]
<strong>Explanation:</strong> The original source string is "a/*comment\nline\nmore_comment*/b", where we have bolded the newline characters.  After deletion, the implicit newline characters are deleted, leaving the string "ab", which when delimited by newline characters becomes ["ab"].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= source.length &lt;= 100</code></li>
	<li><code>0 &lt;= source[i].length &lt;= 80</code></li>
	<li><code>source[i]</code> consists of printable <strong>ASCII</strong> characters.</li>
	<li>Every open block comment is eventually closed.</li>
	<li>There are no single-quote or&nbsp;double-quote in the input.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Mini Parser (Medium)](https://leetcode.com/problems/mini-parser/)
* [Ternary Expression Parser (Medium)](https://leetcode.com/problems/ternary-expression-parser/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-comments/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) excluding the space taken by the answer
class Solution {
    bool match(string &s, int start, string target) {
        return start + 2 <= s.size() && s[start] == target[0] && s[start + 1] == target[1];
    }
public:
    vector<string> removeComments(vector<string>& A) {
        vector<string> ans;
        bool block = false;
        for (int i = 0, N = A.size(); i < N; ++i) {
            int j = 0;
            if (!block) ans.emplace_back();
            while (j < A[i].size()) {
                if (block) {
                    if (match(A[i], j, "*/")) {
                        block = false;
                        j += 2;
                    } else ++j;
                } else if (match(A[i], j, "/*")) {
                    block = true;
                    j += 2;
                } else if (match(A[i], j, "//")) {
                    break;
                } else {
                    ans.back() += A[i][j++];
                }
            } 
            if (ans.back().empty()) ans.pop_back();
        }
        return ans;
    }
};
```