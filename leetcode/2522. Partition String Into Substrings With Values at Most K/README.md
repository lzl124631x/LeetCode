# [2522. Partition String Into Substrings With Values at Most K (Medium)](https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k)

<p>You are given a string <code>s</code> consisting of digits from <code>1</code> to <code>9</code> and an integer <code>k</code>.</p>
<p>A partition of a string <code>s</code> is called <strong>good</strong> if:</p>
<ul>
	<li>Each digit of <code>s</code> is part of <strong>exactly</strong> one substring.</li>
	<li>The value of each substring is less than or equal to <code>k</code>.</li>
</ul>
<p>Return <em>the <strong>minimum</strong> number of substrings in a <strong>good</strong> partition of</em> <code>s</code>. If no <strong>good</strong> partition of <code>s</code> exists, return <code>-1</code>.</p>
<p><b>Note</b> that:</p>
<ul>
	<li>The <strong>value</strong> of a string is its result when interpreted as an integer. For example, the value of <code>"123"</code> is <code>123</code> and the value of <code>"1"</code> is <code>1</code>.</li>
	<li>A <strong>substring</strong> is a contiguous sequence of characters within a string.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "165462", k = 60
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can partition the string into substrings "16", "54", "6", and "2". Each substring has a value less than or equal to k = 60.
It can be shown that we cannot partition the string into less than 4 substrings.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "238182", k = 5
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no good partition for this string.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is a digit from <code>'1'</code> to <code>'9'</code>.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>
<p>&nbsp;</p>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumPartition(string s, int k) {
        int N = s.size(), ans = 0;
        for (int i = 0; i < N; ++ans) {
            long n = 0;
            while (i < N && n * 10 + s[i] - '0' <= k) {
                n = n * 10 + s[i++] - '0';
            }
            if (n == 0) return -1;
        }
        return ans;
    }
};
```