# [2002. Maximum Product of the Length of Two Palindromic Subsequences (Medium)](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/)

<p>Given a string <code>s</code>, find two <strong>disjoint palindromic subsequences</strong> of <code>s</code> such that the <strong>product</strong> of their lengths is <strong>maximized</strong>. The two subsequences are <strong>disjoint</strong> if they do not both pick a character at the same index.</p>

<p>Return <em>the <strong>maximum</strong> possible <strong>product</strong> of the lengths of the two palindromic subsequences</em>.</p>

<p>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is <strong>palindromic</strong> if it reads the same forward and backward.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="example-1" src="https://assets.leetcode.com/uploads/2021/08/24/two-palindromic-subsequences.png" style="width: 550px; height: 124px;">
<pre><strong>Input:</strong> s = "leetcodecom"
<strong>Output:</strong> 9
<strong>Explanation</strong>: An optimal solution is to choose "ete" for the 1<sup>st</sup> subsequence and "cdc" for the 2<sup>nd</sup> subsequence.
The product of their lengths is: 3 * 3 = 9.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "bb"
<strong>Output:</strong> 1
<strong>Explanation</strong>: An optimal solution is to choose "b" (the first character) for the 1<sup>st</sup> subsequence and "b" (the second character) for the 2<sup>nd</sup> subsequence.
The product of their lengths is: 1 * 1 = 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "accbcaxxcxx"
<strong>Output:</strong> 25
<strong>Explanation</strong>: An optimal solution is to choose "accca" for the 1<sup>st</sup> subsequence and "xxcxx" for the 2<sup>nd</sup> subsequence.
The product of their lengths is: 5 * 5 = 25.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 12</code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
</ul>


**Companies**:  
[Ascend](https://leetcode.com/company/ascend)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Bitmask](https://leetcode.com/tag/bitmask/)

**Similar Questions**:
* [Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome/)
* [Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)
* [Maximum Product of the Length of Two Palindromic Substrings (Hard)](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/)

## Solution 1. Bitmask DP

Let `dp[mask]` be the length of the longest palindromic subsequence within a subsequence represented by `mask`.

The answer is `max( dp[m] * dp[(1 << N) - 1 - m] | 1 <= m < 1 << N )`. (`(1 << N) - 1 - m)` is the complement subset of `m`).

For `dp[m]`, we can brute-forcely enumerate each of its subset, and compute the maximum length of its palindromic subsets.

```
dp[m] = max( bitcount( sub ) | `sub` is a subset of `m`, and `sub` forms a palindrome )
```

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
// Author: github.com/lzl124631x
// Time: O(N * 2^N + 3^N)
// Space: O(2^N)
class Solution {
    bool isPalindrome(string &s, int mask) {
        vector<int> index;
        for (int i = 0; mask; mask >>= 1, ++i) {
            if (mask & 1) index.push_back(i);
        }
        for (int i = 0, j = index.size() - 1; i < j; ++i, --j) {
            if (s[index[i]] != s[index[j]]) return false;
        }
        return true;
    }
public:
    int maxProduct(string s) {
        int N = s.size();
        vector<int> dp(1 << N), pal(1 << N);
        for (int m = 1; m < 1 << N; ++m) {
            pal[m] = isPalindrome(s, m);
        }
        for (int m = 1; m < 1 << N; ++m) { // `m` is a subset of all the characters
            for (int sub = m; sub; sub = (sub - 1) & m) { // `sub` is a subset of `m`
                if (pal[sub]) dp[m] = max(dp[m], __builtin_popcount(sub)); // if this subset forms a palindrome, update the maximum length
            }
        }
        int ans = 0;
        for (int m = 1; m < 1 << N; ++m) {
            ans = max(ans, dp[m] * dp[(1 << N) - 1 - m]);
        }
        return ans;
    }
};
```

## Solution 2. Bitmask DP + Bitmask Traversal

In Solution 1, filling the `pal` array takes `O(N * 2^N)` time. We can reduce the time to `O(2^N)` using DP.

```
pal[m] = s[lb] == s[hb] && pal[x]
         where `lb` and `hb` are the indexes of the lowest and highest bits of `m`, respectively,
            and `x` equals `m` removing the lowest and highest bits.
```

```cpp
vector<bool> pal(1 << N);
pal[0] = 1;
for (int m = 1; m < 1 << N; ++m) {
    int lb = __builtin_ctz(m & -m), hb = 31 - __builtin_clz(m); 
    pal[m] = s[lb] == s[hb] && pal[m & ~(1 << lb) & ~(1 << hb)];
}
```

Using the same DP idea, we can reduce the time complexity for filling the `dp` array from `O(3^N)` to `O(2^N)`, and we don't even need the `pal` array.

```
// if `m` has only a single bit 1
dp[m] = 1 

// otherwise
dp[m] = 2 + dp[m - (1 << lb) - (1 << hb)]           // if lb == hb
      = max( dp[m - (1 << lb)], dp[m - (1 << hb)] ) // if lb != hb
```

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    int maxProduct(string s) {
        int N = s.size(), ans = 0;
        vector<int> dp(1 << N);
        for (int m = 1; m < 1 << N; ++m) {
            int lb = __builtin_ctz(m), hb = 31 - __builtin_clz(m);
            if (lb == hb) dp[m] = 1;
            else if (s[lb] == s[hb]) dp[m] = 2 + dp[m - (1 << lb) - (1 << hb)];
            else dp[m] = max(dp[m - (1 << lb)], dp[m - (1 << hb)]);
        }
        for (int m = 1; m < (1 << N) - 1; ++m) {
            ans = max(ans, dp[m] * dp[((1 << N) - 1) ^ m]);
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/discuss/1458788/C%2B%2B-DP-from-O(3N)-to-O(2N)