# [1641. Count Sorted Vowel Strings (Medium)](https://leetcode.com/problems/count-sorted-vowel-strings/)

<p>Given an integer <code>n</code>, return <em>the number of strings of length </em><code>n</code><em> that consist only of vowels (</em><code>a</code><em>, </em><code>e</code><em>, </em><code>i</code><em>, </em><code>o</code><em>, </em><code>u</code><em>) and are <strong>lexicographically sorted</strong>.</em></p>

<p>A string <code>s</code> is <strong>lexicographically sorted</strong> if for all valid <code>i</code>, <code>s[i]</code> is the same as or comes before <code>s[i+1]</code> in the alphabet.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> The 5 sorted strings that consist of vowels only are <code>["a","e","i","o","u"].</code>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 15
<strong>Explanation:</strong> The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 33
<strong>Output:</strong> 66045
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code>&nbsp;</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

We use `cnt[5]` to store the count of strings ending with `aeiou` respectively.

When `n == 1`, `int cnt[5] = {1,1,1,1,1}`.

When going from `n` to `n + 1`, the strings of length `n` ending with `a` can be appended with `aeiou`, and thus contributes its count `cnt[0]` to `next[0..4]` where `int next[5]` is the `cnt` for strings of length `n + 1`.

Similarly, `cnt[1]` contributes to `next[1..4]`. `cnt[2]` contributes to `next[2..4]`. And `cnt[4]` contributes to `next[4]`.

After each iteration, we swap `next` back into `cnt` and continue.

After `n - 1` iterations, we return the sum of `cnt` array.

```cpp
// OJ: https://leetcode.com/problems/count-sorted-vowel-strings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countVowelStrings(int n) {
        int cnt[5] = {1,1,1,1,1};
        while (--n) {
            int next[5] = {};
            for (int i = 0; i < 5; ++i) {
                for (int j = i; j < 5; ++j) next[j] += cnt[i];
            }
            swap(cnt, next);
        }
        return accumulate(begin(cnt), end(cnt), 0);
    }
};
```