# [829. Consecutive Numbers Sum (Hard)](https://leetcode.com/problems/consecutive-numbers-sum/)

<p>Given a positive integer&nbsp;<code>N</code>, how many ways can we write it as a sum of&nbsp;consecutive positive integers?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>5
<strong>Output: </strong>2
<strong>Explanation: </strong>5 = 5 = 2 + 3</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>9
<strong>Output: </strong>3
<strong>Explanation: </strong>9 = 9 = 4 + 5 = 2 + 3 + 4</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>15
<strong>Output: </strong>4
<strong>Explanation: </strong>15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5</pre>

<p><strong>Note:</strong>&nbsp;<code>1 &lt;= N &lt;= 10 ^ 9</code>.</p>


**Companies**:  
[Visa](https://leetcode.com/company/visa)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

The sum of Arithmetic Progression (AP) is:

```
S = an + n(n-1)d/2
```

where `a` is the first element, `n` is the count of elements, `d` is the common difference.

In our case, `S = N`, `d = 1` so we have:

```
a = (N - n(n-1)/2) / n
```

So we can traverse from `n = 1` to `n = N` to get `a`, but they need to satisfy the following requirements:

1. `a = (N - n(n-1)/2) / n >= 1` so `2N - n^2 + n >= 2n`, `n(n+1) <= 2N`. For `n >= 1`, `n(n+1) > n^2` so `n^2 < 2N`, `n < sqrt(2N)`. For `N >= 1`, `n < sqrt(2N)` is the same or tighter than `n <= N`, so we can simply use `n(n+1) <= 2N` as the upper bound.
2. The last element `a + n - 1 <= N` so
```
(N - n(n-1)/2)/n + n - 1 <= N
2N - n(n-1) + 2n(n-1) <= 2nN
n(n-1) <= 2(n-1)N
n = 1 or n <= 2N
```
This is useless.

In sum, we traverse from `n = 1` to `n(n+1) <= 2N`, and if `N - n(n-1)/2` can be divided by `n`, we can increment the count.

```cpp
// OJ: https://leetcode.com/problems/consecutive-numbers-sum/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int n = 1; n * (n + 1) <= 2 * N; ++n) {
            int a = N - n * (n - 1) / 2;
            if (a % n == 0) ++ans;
        }
        return ans;
    }
};
```

## Solution 2.

There are lots of multiplication in Solution 1. Is it possible to reduce them?

If we let `n(n+1)` as `s`. In the previous loop, `s' = n(n-1)`, `s - s' = 2n`. So we can change the multiplication to addition.

Now let `s = n(n+1)/2`, the upper bound of `n` will be `s <= N`. In each step, we do `s += n`. And the `a` can be `N - s + n` now. We can further simply `a % n == 0` to `(N - s) % n == 0` since if `(N - s + n) % n == 0` then `(N - s) % n == 0`

```cpp
// OJ: https://leetcode.com/problems/consecutive-numbers-sum/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0, n = 1, s = 1;
        for (; s <= N; s += ++n) {
            if ((N - s) % n == 0) ++ans;
        }
        return ans;
    }
};
```

## Solution 3.

Assume `N=(x+1)+(x+2)+...+(x+k)`, where `x >= 0`, `k >= 1`.

We have `2N=k(2x+k+1)`, which has two factors, `k` and `2x+k+1`, one of which is odd number and another is even. So the question now is how many ways to factor `2N` into one even and one odd number.

Assume `2N=2^t * M`, where `M` is odd. If we factor `M = a * b`, then multiply `2^t` to one of them will yield the even number. So the question now becomes how many ways to factor the odd part of `N`.

If `N = 3*3*3*5*5`, how many ways to factor `N` into two numbers?

For one number, we can pick 0 to 3 `3`s, and 0 to 2 `5`s, so we have 4 * 3 = 12 options.

Here you can see the answer is multiplication of `1 + {count of a factor}`.

To get the count, we can start from `d = 3` to `d * d <= N` with increment 2, and try to divide `N` with d to count the occurrance of `d` in `N`. If the count is `c`, we multiply `1 + c` to answer.

But what if there is a factor greater than `sqrt(N)`? In this case it have to be a prime number and there will be only one of it. So if eventually `N > 1`, we multiply `2` to answer.

```cpp
// OJ: https://leetcode.com/problems/consecutive-numbers-sum/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
// Ref: https://leetcode.com/problems/consecutive-numbers-sum/solution/
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        while ((N & 1) == 0) N >>= 1;
        int ans = 1, d = 3;
        while (d * d <= N) {
            int e = 0;
            for (; N % d == 0; N /= d, ++e);
            ans *= e + 1;
            d += 2;
        }
        if (N > 1) ans <<= 1;
        return ans;
    }
};
```