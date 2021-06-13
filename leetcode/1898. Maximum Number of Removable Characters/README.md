# [1898. Maximum Number of Removable Characters (Medium)](https://leetcode.com/problems/maximum-number-of-removable-characters/)

<p>You are given two strings <code>s</code> and <code>p</code> where <code>p</code> is a <strong>subsequence </strong>of <code>s</code>. You are also given a <strong>distinct 0-indexed </strong>integer array <code>removable</code> containing a subset of indices of <code>s</code> (<code>s</code> is also <strong>0-indexed</strong>).</p>

<p>You want to choose an integer <code>k</code> (<code>0 &lt;= k &lt;= removable.length</code>) such that, after removing <code>k</code> characters from <code>s</code> using the <strong>first</strong> <code>k</code> indices in <code>removable</code>, <code>p</code> is still a <strong>subsequence</strong> of <code>s</code>. More formally, you will mark the character at <code>s[removable[i]]</code> for each <code>0 &lt;= i &lt; k</code>, then remove all marked characters and check if <code>p</code> is still a subsequence.</p>

<p>Return <em>the <strong>maximum</strong> </em><code>k</code><em> you can choose such that </em><code>p</code><em> is still a <strong>subsequence</strong> of </em><code>s</code><em> after the removals</em>.</p>

<p>A <strong>subsequence</strong> of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcacb", p = "ab", removable = [3,1,0]
<strong>Output:</strong> 2
<strong>Explanation</strong>: After removing the characters at indices 3 and 1, "a<s><strong>b</strong></s>c<s><strong>a</strong></s>cb" becomes "accb".
"ab" is a subsequence of "<strong><u>a</u></strong>cc<strong><u>b</u></strong>".
If we remove the characters at indices 3, 1, and 0, "<s><strong>ab</strong></s>c<s><strong>a</strong></s>cb" becomes "ccb", and "ab" is no longer a subsequence.
Hence, the maximum k is 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
<strong>Output:</strong> 1
<strong>Explanation</strong>: After removing the character at index 3, "abc<s><strong>b</strong></s>ddddd" becomes "abcddddd".
"abcd" is a subsequence of "<u><strong>abcd</strong></u>dddd".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abcab", p = "abc", removable = [0,1,2,3,4]
<strong>Output:</strong> 0
<strong>Explanation</strong>: If you remove the first index in the array removable, "abc" is no longer a subsequence.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= p.length &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= removable.length &lt; s.length</code></li>
	<li><code>0 &lt;= removable[i] &lt; s.length</code></li>
	<li><code>p</code> is a <strong>subsequence</strong> of <code>s</code>.</li>
	<li><code>s</code> and <code>p</code> both consist of lowercase English letters.</li>
	<li>The elements in <code>removable</code> are <strong>distinct</strong>.</li>
</ul>


**Companies**:  
[alphonso](https://leetcode.com/company/alphonso)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Answer

This problem has monotonicity in it -- there must be a `k` that for all `i <= k`, removing the first `i` characters is valid; for all `i > k`, removing the first `i` characters is invalid. 

We can use binary search to search this maximum valid `k`.

The search range is `[0, N]`.

We just need to define a `valid(k)` function which can be done in `O(N)` time..

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-removable-characters/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    int rm[100001] = {};
    bool valid(string &s, string &p, vector<int> &A, int k) {
        memset(rm, 0, sizeof(rm));
        for (int i = 0; i < k; ++i) rm[A[i]] = 1; // mark this index as removed
        int N = s.size(), M = p.size(), j = 0; // `j` is the number of characters in `p` we matched with `s`
        for (int i = 0; i < N && j < M; ++i) {
            if (rm[i] == 1) continue; // this character is removed, skip
            if (s[i] == p[j]) ++j; // found a match, increment `j`
        }
        return j == M; // if `j` reaches the end of `p`, `p` is still a subsequence of `s`.
    }
public:
    int maximumRemovals(string s, string p, vector<int>& A) {
        int L = 0, R = A.size();
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(s, p, A, M)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```