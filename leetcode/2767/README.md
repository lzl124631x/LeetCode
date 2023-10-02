# [2767. Partition String Into Minimum Beautiful Substrings (Medium)](https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings)

<p>Given a binary string <code>s</code>, partition the string into one or more <strong>substrings</strong> such that each substring is <strong>beautiful</strong>.</p>
<p>A string is <strong>beautiful</strong> if:</p>
<ul>
	<li>It doesn't contain leading zeros.</li>
	<li>It's the <strong>binary</strong> representation of a number that is a power of <code>5</code>.</li>
</ul>
<p>Return <em>the <strong>minimum</strong> number of substrings in such partition. </em>If it is impossible to partition the string <code>s</code> into beautiful substrings,&nbsp;return <code>-1</code>.</p>
<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "1011"
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can paritition the given string into ["101", "1"].
- The string "101" does not contain leading zeros and is the binary representation of integer 5<sup>1</sup> = 5.
- The string "1" does not contain leading zeros and is the binary representation of integer 5<sup>0</sup> = 1.
It can be shown that 2 is the minimum number of beautiful substrings that s can be partitioned into.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "111"
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can paritition the given string into ["1", "1", "1"].
- The string "1" does not contain leading zeros and is the binary representation of integer 5<sup>0</sup> = 1.
It can be shown that 3 is the minimum number of beautiful substrings that s can be partitioned into.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "0"
<strong>Output:</strong> -1
<strong>Explanation:</strong> We can not partition the given string into beautiful substrings.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 15</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Partition Array for Maximum Sum (Medium)](https://leetcode.com/problems/partition-array-for-maximum-sum/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings
// Author: github.com/lzl124631x
// Time: O(2^N * N)
// Space: O(1)
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int N = s.size(), ans = INT_MAX;
        for (int m = 1; m < (1 << N); ++m) {
            int i = 0, split = 0;
            while (i < N) {
                int start = i, v = m >> (N - 1 - i) & 1, n = s[i] - '0';
                if (s[i] == '0') {
                    split = -1;
                    break;
                }
                ++i;
                while (i < N && (m >> (N - 1 - i) & 1) == v) {
                    n = (n << 1) + s[i] - '0';
                    ++i;
                }
                while (n % 5 == 0) n /= 5;
                if (n != 1) {
                    split = -1;
                    break;
                }
                ++split;
            }
            if (split != -1) ans = min(ans, split);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```

## Solution 2. DP

Let `dp[i+1]` be the min split of `s[0..i]`. Initially `dp[i] = Inf`, `dp[0] = 0`.

```
dp[i+1] = 1 + min( dp[j] | 0 <= j <= i and s[j..i] is a power of 5 and s[j..i] has no leading 0)
```

The answer is `dp[N]`.

To check if `n` is pow of 5, we can check if `15625 % n == 0`, where `15625` is the biggest pow of 5 with 15 bits.

```cpp
// OJ: https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int N = s.size(), ans = INT_MAX;
        vector<int> dp(N + 1, INT_MAX);
        dp[0] = 0;
        auto isPowerOf5 = [](int n) {
            return 15625 % n == 0
        };
        for (int i = 0; i < N; ++i) {
            int p = 1, n = 0;
            for (int j = i; j >= 0; --j, p <<= 1) {
                if (s[j] == '0') continue;
                n += p;
                if (dp[j] == INT_MAX || !isPowerOf5(n)) continue;
                dp[i + 1] = min(dp[i + 1], 1 + dp[j]);
            }
        }
        return dp[N] == INT_MAX ? -1 : dp[N];
    }
};
```