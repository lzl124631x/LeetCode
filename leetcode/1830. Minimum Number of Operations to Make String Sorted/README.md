# [1830. Minimum Number of Operations to Make String Sorted (Hard)](https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/)

<p>You are given a string <code>s</code> (<strong>0-indexed</strong>)​​​​​​. You are asked to perform the following operation on <code>s</code>​​​​​​ until you get a sorted string:</p>

<ol>
	<li>Find <strong>the largest index</strong> <code>i</code> such that <code>1 &lt;= i &lt; s.length</code> and <code>s[i] &lt; s[i - 1]</code>.</li>
	<li>Find <strong>the largest index</strong> <code>j</code> such that <code>i &lt;= j &lt; s.length</code> and <code>s[k] &lt; s[i - 1]</code> for all the possible values of <code>k</code> in the range <code>[i, j]</code> inclusive.</li>
	<li>Swap the two characters at indices <code>i - 1</code>​​​​ and <code>j</code>​​​​​.</li>
	<li>Reverse the suffix starting at index <code>i</code>​​​​​​.</li>
</ol>

<p>Return <em>the number of operations needed to make the string sorted.</em> Since the answer can be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "cba"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The simulation goes as follows:
Operation 1: i=2, j=2. Swap s[1] and s[2] to get s="cab", then reverse the suffix starting at 2. Now, s="cab".
Operation 2: i=1, j=2. Swap s[0] and s[2] to get s="bac", then reverse the suffix starting at 1. Now, s="bca".
Operation 3: i=2, j=2. Swap s[1] and s[2] to get s="bac", then reverse the suffix starting at 2. Now, s="bac".
Operation 4: i=1, j=1. Swap s[0] and s[1] to get s="abc", then reverse the suffix starting at 1. Now, s="acb".
Operation 5: i=2, j=2. Swap s[1] and s[2] to get s="abc", then reverse the suffix starting at 2. Now, s="abc".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aabaa"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The simulation goes as follows:
Operation 1: i=3, j=4. Swap s[2] and s[4] to get s="aaaab", then reverse the substring starting at 3. Now, s="aaaba".
Operation 2: i=4, j=4. Swap s[3] and s[4] to get s="aaaab", then reverse the substring starting at 4. Now, s="aaaab".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "cdbea"
<strong>Output:</strong> 63</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "leetcodeleetcodeleetcode"
<strong>Output:</strong> 982157772
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3000</code></li>
	<li><code>s</code>​​​​​​ consists only of lowercase English letters.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

## Solution 1. Get Lexicographical order

This question is asking what the lexicographical order of this string is. For example, we have `abc, acb, bac, bca, cab, cba`, then order of string cab is `4` (we start from zero).

For example, how many permutations of `s="cbbaaac"` is smaller than `s`?

**How many permutations are smaller than `s` because of the first letter?**

For the first letter, we have `5` options because there are `3a2b` that can be placed as the first letter. For the rest of the 6 letters, they can form `6!` permutations. So there are total `5 * 6!` permutations with duplicates.

For all these permutations, they all have `3a2b2c`, so we need to divide by `3! * 2! * 2!` to deduplicate. Hence, there are `5 * 6! / 3! / 2! / 2!` permutations without duplicates.

**How many permutations are smaller than `s` because of the second letter?**

Now we consider the permutations whose first letters are `'c'` and they are smaller than `s` because of the second letter. This question is the same as "how many permutations of `t="bbaaac"` are smaller than `t` because of the first letter". We can use the same pattern we found previously. We have 3 options (3 `a`s) to place as the first letter, and the rest of the `5` letters can form `5!` permutations. Since we have `3a2b1c` we need to deduplicate by dividing by `3! * 2! * 1!`. So there are `3 * 5! / 3! / 2! / 1!` such permutations.

**In general, how many permutations are smaller than `s` because of the `i`th letter?**

We need to count how many letters in `s[(i+1)..(N-1)]` are smaller than `s[i]`. Assume it's `countLessThan`. And the rest of the letters can form `(N - i - 1)!` permutations with duplicate. We need to divide by `Multiply( cnt[ch]! )` where `cnt[ch]` is the number of occurrence of a letter `ch` in `s`. The answer is `countLessThan * (N - i - 1)! / Multiply( cnt[ch]! )`.

### Complexity Analysis

Precomputing the `fact` array takes `O(N)` time and `O(N)` space.

The map `m` takes `O(M)` space, where `M` is the size of the character space. `M=26` in this question.

In the `for` loop, we take `O(M)` time to traverse the `m` to compute the `div` and `count`. The `modpow` takes `O(log(MOD))` time.

So the `for` loop takes `O(NM * log(MOD))` time.

The solution overall takes `O(NM * log(MOD))` time and `O(N)` space.

### Trick of the division with mod

Since we need to divide `Multiply( cnt[ch]! )` which might result in `0` when the numerator is smaller than it after `mod`. 

We can use [Fermat's little theorem](https://en.wikipedia.org/wiki/Fermat%27s_little_theorem) to make fast divisions.

Fermat's little theorem states that if $p$ is a prime number, then for any integer $a$, the number $a^p − a$ is an integer multiple of $p$. In the notation of modular arithmetic, this is expressed as

$$ a^p \equiv a \pmod p $$

If $a$ is not divisible by $p$, Fermat's little theorem is equivalent to the statement that $a^{p − 1} − 1$ is an integer multiple of $p$, or in symbols:

$$ a^{p-1} \equiv 1 \pmod p $$
For example, if $a = 2$ and $p = 7$, then $26 = 64$, and $64 − 1 = 63 = 7 × 9$ is thus a multiple of $7$.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/
// Author: github.com/lzl124631x
// Time: O(NM * log(MOD))
// Space: O(N)
class Solution {
    long modpow(long base, long exp, long mod) {
        long ans = 1;
        while (exp) {
            if (exp & 1) ans = (ans * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return ans;
    }
public:
    int makeStringSorted(string s) {
        long N = s.size(), cnt[26] = {}, mod = 1e9 + 7, ans = 0;
        vector<long> fact(N + 1, 1);
        for (int i = 1; i <= N; ++i) fact[i] = (fact[i - 1] * i) % mod;
        for (int i = N - 1; i >= 0; --i) {
            ++cnt[s[i] - 'a'];
            long less = 0, div = 1;
            for (int j = 0; j < 26; ++j) {
                if (j < s[i] - 'a') less += cnt[j];
                div = (div * fact[cnt[j]]) % mod;
            }
            ans = (ans + less * fact[N - i - 1] % mod * modpow(div, mod - 2, mod) % mod) % mod;
        }
        return ans;
    }
};
```

## Thought during contest

During contest, I was blocked by the cases where there are duplicate letters.

I think this is a DP problem that we can use memo to reduce computation.

Consider sequence `s=41235`:

In the first operation, we swap `4` with `3` (`s=31245`), then reversing results in `s=35421`. We can see that after `3`, the sequence is strictly decreasing.

Then we will need to do a sequence of operations to reverse this strictly decreasing part to make `s=31245`.

Let `dec[i]` be the number of operations needed to sort a strictly descreasing sequence of length `i`. Thus far we've done `1 + dec[4]` operations.

Then we swap `3` with `2` and reverse, resulting in `s=25431`. And we need another `dec[i]` operations to sort the decreasing part, resulting in `s=21345`. We took another `1 + dec[4]` operations.

Similarly, swapping `2` with `1` and reverse then sorting will take another `1 + dec[4]` operations.

So overall, we took `3 * (1 + dec[4])` operations. Multiplying by `3` is because there are `3` numbers (`123`) that are smaller `4` and after `4` in `s=41235`. And the `4` in `dec[4]` is because there are `4` numbers (`1235`) after the `4` in `s=41235`.

So we can scan from the rear of the array, find the first reversed consecutive sequence `s[i-1]` and `s[i]` (in the above case it's `41`), then we can find `j` using binary search since the numbers `s[i..(N-1)]` must be sorted already. We need `(j - i + 1) * (1 + dec[N - i])` operations to sort `s[(i-1)..(N-1)]`.

Now consider `dec[i]`:

```
dec[1] = 0
dec[2] = 1
```

For `3`, `s=321`, we need:
1. sorting the `21` part needing `dp[2] = 1` step. The result is `312`.
2. For `312`, we can use the `(j - i + 1) * (1 + dec[N - i])` formula. Here `i = 1, j = 2, N = 3`, so we need `4` operations to sort it.

So `dec[3] = 1 + 2 * (1 + dec[2]) = 5`

So, the pattern is

```
dec[1] = 0
dec[2] = 1
dec[i] = 1 + (i - 1) * (1 + dec[i - 1])    where i >= 3
```

So far so good. But when there are duplicates in the sequence, I didn't find a way to reuse the results.