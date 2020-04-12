# [1410. HTML Entity Parser (Medium)](https://leetcode.com/problems/html-entity-parser/)

<p><strong>HTML entity parser</strong> is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.</p>

<p>The special characters and their entities for HTML are:</p>

<ul>
	<li><strong>Quotation Mark:</strong>&nbsp;the entity is <code>&amp;quot;</code> and&nbsp;symbol character is <code>"</code>.</li>
	<li><strong>Single Quote&nbsp;Mark:</strong>&nbsp;the entity is <code>&amp;apos;</code> and&nbsp;symbol character is <code>'</code>.</li>
	<li><strong>Ampersand:</strong>&nbsp;the entity is <code>&amp;amp;</code> and symbol character is <code>&amp;</code>.</li>
	<li><strong>Greater Than Sign:</strong>&nbsp;the entity is <code>&amp;gt;</code>&nbsp;and symbol character is <code>&gt;</code>.</li>
	<li><strong>Less Than Sign:</strong>&nbsp;the entity is <code>&amp;lt;</code>&nbsp;and symbol character is <code>&lt;</code>.</li>
	<li><strong>Slash:</strong>&nbsp;the entity is <code>&amp;frasl;</code> and&nbsp;symbol character is <code>/</code>.</li>
</ul>

<p>Given the input <code>text</code> string to the HTML parser, you have to implement the entity parser.</p>

<p>Return <em>the text</em> after replacing the entities by the special characters.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text = "&amp;amp; is an HTML entity but &amp;ambassador; is not."
<strong>Output:</strong> "&amp; is an HTML entity but &amp;ambassador; is not."
<strong>Explanation:</strong> The parser will replace the &amp;amp; entity by &amp;
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text = "and I quote: &amp;quot;...&amp;quot;"
<strong>Output:</strong> "and I quote: \"...\""
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> text = "Stay home! Practice on Leetcode :)"
<strong>Output:</strong> "Stay home! Practice on Leetcode :)"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> text = "x &amp;gt; y &amp;amp;&amp;amp; x &amp;lt; y is always false"
<strong>Output:</strong> "x &gt; y &amp;&amp; x &lt; y is always false"
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> text = "leetcode.com&amp;frasl;problemset&amp;frasl;all"
<strong>Output:</strong> "leetcode.com/problemset/all"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10^5</code></li>
	<li>The string may contain any possible characters out of all the 256&nbsp;ASCII characters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1. Brute force

Once found a `&`, read the string from `&` to `;` into `entity`. If `entity` is a known html entity, append the corresponding symbol to the result; otherwise, append the `entity` to the result.

```cpp
// OJ: https://leetcode.com/problems/html-entity-parser/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string entityParser(string s) {
        int N = s.size(), i = 0;
        string ans;
        while (i < N) {
            if (s[i] != '&') ans += s[i++];
            else {
                string ent;
                do {
                    ent += s[i++];
                } while (i < N && s[i - 1] != ';');
                if (ent == "&quot;") ans += "\""; 
                else if (ent == "&apos;" ) ans += "\'"; 
                else if (ent == "&amp;" ) ans += "&"; 
                else if (ent == "&gt;" ) ans += ">"; 
                else if (ent == "&lt;" ) ans += "<"; 
                else if (ent == "&frasl;" ) ans += "/"; 
                else ans += ent;
            }
        }
        return ans;
    }
};
```