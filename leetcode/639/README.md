# [639. Decode Ways II (Hard)](https://leetcode.com/problems/decode-ways-ii/)

<p>
A message containing letters from <code>A-Z</code> is being encoded to numbers using the following mapping way:
</p>

<pre>'A' -&gt; 1
'B' -&gt; 2
...
'Z' -&gt; 26
</pre>

<p>
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.
</p>


<p>
Given the encoded message containing digits and the character '*', return the total number of ways to decode it.
</p>

<p>
Also, since the answer may be very large, you should return the output mod 10<sup>9</sup> + 7.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "*"
<b>Output:</b> 9
<b>Explanation:</b> The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "1*"
<b>Output:</b> 9 + 9 = 18
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The length of the input string will fit in range [1, 10<sup>5</sup>].</li>
<li>The input string will only contain the character '*' and digits '0' - '9'.</li>
</ol>
<p></p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Decode Ways (Medium)](https://leetcode.com/problems/decode-ways/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/decode-ways-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/decode-ways-ii/solution/
class Solution {
    void add(long &a, long b) { a = (a + b) % ((int)1e9+7); }
public:
    int numDecodings(string s) {
        long prev1 = s[0] == '*' ? 9 : (s[0] != '0'), prev2 = 1;
        for (int i = 1; i < s.size(); ++i) {
            long cur = 0;
            if (s[i] == '*') {
                cur = 9 * prev1;
                if (s[i - 1] == '1') add(cur, 9 * prev2);
                else if (s[i - 1] == '2') add(cur, 6 * prev2);
                else if (s[i - 1] == '*') add(cur, 15 * prev2);
            } else {
                cur = s[i] != '0' ? prev1 : 0;
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) add(cur, prev2);
                else if (s[i - 1] == '*') add(cur, (s[i] <= '6' ? 2 : 1) * prev2);
            }
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
```