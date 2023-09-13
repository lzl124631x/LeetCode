# [2311. Longest Binary Subsequence Less Than or Equal to K (Medium)](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k)

<p>You are given a binary string <code>s</code> and a positive integer <code>k</code>.</p>
<p>Return <em>the length of the <strong>longest</strong> subsequence of </em><code>s</code><em> that makes up a <strong>binary</strong> number less than or equal to</em> <code>k</code>.</p>
<p>Note:</p>
<ul>
	<li>The subsequence can contain <strong>leading zeroes</strong>.</li>
	<li>The empty string is considered to be equal to <code>0</code>.</li>
	<li>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "1001010", k = 5
<strong>Output:</strong> 5
<strong>Explanation:</strong> The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "00101001", k = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/), [Memoization](https://leetcode.com/tag/memoization/)

**Similar Questions**:
* [Maximum Binary String After Change (Medium)](https://leetcode.com/problems/maximum-binary-string-after-change/)

## Solution 1. Greedy

The brute force solution would be generating all `2^N` subsequences and use `O(N)` time to check each of them, taking `O(2^N * N)` time.

There are lots of unnecessary checks. For example, `s = "00001", k = 1`, when we know `binary("1") <= k`, for all the leading zeros, we can just greedily use them. So, we need to find a subsequence to the right as much as possible that is `<= k`, and use all leading zeros.

Assume `k` has `bits` bits, if the last `bits` digits of `s` is `<= k`, we can use them directly and use all leading zeros.

If the last `bits` digits of `s` is `> k`, we must use another leading `0` to replace the leading `1` of the current subsequence. For example `s = "0010111101", k = 4 (100)`, the last 3 digits of `s` forms `"101" > 100`, and using any `1`s in the front won't reduce the value; we must find a leading zero to make the subsequence `"001"`.

If we can't find such leading zero, we have to match one less digit.

Otherwise, we use this leading zero, and use up all other leading zeros.

```cpp
// OJ: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int i = s.size() - 1, bits = 32 - __builtin_clz(k), n = 0, ans = 0;
        while (i >= 0 && bits-- > 0) { // turn the last `bits` digits to a binary number `n`.
            n += ((s[i] - '0') << ans);
            --i;
            ++ans;
        }
        if (n > k) { // if `n > k`, we need to find a single `0` to replace the leading `1` of `n`.
            while (i >= 0 && s[i] == '1') --i;
            if (i < 0) return ans - 1; // If we can't find a `0`, we have to match one less digit.
            --i;
        }
        for (; i >= 0; --i) { // for any leading `0`s, we use them all
            ans += s[i] == '0';
        }
        return ans;
    }
};
```

## Solution 2.

The key is to realize that we need to take all zeros.

Then, we take as many 1 from the right as we can, before exceeding `k`. It can be shown that greedily using 1 from the right is always better than to skip it.

```cpp
// OJ: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/solutions/2168423/o-n/
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val = 0, one = 0, p = 1;
        for (int i = s.size() - 1; i >= 0 && val + p <= k; --i) {
            if (s[i] == '1') {
                ++one;
                val += p;
            }
            p <<= 1;
        }
        return count(begin(s), end(s), '0') + one;
    }
};
```