# [903. Valid Permutations for DI Sequence (Hard)](https://leetcode.com/problems/valid-permutations-for-di-sequence/)

<p>We are given <code>S</code>, a length <code>n</code> string of characters from the set <code>{'D', 'I'}</code>. (These letters stand for "decreasing" and "increasing".)</p>

<p>A&nbsp;<em>valid permutation</em>&nbsp;is a permutation <code>P[0], P[1], ..., P[n]</code> of integers&nbsp;<code>{0, 1, ..., n}</code>, such that for all <code>i</code>:</p>

<ul>
	<li>If <code>S[i] == 'D'</code>, then <code>P[i] &gt; P[i+1]</code>, and;</li>
	<li>If <code>S[i] == 'I'</code>, then <code>P[i] &lt; P[i+1]</code>.</li>
</ul>

<p>How many valid permutations are there?&nbsp; Since the answer may be large, <strong>return your answer modulo <code>10^9 + 7</code></strong>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"DID"</span>
<strong>Output: </strong><span id="example-output-1">5</span>
<strong>Explanation: </strong>
The 5 valid permutations of (0, 1, 2, 3) are:
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= S.length &lt;= 200</code></li>
	<li><code>S</code> consists only of characters from the set <code>{'D', 'I'}</code>.</li>
</ol>

<div>
<p>&nbsp;</p>
</div>


**Related Topics**:  
[Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/valid-permutations-for-di-sequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/valid-permutations-for-di-sequence/discuss/168278/C%2B%2BJavaPython-DP-Solution-O(N2)
class Solution {
public:
    int numPermsDISequence(string S) {
        int N = S.size(), mod = 1e9 + 7;
        vector<int> dp(N + 1, 1), dp2(N);
        for (int i = 0; i < N; dp = dp2, ++i) {
            if (S[i] == 'I') {
                for (int j = 0, cur = 0; j < N - i; ++j) dp2[j] = cur = (cur + dp[j]) % mod;
            } else {
                for (int j = N - i - 1, cur = 0; j >= 0; --j) dp2[j] = cur = (cur + dp[j + 1]) % mod;
            }
        }
        return dp[0];
    }
};
```