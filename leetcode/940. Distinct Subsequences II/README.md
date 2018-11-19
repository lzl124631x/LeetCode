# [940. Distinct Subsequences II (Hard)](https://leetcode.com/contest/weekly-contest-110/problems/distinct-subsequences-ii/)

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

## Solution 1. DP

How many subsequences? `2^N - 1` because for each character you can either choose or not choose it which results in `2^N` and `-1` is to remove empty string.

Can we reduce the complexity to `O(N^2)`?

Split `S` into `S1` and `S2`.

`aaab` => `aa` and `ab`
R(aaab) = `a, aa, aaa, ab, aab, aaab`
R(aa) = `a, aa`
R(ab) = `a, b, ab`
R(aaab) is not a simple addition or multiplication of R(aa) and R(ab).

`aaba`.

Assume we already resolved R(aab) = `a, b, aa, ab, aab`. Append `a` to it, R(aaba) = `aa, ba, aaa, aba, aaba`

Biggest issue in my mind. How to dedup? I think I have to use set. But the result is so large that it can't fit in one set.