# [2081. Sum of k-Mirror Numbers (Hard)](https://leetcode.com/problems/sum-of-k-mirror-numbers/)

<p>A <strong>k-mirror number</strong> is a <strong>positive</strong> integer <strong>without leading zeros</strong> that reads the same both forward and backward in base-10 <strong>as well as</strong> in base-k.</p>

<ul>
	<li>For example, <code>9</code> is a 2-mirror number. The representation of <code>9</code> in base-10 and base-2 are <code>9</code> and <code>1001</code> respectively, which read the same both forward and backward.</li>
	<li>On the contrary, <code>4</code> is not a 2-mirror number. The representation of <code>4</code> in base-2 is <code>100</code>, which does not read the same both forward and backward.</li>
</ul>

<p>Given the base <code>k</code> and the number <code>n</code>, return <em>the <strong>sum</strong> of the</em> <code>n</code> <em><strong>smallest</strong> k-mirror numbers</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> k = 2, n = 5
<strong>Output:</strong> 25
<strong>Explanation:
</strong>The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
  base-10    base-2
    1          1
    3          11
    5          101
    7          111
    9          1001
Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> k = 3, n = 7
<strong>Output:</strong> 499
<strong>Explanation:
</strong>The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
  base-10    base-3
    1          1
    2          2
    4          11
    8          22
    121        11111
    151        12121
    212        21212
Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> k = 7, n = 17
<strong>Output:</strong> 20379000
<strong>Explanation:</strong> The 17 smallest 7-mirror numbers are:
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 30</code></li>
</ul>


**Companies**:  
[Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Enumeration](https://leetcode.com/tag/enumeration/)

**Similar Questions**:
* [Strobogrammatic Number II (Medium)](https://leetcode.com/problems/strobogrammatic-number-ii/)
* [Prime Palindrome (Medium)](https://leetcode.com/problems/prime-palindrome/)

## Solution 1. Generating Palindromes

Enumerate palindrom numbers in base-10 and check if the corresponding base-k number is also a palindrome.


```cpp
// OJ: https://leetcode.com/problems/sum-of-k-mirror-numbers/
// Author: github.com/lzl124631x
class Solution {
    long long getPalindrome(int half, bool odd) {
        long long n = half, tmp = half;
        if (odd) tmp /= 10;
        while (tmp) {
            n = n * 10 + tmp % 10;
            tmp /= 10;
        }
        return n;
    }
    bool isPalindromeBaseK(long long n, int k) {
        string s;
        while (n) {
            s += '0' + n % k;
            n /= k;
        }
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        for (int len = 1; true; ++len) {
            for (int half = pow(10, len - 1); half < pow(10, len); ++half) {
                auto pal = getPalindrome(half, true);
                if (isPalindromeBaseK(pal, k)) {
                    ans += pal;
                    if (--n == 0) return ans;
                }
            }
            for (int half = pow(10, len - 1); half < pow(10, len); ++half) {
                auto pal = getPalindrome(half, false);
                if (isPalindromeBaseK(pal, k)) {
                    ans += pal;
                    if (--n == 0) return ans;
                }
            }
        }
    }
};
```

Another implementation:

```cpp
// OJ: https://leetcode.com/problems/sum-of-k-mirror-numbers/
// Author: github.com/lzl124631x
class Solution {
    long getPalindrome(int half, bool odd) {
        long pal = half;
        if (odd) half /= 10;
        for (; half; half /= 10) pal = pal * 10 + half % 10;
        return pal;
    }
    bool isPalindromeBaseK(long n, int k) {
        long mul = 1;
        while (mul * k <= n) mul *= k;
        for (; n; mul /= k * k) {
            if (n / mul != n % k) return false;
            n = (n - (n / mul) * mul - n % k) / k;
        }
        return true;
    }
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        for (int len = 1; true; ++len) {
            int begin = pow(10, (len - 1) / 2), end = pow(10, (len + 1) / 2);
            for (int half = begin; half < end; ++half) {
                long pal = getPalindrome(half, len % 2);
                if (isPalindromeBaseK(pal, k)) {
                    ans += pal;
                    if (--n == 0) return ans;
                }
            }
        }
    }
};
```

Or we can do it in the reverse order -- enumerate palindrome numbers in base-k, then check if the corresponding base-10 number is a palindrome.

```cpp
// OJ: https://leetcode.com/problems/sum-of-k-mirror-numbers/
// Author: github.com/lzl124631x
class Solution {
    long long getPalindromeBaseK(int half, int k, bool odd) {
        long long ans = half;
        if (odd) half /= k;
        while (half) {
            ans = ans * k + half % k;
            half /= k;
        }
        return ans;
    }
    bool isPalindromeBase10(long long n) {
        string s;
        while (n) {
            s += '0' + n % 10;
            n /= 10;
        }
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        for (int len = 1; true; ++len) {
            for (int half = pow(k, len - 1); half < pow(k, len); ++half) {
                auto pal = getPalindromeBaseK(half, k, true);
                if (isPalindromeBase10(pal)) {
                    ans += pal;
                    if (--n == 0) return ans;
                }
            }
            for (int half = pow(k, len - 1); half < pow(k, len); ++half) {
                auto pal = getPalindromeBaseK(half, k, false);
                if (isPalindromeBase10(pal)) {
                    ans += pal;
                    if (--n == 0) return ans;
                }
            }
        }
    }
};
```