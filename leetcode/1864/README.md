# [1864. Minimum Number of Swaps to Make the Binary String Alternating (Medium)](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/)

<p>Given a binary string <code>s</code>, return <em>the <strong>minimum</strong> number of character swaps to make it <strong>alternating</strong>, or </em><code>-1</code><em> if it is impossible.</em></p>

<p>The string is called <strong>alternating</strong> if no two adjacent characters are equal. For example, the strings <code>"010"</code> and <code>"1010"</code> are alternating, while the string <code>"0100"</code> is not.</p>

<p>Any two characters may be swapped, even if they are&nbsp;<strong>not adjacent</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "111000"
<strong>Output:</strong> 1
<strong>Explanation:</strong> Swap positions 1 and 4: "1<u>1</u>10<u>0</u>0" -&gt; "1<u>0</u>10<u>1</u>0"
The string is now alternating.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "010"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string is already alternating, no swaps are needed.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "1110"
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Companies**:  
[Société Générale](https://leetcode.com/company/societe-generale)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Two Pointers

Count number of `0`s and `1`s. If either count is greater than `1` + the other count, return `-1`. Otherwise, we can try putting `0` or `1` at the first position and use two pointers to try to swap the numbers.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    int solve(string s, int first) {
        int i = 0, j = 1, N = s.size(), ans = 0;
        while (i < N && j < N) {
            while (i < N && s[i] == '0' + first) i += 2;
            while (j < N && s[j] == '0' + 1 - first) j += 2;
            if (i < N && j < N) {
                swap(s[i], s[j]);
                ++ans;
            }
        }
        return ans;
    }
public:
    int minSwaps(string s) {
        int one = 0, zero = 0;
        for (char c : s) {
            if (c == '1') one++;
            else zero++;
        }
        if (zero > one + 1 || one > zero + 1) return -1;
        int ans = INT_MAX;
        if (zero >= one) ans = min(ans, solve(s, 0));
        if (zero <= one) ans = min(ans, solve(s, 1));
        return ans;
    }
};
```