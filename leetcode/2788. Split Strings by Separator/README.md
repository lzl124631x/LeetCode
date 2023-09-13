# [2788. Split Strings by Separator (Easy)](https://leetcode.com/problems/split-strings-by-separator)

<p>Given an array of strings <code>words</code> and a character <code>separator</code>, <strong>split</strong> each string in <code>words</code> by <code>separator</code>.</p>
<p>Return <em>an array of strings containing the new strings formed after the splits, <strong>excluding empty strings</strong>.</em></p>
<p><strong>Notes</strong></p>
<ul>
	<li><code>separator</code> is used to determine where the split should occur, but it is not included as part of the resulting strings.</li>
	<li>A split may result in more than two strings.</li>
	<li>The resulting strings must maintain the same order as they were initially given.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["one.two.three","four.five","six"], separator = "."
<strong>Output:</strong> ["one","two","three","four","five","six"]
<strong>Explanation: </strong>In this example we split as follows:

"one.two.three" splits into "one", "two", "three"
"four.five" splits into "four", "five"
"six" splits into "six" 

Hence, the resulting array is ["one","two","three","four","five","six"].</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["$easy$","$problem$"], separator = "$"
<strong>Output:</strong> ["easy","problem"]
<strong>Explanation:</strong> In this example we split as follows: 

"$easy$" splits into "easy" (excluding empty strings)
"$problem$" splits into "problem" (excluding empty strings)

Hence, the resulting array is ["easy","problem"].
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> words = ["|||"], separator = "|"
<strong>Output:</strong> []
<strong>Explanation:</strong> In this example the resulting split of "|||" will contain only empty strings, so we return an empty array []. </pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li>characters in <code>words[i]</code> are either lowercase English letters or characters from the string <code>".,|$#@"</code> (excluding the quotes)</li>
	<li><code>separator</code> is a character from the string <code>".,|$#@"</code> (excluding the quotes)</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Split a String in Balanced Strings (Easy)](https://leetcode.com/problems/split-a-string-in-balanced-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/split-strings-by-separator
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(W) where W is the maximum length of A[i]
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& A, char separator) {
        vector<string> ans;
        for (auto &s : A) {
            int start = 0, N = s.size();
            for (int i = 0; i <= N; ++i) {
                if (s[i] == separator || i == N) {
                    if (i - start > 0) ans.push_back(s.substr(start, i - start));
                    start = i + 1;
                }
            }
        }
        return ans;
    }
};
```