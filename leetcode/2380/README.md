# [2380. Time Needed to Rearrange a Binary String (Medium)](https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string)

<p>You are given a binary string <code>s</code>. In one second, <strong>all</strong> occurrences of <code>"01"</code> are <strong>simultaneously</strong> replaced with <code>"10"</code>. This process <strong>repeats</strong> until no occurrences of <code>"01"</code> exist.</p>
<p>Return<em> the number of seconds needed to complete this process.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "0110101"
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
After one second, s becomes "1011010".
After another second, s becomes "1101100".
After the third second, s becomes "1110100".
After the fourth second, s becomes "1111000".
No occurrence of "01" exists any longer, and the process needed 4 seconds to complete,
so we return 4.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "11100"
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No occurrence of "01" exists in s, and the processes needed 0 seconds to complete,
so we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>
<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>
<p>Can you solve this problem in O(n) time complexity?</p>

**Companies**:
[PayPal](https://leetcode.com/company/paypal), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Minimum Swaps to Group All 1's Together (Medium)](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/)
* [Minimum Swaps to Group All 1's Together II (Medium)](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/)

## Solution 1. Simulation

```cpp
// OJ: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int N = s.size(), ans = 0, changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i + 1 < N; ++i) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    swap(s[i], s[i + 1]);
                    ++i;
                    changed = true;
                } 
            }
            ans += changed;
        }
        return ans;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/solutions/2454262
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zero = 0, second = 0;
        for (int i = 0; i < s.size(); ++i) {
            zero += s[i] == '0';
            if (s[i] == '1' && zero) second = max(second + 1, zero);
        }
        return second;
    }
};
```