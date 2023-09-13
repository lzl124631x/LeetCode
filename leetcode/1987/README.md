# [1987. Number of Unique Good Subsequences (Hard)](https://leetcode.com/problems/number-of-unique-good-subsequences/)

<p>You are given a binary string <code>binary</code>. A <strong>subsequence</strong> of <code>binary</code> is considered <strong>good</strong> if it is <strong>not empty</strong> and has <strong>no leading zeros</strong> (with the exception of <code>"0"</code>).</p>

<p>Find the number of <strong>unique good subsequences</strong> of <code>binary</code>.</p>

<ul>
	<li>For example, if <code>binary = "001"</code>, then all the <strong>good</strong> subsequences are <code>["0", "0", "1"]</code>, so the <strong>unique</strong> good subsequences are <code>"0"</code> and <code>"1"</code>. Note that subsequences <code>"00"</code>, <code>"01"</code>, and <code>"001"</code> are not good because they have leading zeros.</li>
</ul>

<p>Return <em>the number of <strong>unique good subsequences</strong> of </em><code>binary</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> binary = "001"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The good subsequences of binary are ["0", "0", "1"].
The unique good subsequences are "0" and "1".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> binary = "11"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The good subsequences of binary are ["1", "1", "11"].
The unique good subsequences are "1" and "11".</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> binary = "101"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The good subsequences of binary are ["1", "0", "1", "10", "11", "101"]. 
The unique good subsequences are "0", "1", "10", "11", and "101".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= binary.length &lt;= 10<sup>5</sup></code></li>
	<li><code>binary</code> consists of only <code>'0'</code>s and <code>'1'</code>s.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Distinct Subsequences (Hard)](https://leetcode.com/problems/distinct-subsequences/)
* [Distinct Subsequences II (Hard)](https://leetcode.com/problems/distinct-subsequences-ii/)

## Solution 1. DP

Let `dp[i+1]` be the number of unique good subsequences, **including empty subsequence**, in `s[0..i]`. The anwer is `dp[N] - 1` (`-1` to remove the empty sequence)

Let `dp[0] = 1` representing a empty subsequence.

**Step 1. Multiplying by 2**:

For `dp[i+1]`, we can start by appending `s[i]` to all subsequences represented by `dp[i]`, so `dp[i+1]` starts from `2 * dp[i]`.

For example, assume `s = "111"`, and `dp[2] = 3` represending `nil, 1, 11`. We can append `s[2] = 1` to them and get `1, 11, 111`. So `dp[i+1]` starts from `2 * dp[2] = 6` represending `nil, 1, 11` plus `1, 11, 111`.

**Step 2. Deduplication**:

Assume the last time we saw `s[i]` value was at index `j`. So `dp[j]` reprensents all the unique good subsequences in `s[0..(j-1)]`. This number of subsequences are counted twice in our previous computation because these subsequences ending with `s[j]` or `s[i]` yields the same set of subsequences.

For the above example, when computing `dp[3]`, we counted `dp[1] = 2` number of subsequences twice. `dp[1]` represents `nil, 1`. Appending `s[1] = 1` or `s[2] = 1` will get the same subsequences -- `1, 11`.

To dedup, we do `dp[i+1] = 2 * dp[i] - dp[j]`.

One caveat is that if `dp[j]` contains `0` subsequence, we can't append it to either `s[i]` or `s[j]`. So instead of `- dp[j]`, we should `- (dp[j] - zero[j])` where `zero[j] = 1` if we've seen `0` in `s[0..(j-1)]`; otherwise `zero[j] = 0`.

We can store this `dp[j] - zero[j]` in `dup[0]` and `dup[1]` respectively. 

So, `dp[i+1] = 2 * dp[i] - dup[s[i]-'0']`.

**Step 3. Remove leading zero**:

Lastly, if `dp[i]` includes subsequence `0`, we can't append `s[i]` to it. So we need to `- zero[i]`. 

Finally, `dp[i+1] = 2 * dp[i] - dup[s[i]-'0'] - zero[i]`.

In implementation, since `dp[i+1]` only depends on `dp[i]`, and `zero[i]` just means if we have seen `0` before -- `zero[i] = dup[0] > 0`, we can using a single value to track the `dp` values.

```cpp
// OJ: https://leetcode.com/problems/number-of-unique-good-subsequences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        long mod = 1e9 + 7, dup[2] = {}, ans = 1;
        for (char c : s) {
            int prev = ans, zero = dup[0] > 0;
            ans = (2 * ans - dup[c - '0'] - zero + mod) % mod;
            dup[c - '0'] = prev - zero;
        }
        return (ans - 1 + mod) % mod;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/number-of-unique-good-subsequences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/number-of-unique-good-subsequences/discuss/1431819/JavaC%2B%2BPython-DP-4-lines-O(N)-Time-O(1)-Space
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        long mod = 1e9 + 7, cnt[2] = {};
        for (char c : s) cnt[c - '0'] = (cnt[0] + cnt[1] + c - '0') % mod;
        return (cnt[0] + cnt[1] + (s.find('0') != string::npos)) % mod;
    }
};
```