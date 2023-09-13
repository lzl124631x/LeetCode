# [1784. Check if Binary String Has at Most One Segment of Ones (Easy)](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)

<p>Given a binary string <code>s</code> <strong>​​​​​without leading zeros</strong>, return <code>true</code>​​​ <em>if </em><code>s</code><em> contains <strong>at most one contiguous segment of ones</strong></em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1001"
<strong>Output:</strong> false
<strong>Explanation: </strong>The ones do not form a contiguous segment.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "110"
<strong>Output:</strong> true</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code>​​​​ is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>s[0]</code> is&nbsp;<code>'1'</code>.</li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

When `done` is `true`, it means that we've already done visiting the first continuous segment of `1`s. 

If we continue to see `1` after `done` is already `true`, return `false`.

```cpp
// OJ: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        int done = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (done) return false;
            } else done = true;
        }
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] == '0' && s[i] == '1') return false;
        }
        return true;
    }
};
```