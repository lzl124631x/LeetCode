# [2222. Number of Ways to Select Buildings (Medium)](https://leetcode.com/problems/number-of-ways-to-select-buildings/)

<p>You are given a <strong>0-indexed</strong> binary string <code>s</code> which represents the types of buildings along a street where:</p>

<ul>
	<li><code>s[i] = '0'</code> denotes that the <code>i<sup>th</sup></code> building is an office and</li>
	<li><code>s[i] = '1'</code> denotes that the <code>i<sup>th</sup></code> building is a restaurant.</li>
</ul>

<p>As a city official, you would like to <strong>select</strong> 3 buildings for random inspection. However, to ensure variety, <strong>no two consecutive</strong> buildings out of the <strong>selected</strong> buildings can be of the same type.</p>

<ul>
	<li>For example, given <code>s = "0<u><strong>0</strong></u>1<u><strong>1</strong></u>0<u><strong>1</strong></u>"</code>, we cannot select the <code>1<sup>st</sup></code>, <code>3<sup>rd</sup></code>, and <code>5<sup>th</sup></code> buildings as that would form <code>"0<strong><u>11</u></strong>"</code> which is <strong>not</strong> allowed due to having two consecutive buildings of the same type.</li>
</ul>

<p>Return <em>the <b>number of valid ways</b> to select 3 buildings.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "001101"
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
The following sets of indices selected are valid:
- [0,2,4] from "<u><strong>0</strong></u>0<strong><u>1</u></strong>1<strong><u>0</u></strong>1" forms "010"
- [0,3,4] from "<u><strong>0</strong></u>01<u><strong>10</strong></u>1" forms "010"
- [1,2,4] from "0<u><strong>01</strong></u>1<u><strong>0</strong></u>1" forms "010"
- [1,3,4] from "0<u><strong>0</strong></u>1<u><strong>10</strong></u>1" forms "010"
- [2,4,5] from "00<u><strong>1</strong></u>1<u><strong>01</strong></u>" forms "101"
- [3,4,5] from "001<u><strong>101</strong></u>" forms "101"
No other selection is valid. Thus, there are 6 total ways.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "11100"
<strong>Output:</strong> 0
<strong>Explanation:</strong> It can be shown that there are no valid selections.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>

## Solution 1. DP

Let `dp[len][c]` be the count of alternating subsequences of length `len` ending with character `'0' + c'`. The answer is `dp[3][0] + dp[3][1]`.

We can scan the array from left to right and compute these `dp[len][c]` values.

For each `dp[len][c]`, its count should increase by `dp[len - 1][1 - c]`, i.e. prepending subsequences of length `len - 1` ending with a different character.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-select-buildings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long numberOfWays(string s) {
        long dp[4][2] = {};
        dp[0][0] = dp[0][1] = 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int len = 1; len <= 3; ++len) {
                dp[len][s[i] - '0'] += dp[len - 1][1 - (s[i] - '0')]; // for this s[i], we can prepend subsequences of length `len-1` ending with a different character to it.
            }
        }
        return dp[3][0] + dp[3][1];
    }
};
```

## Discuss

https://leetcode.com/problems/number-of-ways-to-select-buildings/discuss/1907123/