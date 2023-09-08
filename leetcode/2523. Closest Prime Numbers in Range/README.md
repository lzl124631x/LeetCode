# [2523. Closest Prime Numbers in Range (Medium)](https://leetcode.com/problems/closest-prime-numbers-in-range)

<p>Given two positive integers <code>left</code> and <code>right</code>, find the two integers <code>num1</code> and <code>num2</code> such that:</p>
<ul>
	<li><code>left &lt;= nums1 &lt; nums2 &lt;= right </code>.</li>
	<li><code>nums1</code> and <code>nums2</code> are both <strong>prime</strong> numbers.</li>
	<li><code>nums2 - nums1</code> is the <strong>minimum</strong> amongst all other pairs satisfying the above conditions.</li>
</ul>
<p>Return <em>the positive integer array</em> <code>ans = [nums1, nums2]</code>. <em>If there are multiple pairs satisfying these conditions, return the one with the minimum</em> <code>nums1</code> <em>value or</em> <code>[-1, -1]</code> <em>if such numbers do not exist.</em></p>
<p>A number greater than <code>1</code> is called <b>prime</b> if it is only divisible by <code>1</code> and itself.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> left = 10, right = 19
<strong>Output:</strong> [11,13]
<strong>Explanation:</strong> The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> left = 4, right = 6
<strong>Output:</strong> [-1,-1]
<strong>Explanation:</strong> There exists only one prime number in the given range, so the conditions cannot be satisfied.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>6</sup></code></li>
</ul>
<p>&nbsp;</p>

**Companies**:
[TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Number Theory](https://leetcode.com/tag/number-theory/)

**Similar Questions**:
* [Count Ways to Make Array With Product (Hard)](https://leetcode.com/problems/count-ways-to-make-array-with-product/)

## Solution 1. Sieve of Eratosthenes

```cpp
// OJ: https://leetcode.com/problems/closest-prime-numbers-in-range
// Author: github.com/lzl124631x
// Time: O(NloglogN)
// Space: O(N)
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        vector<int> primes;
        int bound = sqrt(right), minDiff = INT_MAX, first = -1;
        for (int i = 2; i <= right; ++i) {
            if (!isPrime[i]) continue;
            if (i >= left) primes.push_back(i);
            if (i > bound) continue;
            for (int j = i * i; j <= right; j += i) isPrime[j] = false;
        }
        for (int i = 1; i < primes.size(); ++i) {
            int d = primes[i] - primes[i - 1];
            if (d < minDiff) {
                minDiff = d;
                first = i - 1;
            }
        }
        return first == -1 ? vector<int>{-1,-1} : vector<int>{primes[first], primes[first + 1]};
    }
};
```