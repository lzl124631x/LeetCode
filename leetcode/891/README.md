# [891. Sum of Subsequence Widths (Hard)](https://leetcode.com/problems/sum-of-subsequence-widths/)

<p>The <strong>width</strong> of a sequence is the difference between the maximum and minimum elements in the sequence.</p>

<p>Given an array of integers <code>nums</code>, return <em>the sum of the <strong>widths</strong> of all the non-empty <strong>subsequences</strong> of </em><code>nums</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, <code>[3,6,2,7]</code> is a subsequence of the array <code>[0,3,1,6,2,2,7]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,3]
<strong>Output:</strong> 6
Explanation: The subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1. Sorting + Math

```cpp
// OJ: https://leetcode.com/problems/sum-of-subsequence-widths/
// Author: github.com/lzl124631x
// Time: O(NlogU) where `U` is the number of unique elements in `A`.
// Space: O(U)
class Solution {
    long mod = 1e9 + 7;
    long modpow(long base, long exp) {
        long ans = 1;
        while (exp) {
            if (exp & 1) ans = ans * base % mod;
            exp >>= 1;
            base = base * base % mod;
        }
        return ans;
    }
    long minus(long a, long b) {
        return (a - b + mod) % mod;
    }
public:
    int sumSubseqWidths(vector<int>& A) {
        map<int, int> m;
        for (int n : A) m[n]++;
        long ans = 0, first = 0, second = 0;
        for (auto j = m.begin(); j != m.end(); ++j) {
            long p = modpow(2, j->second);
            ans = (ans + minus(first * j->first, second) * minus(p, 1) % mod) % mod;
            first = (first * p % mod + minus(p, 1)) % mod;
            second = (second * p % mod + j->first * minus(p, 1) % mod) % mod;
        }
        return ans;
    }
};
```

## Solution 2. Sorting + Math

We can sort the array as it doesn't change the answer.

The number of subsequences with minimum `A[i]` and maximum `A[j]` is $2^{j-i-1}$.

The answer is:

$$ 
\sum\limits_{j>i}2^{j-i-1}\cdot(A_j-A_i)\\
=\sum\limits_{i=0}^{n-2}\sum\limits_{j=i+1}^{n-1}2^{j-i-1}\cdot(A_j-A_i)\\
=\sum\limits_{i=0}^{n-2}\sum\limits_{j=i+1}^{n-1}2^{j-i-1}\cdot A_j-\sum\limits_{i=0}^{n-2}\sum\limits_{j=i+1}^{n-1}2^{j-i-1}\cdot A_i\\
=\left[\left(2^0A_1+2^1A_2+\cdots+2^{n-2}A_{n-1}\right)+\left(2^0A_2+2^1A_3+\cdots+2^{n-3}A_{n-1}\right)+\cdots+(2^0A_{n-1})\right] -\left[\sum\limits_{i=0}^{n-2}\left(2^0+2^1+\cdots+2^{n-i-2}\right)A_i\right]\\
=\left[\sum\limits_{i=1}^{n-1}(2^i-1)A_i\right]-\left[\sum\limits_{i=0}^{n-2}(2^{n-i-1}-1)A_i\right]\\
=\sum\limits_{i=0}^{n-1}\left(2^i-2^{n-i-1}\right)A_i
$$

```cpp
// OJ: https://leetcode.com/problems/sum-of-subsequence-widths/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N) This can be improved to `O(1)` if we calculate the powers on the fly.
// Ref: https://leetcode.com/problems/sum-of-subsequence-widths/solution/
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(begin(A), end(A));
        long N = A.size(), ans = 0, mod = 1e9 + 7;
        vector<int> pow(N, 1);
        for (int i = 1; i < N; ++i) pow[i] = pow[i - 1] * 2 % mod;
        for (int i = 0; i < N; ++i) {
            ans = (ans + (pow[i] - pow[N - i - 1] + mod) % mod * A[i]) % mod;
        }
        return ans;
    }
};
```