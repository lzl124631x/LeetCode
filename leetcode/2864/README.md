# [2864. Maximum Odd Binary Number (Easy)](https://leetcode.com/problems/maximum-odd-binary-number)

<p>You are given a <strong>binary</strong> string <code>s</code> that contains at least one <code>&#39;1&#39;</code>.</p>

<p>You have to <strong>rearrange</strong> the bits in such a way that the resulting binary number is the <strong>maximum odd binary number</strong> that can be created from this combination.</p>

<p>Return <em>a string representing the maximum odd binary number that can be created from the given combination.</em></p>

<p><strong>Note </strong>that the resulting string <strong>can</strong> have leading zeros.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;010&quot;
<strong>Output:</strong> &quot;001&quot;
<strong>Explanation:</strong> Because there is just one &#39;1&#39;, it must be in the last position. So the answer is &quot;001&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0101&quot;
<strong>Output:</strong> &quot;1001&quot;
<strong>Explanation: </strong>One of the &#39;1&#39;s must be in the last position. The maximum number that can be made with the remaining digits is &quot;100&quot;. So the answer is &quot;1001&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists only of <code>&#39;0&#39;</code> and <code>&#39;1&#39;</code>.</li>
	<li><code>s</code> contains at least one <code>&#39;1&#39;</code>.</li>
</ul>


**Hints**:
* The binary representation of an odd number contains <code>'1'</code> in the least significant place.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-odd-binary-number
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int N = s.size(), i = 0, j = 0;
        for (; i < N; ++i) {
            if (s[i] == '1') swap(s[i], s[j++]);
        }
        swap(s[j - 1], s.back());
        return s;
    }
};
```