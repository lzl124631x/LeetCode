# [171. Excel Sheet Column Number (Easy)](https://leetcode.com/problems/excel-sheet-column-number/)

<p>Given a string <code>columnTitle</code> that represents the column title as appear in an Excel sheet, return <em>its corresponding column number</em>.</p>

<p>For example:</p>

<pre>A -&gt; 1
B -&gt; 2
C -&gt; 3
...
Z -&gt; 26
AA -&gt; 27
AB -&gt; 28 
...
</pre>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> columnTitle = "A"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> columnTitle = "AB"
<strong>Output:</strong> 28
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> columnTitle = "ZY"
<strong>Output:</strong> 701
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= columnTitle.length &lt;= 7</code></li>
	<li><code>columnTitle</code> consists only of uppercase English letters.</li>
	<li><code>columnTitle</code> is in the range <code>["A", "FXSHRXW"]</code>.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Excel Sheet Column Title (Easy)](https://leetcode.com/problems/excel-sheet-column-title/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/excel-sheet-column-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (char c : s) ans = ans * 26 + (c - 'A' + 1);
        return ans;
    }
};
```

Or one liner

```cpp
// OJ: https://leetcode.com/problems/excel-sheet-column-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int titleToNumber(string s) { 
        return accumulate(s.begin(), s.end(), 0, [](int num, char ch) { return num * 26 + (ch - 'A' + 1); }); 
    }
};
```