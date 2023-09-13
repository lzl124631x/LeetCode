# [1220. Count Vowels Permutation (Hard)](https://leetcode.com/problems/count-vowels-permutation/)

<p>Given an integer <code>n</code>, your task is to count how many strings of length <code>n</code> can be formed under the following rules:</p>

<ul>
	<li>Each character is a lower case vowel&nbsp;(<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>)</li>
	<li>Each vowel&nbsp;<code>'a'</code> may only be followed by an <code>'e'</code>.</li>
	<li>Each vowel&nbsp;<code>'e'</code> may only be followed by an <code>'a'</code>&nbsp;or an <code>'i'</code>.</li>
	<li>Each vowel&nbsp;<code>'i'</code> <strong>may not</strong> be followed by another <code>'i'</code>.</li>
	<li>Each vowel&nbsp;<code>'o'</code> may only be followed by an <code>'i'</code> or a&nbsp;<code>'u'</code>.</li>
	<li>Each vowel&nbsp;<code>'u'</code> may only be followed by an <code>'a'.</code></li>
</ul>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo <code>10^9 + 7.</code></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> All possible strings are: "a", "e", "i" , "o" and "u".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 10
<strong>Explanation:</strong> All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
</pre>

<p><strong>Example 3:&nbsp;</strong></p>

<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> 68</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10^4</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Given the rule, the valid combinations are as follows:

```
a: ae
e: ea ei
i: ia ie io iu
o: oi ou
u: ua
```

Let `dp[i][j]` be the count of valid strings of length `i` ending with letter `j` where `0 < i <= n`, `j = 'a', 'e', 'i', 'o', 'u'`.

So we have

```
dp[i]['a'] = dp[i - 1]['e'] + dp[i - 1]['i'] + dp[i - 1]['u']
dp[i]['e'] = dp[i - 1]['a'] + dp[i - 1]['i']
dp[i]['i'] = dp[i - 1]['e'] + dp[i - 1]['o']
dp[i]['o'] = dp[i - 1]['i']
dp[i]['u'] = dp[i - 1]['i'] + dp[i - 1]['o']

dp[1][j] = 1
```

The answer is `Sum{ dp[n][j] | j = 'a', 'e', 'i', 'o', 'u' }`.

```cpp
// OJ: https://leetcode.com/problems/count-vowels-permutation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7, a = 1, e = 1, i = 1, o = 1, u = 1;
        while (--n) {
            int aa = ((e + i) % mod + u) % mod;
            int ee = (a + i) % mod;
            int ii = (e + o) % mod;
            int oo = i;
            int uu = (i + o) % mod;
            a = aa, e = ee, i = ii, o = oo, u = uu;
        }
        return ((((a + e) % mod + i) % mod + o) % mod + u) % mod;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/count-vowels-permutation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countVowelPermutation(int n) {
        long mod = 1e9 + 7, a = 1, e = 1, i = 1, o = 1, u = 1;
        while (--n) {
            long aa = e;
            long ee = (a + i) % mod;
            long ii = ((a + e) % mod + (o + u) % mod) % mod;
            long oo = (i + u) % mod;
            long uu = a;
            a = aa, e = ee, i = ii, o = oo, u = uu;
        }
        return (((((a + e) % mod + i) % mod) + o) % mod + u) % mod;
    }
};
```