# [917. Reverse Only Letters (Easy)](https://leetcode.com/problems/reverse-only-letters/)

<p>Given a string <code>S</code>, return the "reversed" string where all characters that are not a letter&nbsp;stay in the same place, and all letters reverse their positions.</p>

<p>&nbsp;</p>

<div>
<div>
<div>
<ol>
</ol>
</div>
</div>
</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"ab-cd"</span>
<strong>Output: </strong><span id="example-output-1">"dc-ba"</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"a-bC-dEf-ghIj"</span>
<strong>Output: </strong><span id="example-output-2">"j-Ih-gfE-dCba"</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">"Test1ng-Leet=code-Q!"</span>
<strong>Output: </strong><span id="example-output-3">"Qedo1ct-eeLg=ntse-T!"</span>
</pre>

<p>&nbsp;</p>

<div>
<p><strong><span>Note:</span></strong></p>

<ol>
	<li><code>S.length &lt;= 100</code></li>
	<li><code>33 &lt;= S[i].ASCIIcode &lt;= 122</code>&nbsp;</li>
	<li><code>S</code> doesn't contain <code>\</code> or <code>"</code></li>
</ol>
</div>
</div>
</div>
</div>

**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-only-letters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size() - 1;
        while (i < j) {
            while (i < j && !isalpha(S[i])) ++i;
            while (i < j && !isalpha(S[j])) --j;
            if (i < j) swap(S[i++], S[j--]);
        }
        return S;
    }
};
```