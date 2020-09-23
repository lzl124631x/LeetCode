# [866. Prime Palindrome (Medium)](https://leetcode.com/problems/prime-palindrome/)

<p>Find the smallest prime palindrome greater than or equal to <code>N</code>.</p>

<p>Recall that a&nbsp;number is <em>prime</em> if it's only divisors are 1 and itself, and it is greater than 1.&nbsp;</p>

<p>For example, 2,3,5,7,11 and 13 are&nbsp;primes.</p>

<p>Recall that a number is a <em>palindrome</em> if it reads the same from left to right as it does from right to left.&nbsp;</p>

<p>For example, 12321 is a palindrome.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">6</span>
<strong>Output: </strong><span id="example-output-1">7</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">8</span>
<strong>Output: </strong><span id="example-output-2">11</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">13</span>
<strong>Output: </strong><span id="example-output-3">101</span></pre>
</div>
</div>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= N &lt;= 10^8</code></li>
	<li>The answer is guaranteed to exist and be less than <code>2 * 10^8</code>.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/prime-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
// Ref: https://leetcode.com/problems/prime-palindrome/solution/
class Solution {
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int d = 2, R = sqrt(x); d <= R; ++d) {
            if (x % d == 0) return false;
        }
        return true;
    }
public:
    int primePalindrome(int N) {
        for (int L = 1; L <= 5; ++L) {
            for (int root = pow(10, L - 1); root < pow(10, L); ++root) { // check for odd-length palindromes
                auto s = to_string(root);
                for (int k = L - 2; k >= 0; --k) s += s[k];
                int x = stoi(s);
                if (x >= N && isPrime(x)) return x;
            }
            for (int root = pow(10, L - 1); root < pow(10, L); ++root) {
                auto s = to_string(root);
                for (int k = L - 1; k >= 0; --k) s += s[k];
                int x = stoi(s);
                if (x >= N && isPrime(x)) return x;
            }
        }
        return -1;
    }
};
```

## Solution 2. Brute Force with Mathematical Shortcut

```cpp
// OJ: https://leetcode.com/problems/prime-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/prime-palindrome/solution/
class Solution {
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int d = 2, R = sqrt(x); d <= R; ++d) {
            if (x % d == 0) return false;
        }
        return true;
    }
    int reverse(int N) {
        int ans = 0;
        while (N > 0) {
            ans = 10 * ans + (N % 10);
            N /= 10;
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