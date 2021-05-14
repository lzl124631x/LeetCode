# [848. Shifting Letters (Medium)](https://leetcode.com/problems/shifting-letters/)

<p>We have a string <code>s</code> of lowercase letters, and an integer array <code>shifts</code>.</p>

<p>Call the <em>shift</em> of a letter, the next letter in the alphabet, (wrapping around so that <code>'z'</code> becomes <code>'a'</code>).&nbsp;</p>

<p>For example, <code>shift('a') = 'b'</code>, <code>shift('t') = 'u'</code>, and <code>shift('z') = 'a'</code>.</p>

<p>Now for each <code>shifts[i] = x</code>, we want to shift the first <code>i+1</code>&nbsp;letters of <code>S</code>, <code>x</code> times.</p>

<p>Return the final string&nbsp;after all such shifts to <code>s</code> are applied.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>s = "abc", shifts = [3,5,9]
<strong>Output: </strong>"rpl"
<strong>Explanation: </strong>
We start with "abc".
After shifting the first 1 letters of S by 3, we have "dbc".
After shifting the first 2 letters of S by 5, we have "igc".
After shifting the first 3 letters of S by 9, we have "rpl", the answer.
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= s.length = shifts.length &lt;= 20000</code></li>
	<li><code>0 &lt;= shifts[i] &lt;= 10<sup>9</sup></code></li>
</ol>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Replace All Digits with Characters (Easy)](https://leetcode.com/problems/replace-all-digits-with-characters/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shifting-letters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& A) {
        int shift = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            shift = (shift + A[i]) % 26;
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
        }
        return s;
    }
};
```