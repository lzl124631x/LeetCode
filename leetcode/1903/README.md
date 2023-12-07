# [1903. Largest Odd Number in String (Easy)](https://leetcode.com/problems/largest-odd-number-in-string)

<p>You are given a string <code>num</code>, representing a large integer. Return <em>the <strong>largest-valued odd</strong> integer (as a string) that is a <strong>non-empty substring</strong> of </em><code>num</code><em>, or an empty string </em><code>&quot;&quot;</code><em> if no odd integer exists</em>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;52&quot;
<strong>Output:</strong> &quot;5&quot;
<strong>Explanation:</strong> The only non-empty substrings are &quot;5&quot;, &quot;2&quot;, and &quot;52&quot;. &quot;5&quot; is the only odd number.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;4206&quot;
<strong>Output:</strong> &quot;&quot;
<strong>Explanation:</strong> There are no odd numbers in &quot;4206&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;35427&quot;
<strong>Output:</strong> &quot;35427&quot;
<strong>Explanation:</strong> &quot;35427&quot; is already an odd number.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> only consists of digits and does not contain any leading zeros.</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Math](https://leetcode.com/tag/math), [String](https://leetcode.com/tag/string), [Greedy](https://leetcode.com/tag/greedy)

**Similar Questions**:
* [Largest 3-Same-Digit Number in String (Easy)](https://leetcode.com/problems/largest-3-same-digit-number-in-string)

**Hints**:
* In what order should you iterate through the digits?
* If an odd number exists, where must the number start from?

## Solution 1. Find the rightmost odd number

```cpp
// OJ: https://leetcode.com/problems/largest-odd-number-in-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string largestOddNumber(string s) {
        while (s.size() && (s.back() - '0') % 2 == 0) s.pop_back();
        return s;
    }
};
```