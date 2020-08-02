# [984. String Without AAA or BBB (Medium)](https://leetcode.com/problems/string-without-aaa-or-bbb/)

<p>Given two integers <code>A</code> and <code>B</code>, return <strong>any</strong> string <code>S</code> such that:</p>

<ul>
	<li><code>S</code> has length <code>A + B</code> and contains exactly <code>A</code> <code>'a'</code> letters, and exactly <code>B</code> <code>'b'</code> letters;</li>
	<li>The substring&nbsp;<code>'aaa'</code>&nbsp;does not occur in <code>S</code>;</li>
	<li>The substring <code>'bbb'</code> does not occur in <code>S</code>.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">1</span>, B = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">"abb"
</span><strong>Explanation:</strong> "abb", "bab" and "bba" are all correct answers.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">4</span>, B = <span id="example-input-2-2">1</span>
<strong>Output: </strong><span id="example-output-2">"aabaa"</span></pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= A &lt;= 100</code></li>
	<li><code>0 &lt;= B &lt;= 100</code></li>
	<li>It is guaranteed such an <code>S</code> exists for the given <code>A</code> and <code>B</code>.</li>
</ol>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/string-without-aaa-or-bbb/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        char a = 'a', b = 'b';
        if (A < B) swap(A, B), swap(a, b);
        string ans;
        while (A && B) {
            for (int i = A > B ? 2 : 1; i > 0; --i, --A) ans += a;
            ans += b;
            --B;
        }
        while (A-- > 0) ans += a;
        return ans;
    }
};
```