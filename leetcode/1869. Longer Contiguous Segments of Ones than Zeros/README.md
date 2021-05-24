# [1869. Longer Contiguous Segments of Ones than Zeros (Easy)](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/)

<p>Given a binary string <code>s</code>, return <code>true</code><em> if the <strong>longest</strong> contiguous segment of </em><code>1</code><em>s is <strong>strictly longer</strong> than the <strong>longest</strong> contiguous segment of </em><code>0</code><em>s in </em><code>s</code>. Return <code>false</code><em> otherwise</em>.</p>

<ul>
	<li>For example, in <code>s = "<u>11</u>01<u>000</u>10"</code> the longest contiguous segment of <code>1</code>s has length <code>2</code>, and the longest contiguous segment of <code>0</code>s has length <code>3</code>.</li>
</ul>

<p>Note that if there are no <code>0</code>s, then the longest contiguous segment of <code>0</code>s is considered to have length <code>0</code>. The same applies if there are no <code>1</code>s.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1101"
<strong>Output:</strong> true
<strong>Explanation:</strong>
The longest contiguous segment of 1s has length 2: "<u>11</u>01"
The longest contiguous segment of 0s has length 1: "11<u>0</u>1"
The segment of 1s is longer, so return true.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "111000"
<strong>Output:</strong> false
<strong>Explanation:</strong>
The longest contiguous segment of 1s has length 3: "<u>111</u>000"
The longest contiguous segment of 0s has length 3: "111<u>000</u>"
The segment of 1s is not longer, so return false.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "110100010"
<strong>Output:</strong> false
<strong>Explanation:</strong>
The longest contiguous segment of 1s has length 2: "<u>11</u>0100010"
The longest contiguous segment of 0s has length 3: "1101<u>000</u>10"
The segment of 1s is not longer, so return false.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Max Consecutive Ones (Easy)](https://leetcode.com/problems/max-consecutive-ones/)
* [Check if Binary String Has at Most One Segment of Ones (Easy)](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int longest(string s, char c) {
        int ans = 0;
        for (int i = 0; i < s.size(); ) {
            if (s[i] != c) ++i;
            else {
                int start = i;
                while (i < s.size() && s[i] == c) ++i;
                ans = max(ans, i - start);
            }
        }
        return ans;
    }
public:
    bool checkZeroOnes(string s) {
        return longest(s, '0') < longest(s, '1');
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0, zero = 0, maxOne = 0, maxZero = 0;
        for (char c : s) {
            if (c == '0') {
                one = 0;
                ++zero;
                maxZero = max(maxZero, zero);
            } else {
                zero = 0;
                ++one;
                maxOne = max(maxOne, one);
            }
        }
        return maxOne > maxZero;
    }
};
```