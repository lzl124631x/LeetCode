# [866. Prime Palindrome (Medium)](https://leetcode.com/problems/prime-palindrome/)

<p>Given an integer n, return <em>the smallest <strong>prime palindrome</strong> greater than or equal to </em><code>n</code>.</p>

<p>An integer is <strong>prime</strong> if it has exactly two divisors: <code>1</code> and itself. Note that <code>1</code> is not a prime number.</p>

<ul>
	<li>For example, <code>2</code>, <code>3</code>, <code>5</code>, <code>7</code>, <code>11</code>, and <code>13</code> are all primes.</li>
</ul>

<p>An integer is a <strong>palindrome</strong> if it reads the same from left to right as it does from right to left.</p>

<ul>
	<li>For example, <code>101</code> and <code>12321</code> are palindromes.</li>
</ul>

<p>The test cases are generated so that the answer always exists and is in the range <code>[2, 2 * 10<sup>8</sup>]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 6
<strong>Output:</strong> 7
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 8
<strong>Output:</strong> 11
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> n = 13
<strong>Output:</strong> 101
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>8</sup></code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Sum of k-Mirror Numbers (Hard)](https://leetcode.com/problems/sum-of-k-mirror-numbers/)

## Solution 1. Enumerate Palindromes

Enumerate palindromes and return the first one that is `>= n` and is a prime.

```cpp
// OJ: https://leetcode.com/problems/prime-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
// Ref: https://leetcode.com/problems/prime-palindrome/solution/
class Solution {
    int getPalindrome(int half, bool odd) {
        string s = to_string(half);
        for (int i = s.size() - 1 - odd; i >= 0; --i) s += s[i];
        return stoi(s);
    }
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int d = 2; d * d <= n; ++d) {
            if (n % d == 0) return false;
        }
        return true;
    }
public:
    int primePalindrome(int n) {
        for (int len = 1; len <= 5; ++len) {
            for (int root = pow(10, len - 1); root < pow(10, len); ++root) { // Enumerate odd-length palindromes
                int pal = getPalindrome(root, true);
                if (pal >= n && isPrime(pal)) return pal;
            }
            for (int root = pow(10, len - 1); root < pow(10, len); ++root) { // Enumerate even-length palindromes
                int pal = getPalindrome(root, false);
                if (pal >= n && isPrime(pal)) return pal;
            }
        }
        return -1;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/prime-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getPalindrome(int half, bool odd) {
        int ans = half;
        if (odd) half /= 10;
        for (; half; half /= 10) ans = ans * 10 + half % 10;
        return ans;
    }
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    int primePalindrome(int n) {
        for (int len = log10(n) + 1; true; ++len) {
            int half = pow(10, (len - 1) / 2), end = half * 10;
            for (; half < end; ++half) {
                int pal = getPalindrome(half, len % 2);
                if (pal >= n && isPrime(pal)) return pal;
            }
        }
        return 0;
    }
};
```

## Solution 2. Brute Force with Mathematical Shortcut

All even-digit palindromes, except for 11, are not primes because they are divisible by `11`. For example, `2332 / 11 = 212`

```cpp
// OJ: https://leetcode.com/problems/prime-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/prime-palindrome/solution/
class Solution {
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int d = 2; d * d <= n; ++d) {
            if (n % d == 0) return false;
        }
        return true;
    }
    int reverse(int n) {
        int ans = 0;
        while (n > 0) {
            ans = 10 * ans + (n % 10);
            n /= 10;
        }
        return ans;
    }
public:
    int primePalindrome(int N) {
        while (true) {
            if (N == reverse(N) && isPrime(N)) return N;
            ++N;
            if (1e7 < N && N < 1e8) N = 1e8;
        }
    }
};
```

Another way for `primePalindrome`

```cpp
int digits(int n) {
    return (int)log10(n) + 1;
}
int primePalindrome(int n) {
    while (true) {
        if (n == reverse(n) && isPrime(n)) return n;
        ++n;
        if (n > 11 && digits(n) % 2 == 0) n = pow(10, digits(n));
    }
}
```