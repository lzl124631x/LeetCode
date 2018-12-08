# [859. Buddy Strings (Easy)](https://leetcode.com/problems/buddy-strings/)

<p>Given two strings <code>A</code> and <code>B</code>&nbsp;of lowercase letters, return <code>true</code> if and only if we&nbsp;can swap two letters in <code>A</code> so that the result equals <code>B</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong>A = <span id="example-input-1-1">"ab"</span>, B = <span id="example-input-1-2">"ba"</span>
<strong>Output: </strong><span id="example-output-1">true</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">"ab"</span>, B = <span id="example-input-2-2">"ab"</span>
<strong>Output: </strong><span id="example-output-2">false</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-3-1">"aa"</span>, B = <span id="example-input-3-2">"aa"</span>
<strong>Output: </strong><span id="example-output-3">true</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-4-1">"aaaaaaabc"</span>, B = <span id="example-input-4-2">"aaaaaaacb"</span>
<strong>Output: </strong><span id="example-output-4">true</span>
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-5-1">""</span>, B = <span id="example-input-5-2">"aa"</span>
<strong>Output: </strong><span id="example-output-5">false</span>
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ol>
	<li><code>0 &lt;= A.length &lt;= 20000</code></li>
	<li><code>0 &lt;= B.length &lt;= 20000</code></li>
	<li><code>A</code> and&nbsp;<code>B</code> consist only of lowercase letters.</li>
</ol>
</div>
</div>
</div>
</div>
</div>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/buddy-strings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        int cnts[26] = {0}, first = -1, second = -1;
        bool hasDup = false;
        for (int i = 0; i < A.size(); ++i) {
            if (++cnts[A[i] - 'a'] == 2) hasDup = true;
            if (A[i] == B[i]) continue;
            if (first == -1) first = i;
            else if (second == -1) second = i;
            else return false;
        }
        return (first != -1 && second != -1 && A[first] == B[second] && A[second] == B[first])
            || (first == -1 && second == -1 && hasDup);
    }
};
```