# [696. Count Binary Substrings (Easy)](https://leetcode.com/problems/count-binary-substrings/)

<p>Give a string <code>s</code>, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively. 
</p>
<p>Substrings that occur multiple times are counted the number of times they occur.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "00110011"
<b>Output:</b> 6
<b>Explanation:</b> There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
<br>Notice that some of these substrings repeat and are counted the number of times they occur.
<br>Also, "00110011" is not a valid substring because <b>all</b> the 0's (and 1's) are not grouped together.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "10101"
<b>Output:</b> 4
<b>Explanation:</b> There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
</pre>
<p></p>

<p><b>Note:</b>
</p><li><code>s.length</code> will be between 1 and 50,000.</li>
<li><code>s</code> will only consist of "0" or "1" characters.</li>
<p></p>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Encode and Decode Strings (Medium)](https://leetcode.com/problems/encode-and-decode-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-binary-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, N = s.size(), ans = 0;
        for (int i = 0; i < N; ) {
            int j = i++;
            while (i < N && s[i] == s[i - 1]) ++i;
            int cnt = i - j;
            ans += min(cnt, prev);
            prev = cnt;
        }
        return ans;
    }
};
```