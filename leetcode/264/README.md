# [264. Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii/)

<p>Write a program to find the <code>n</code>-th ugly number.</p>

<p>Ugly numbers are<strong> positive numbers</strong> whose prime factors only include <code>2, 3, 5</code>.&nbsp;</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> n = 10
<strong>Output:</strong> 12
<strong>Explanation: </strong><code>1, 2, 3, 4, 5, 6, 8, 9, 10, 12</code> is the sequence of the first <code>10</code> ugly numbers.</pre>

<p><strong>Note: </strong>&nbsp;</p>

<ol>
	<li><code>1</code> is typically treated as an ugly number.</li>
	<li><code>n</code> <b>does not exceed 1690</b>.</li>
</ol>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Heap](https://leetcode.com/tag/heap/)

**Similar Questions**:
* [Merge k Sorted Lists (Hard)](https://leetcode.com/problems/merge-k-sorted-lists/)
* [Count Primes (Easy)](https://leetcode.com/problems/count-primes/)
* [Ugly Number (Easy)](https://leetcode.com/problems/ugly-number/)
* [Perfect Squares (Medium)](https://leetcode.com/problems/perfect-squares/)
* [Super Ugly Number (Medium)](https://leetcode.com/problems/super-ugly-number/)
* [Ugly Number III (Medium)](https://leetcode.com/problems/ugly-number-iii/)

## Solution 1. DP

Assume we've already computed the first `n` ugly numbers and stored them in vector `v`, the next ugly number must be the smallest one among `v[i] * 2  > v[n-1]`, `v[j] * 3] > v[n-1]` and `v[k] * 5 > v[n-1]` where `i, j, k` are some indexes in range `[0, n)`.

```cpp
// OJ: https://leetcode.com/problems/ugly-number-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> num(n);
        num[0] = 1;
        int i = 0, j = 0, k = 0;
        for (int t = 1; t < n; ++t) {
            num[t] = min({ num[i] * 2, num[j] * 3, num[k] * 5 });
            if (num[t] == num[i] * 2) ++i;
            if (num[t] == num[j] * 3) ++j;
            if (num[t] == num[k] * 5) ++k;
        }
        return num.back();
    }
};
```

Another implementation.

```cpp
// OJ: https://leetcode.com/problems/ugly-number-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> num(n, 1), index(3, 0), val{2, 3, 5};
        for (int i = 1; i < n; ++i) {
            int next = INT_MAX;
            for (int j = 0; j < 3; ++j) next = min(next, num[index[j]] * val[j]);
            for (int j = 0; j < 3; ++j) {
                if (num[index[j]] * val[j] == next) ++index[j];
            }
            num[i] = next;
        }
        return num.back();
    }
};
```