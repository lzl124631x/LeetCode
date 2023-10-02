# [940. Distinct Subsequences II (Hard)](https://leetcode.com/problems/distinct-subsequences-ii/)

Given a string `S`, count the number of distinct, non-empty subsequences of `S` .

Since the result may be large, **return the answer modulo `10^9 + 7`**.

**Example 1:**

**Input:** "abc"  
**Output:** 7  
**Explanation**: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

**Example 2:**

**Input:** "aba"  
**Output:** 6  
**Explanation**: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".

**Example 3:**

**Input:** "aaa"
**Output:** 3  
**Explanation**: The 3 distinct subsequences are "a", "aa" and "aaa".

**Note:**

1.  `S` contains only lowercase letters.
2.  `1 <= S.length <= 2000`

## Thoughts

There are `2^N - 1` subsequences because for each letter you can either choose or not choose it which results in `2^N` and `-1` is to remove empty string.

One naive solution is to generate all the subsequences and deduplicate using `unordered_set`. But this is too time and space inefficient.

Can we reduce the complexity?

Try divide and conquer?

Split `S` into `S1` and `S2`.

**Example:**  
`aaab` => `aa` and `ab`  
`R(aaab)` = `a, aa, aaa, ab, aab, aaab`  
`R(aa)` = `a, aa`  
`R(ab)` = `a, b, ab`  
`R(aaab)` is not a simple addition or multiplication of `R(aa)` and `R(ab)`.

This idea doesn't seem to work :(

## Solution 1. DP

Try consume the letters one by one?

When we visit a new letter `S[i]`, we have two options -- pick it or don't pick it. Denote the results as `P(i)` and `N(i)` respectively.
1. If don't pick, then `N(i) = N(i - 1) + P(i - 1)`.
1. If pick, we can try to append `S[i]` to all the subsequences previously generated, yielding `N(i - 1) + P(i - 1)` subsequences. But all the previously generated subsequences ending with the same letter as `S[i]` will be duplicate with the subsequences ending with exactly this `S[i]`. So `P(i) = N(i - 1) + P(i - 1) - Sum{P(k) | where S[k] == S[i]}`.

Let's use 2-d array `dp` to store the results. `dp[1][i]` means "pick `S[i - 1]`" while `dp[0][i]` means "don't pick `S[i - 1]`", `1 <= i <= N`.

```
// For 1 <= i <= N
dp[0][i] = dp[0][i - 1] + dp[1][i - 1]
dp[1][i] = dp[0][i] - Sum{ dp[1][k] | where S[k - 1] == S[i - 1] }

dp[0][0] = 1
dp[1][0] = 0
```

It doesn't matter `dp[0][0]` or `dp[0][1]` as long as only one equals 1.

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int distinctSubseqII(string S) {
        int N = S.size(), mod = pow(10, 9) + 7;
        vector<vector<long long>> dp(2, vector<long long>(N + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod;
            dp[1][i] = dp[0][i];
            for (int j = 1; j < i; ++j) {
                if (S[i - 1] == S[j - 1]) dp[1][i] = (dp[1][i] - dp[1][j] + mod) % mod;
            }
        }
        return (dp[0][N] + dp[1][N] - 1) % mod;
    }
};
```

## Solution 2.

In the formula of Solution 1, we notice that `dp[?][i]` almost just rely on the `dp[?][i - 1]`.

The `dp` array is mainly for computing the the sum of duplicates. And the iterative summation 

If we store the sum of previous `dp[1][k]` where `S[k - 1] == S[i - 1]`, we can reduce the `2N` extra space to constant space.

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int distinctSubseqII(string S) {
        int N = S.size(), mod = pow(10, 9) + 7;
        int picks[26] = {0};
        int pick = 0, noPick = 1;
        for (int i = 0; i < N; ++i) {
            noPick = (noPick + pick) % mod;
            pick = (noPick - picks[S[i] - 'a'] + mod) % mod;
            picks[S[i] - 'a'] = (picks[S[i] - 'a'] + pick) % mod;
        }
        return (pick + noPick - 1) % mod;
    }
};
```

## Solution 3.

Same idea as Solution 2, but shorter and unnoticeably slower (it's `O(26N)` while solution 2 is real `O(N)`).

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/distinct-subsequences-ii/discuss/192017/C%2B%2BJavaPython-4-lines-O(N)-Time-O(1)-Space
class Solution {
public:
    int distinctSubseqII(string S) {
        long endsWith[26] = {}, mod = 1e9 + 7;
        for (char c : S)
            endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1L) % mod;
        return accumulate(begin(endsWith), end(endsWith), 0L) % mod;
    }
};
```

## Solution 4

In solution 2 we notice that we always sum `pick` and `noPick`, meaning we only care about the sum. 

```cpp
// OJ: https://leetcode.com/problems/distinct-subsequences-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/distinct-subsequences-ii/discuss/192095/C%2B%2B-O(n)-or-O-(n)-Geeks4Geeks-improved-to-O(n)-or-O(1)
class Solution {
public:
    int distinctSubseqII(string S) {
        int mod = pow(10, 9) + 7, picks[26] = {0}, sum = 1;
        for (char c : S) {
            int oldSum = sum;
            sum = (sum * 2 % mod - picks[c - 'a'] + mod) % mod;
            picks[c - 'a'] = oldSum;
        }
        return sum - 1;
    }
};
```