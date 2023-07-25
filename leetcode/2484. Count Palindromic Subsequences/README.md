# [2484. Count Palindromic Subsequences (Hard)](https://leetcode.com/problems/count-palindromic-subsequences)

<p>Given a string of digits <code>s</code>, return <em>the number of <strong>palindromic subsequences</strong> of</em> <code>s</code><em> having length </em><code>5</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>
<p><strong>Note:</strong></p>
<ul>
	<li>A string is <strong>palindromic</strong> if it reads the same forward and backward.</li>
	<li>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "103301"
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301". 
Two of them (both equal to "10301") are palindromic.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "0000000"
<strong>Output:</strong> 21
<strong>Explanation:</strong> All 21 subsequences are "00000", which is palindromic.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "9999900000"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The only two palindromic subsequences are "99999" and "00000".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of digits.</li>
</ul>

**Companies**:
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Atlassian](https://leetcode.com/company/atlassian)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Arithmetic Slices II - Subsequence (Hard)](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/)
* [Count Different Palindromic Subsequences (Hard)](https://leetcode.com/problems/count-different-palindromic-subsequences/)
* [Unique Length-3 Palindromic Subsequences (Medium)](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/)

## Solution 1. DP

Let `left[a][b][i]` be the number of `ab` subsequences in `s[0..i]`, `right[a][b][i]` be the number of `ba` subsequences in `s[i..(N-1)]`, where `0 <= a, b <= 9`, `0 <= i < N`.

The answer is `SUM( left[a][b][i-1] * right[a][b][i+1] | 0 <= a, b <= 9 and 0 <= i < N )`

We can use the following to compute `left[a][b][i]`.

```
left[a][b][i] = left[a][b][i-1] + (s[i] == b ? ca[i-1] : 0)
```
where `ca[i]` is the number of character `a`s in `A[0..i]`.

```cpp
// OJ: https://leetcode.com/problems/count-palindromic-subsequences
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countPalindromes(string s) {
        long N = s.size(), mod = 1e9 + 7, ans = 0;
        vector<vector<vector<long>>> left(10, vector<vector<long>>(10, vector<long>(N))), right(10, vector<vector<long>>(10, vector<long>(N)));
        for (int a = 0; a <= 9; ++a) {
            for (int b = 0; b <= 9; ++b) {
                long ca = 0, cnt = 0;
                for (int i = 0; i < N; ++i) {
                    if (s[i] - '0' == b) cnt = (cnt + ca) % mod;
                    left[a][b][i] = cnt;
                    ca += s[i] - '0' == a;
                }
                ca = 0, cnt = 0;
                for (int i = N - 1; i >= 0; --i) {
                    if (s[i] - '0' == b) cnt = (cnt + ca) % mod;
                    right[a][b][i] = cnt;
                    ca += s[i] - '0' == a;
                }
            }
        }
        for (int i = 2; i < N - 2; ++i) {
            for (int a = 0; a <= 9; ++a) {
                for (int b = 0; b <= 9; ++b) {
                    ans = (ans + left[a][b][i - 1] * right[a][b][i + 1] % mod) % mod;
                }
            }
        }
        return ans;
    }
};
```