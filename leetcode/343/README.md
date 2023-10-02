# [343. Integer Break (Medium)](https://leetcode.com/problems/integer-break/)

<p>Given a positive integer <i>n</i>, break it into the sum of <b>at least</b> two positive integers and maximize the product of those integers. Return the maximum product you can get.</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">2</span>
<strong>Output: </strong><span id="example-output-1">1</span>
<strong>Explanation: </strong>2 = 1 + 1, 1 × 1 = 1.</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">10</span>
<strong>Output: </strong><span id="example-output-2">36</span>
<strong>Explanation: </strong>10 = 3 + 3 + 4, 3 ×&nbsp;3 ×&nbsp;4 = 36.</pre>

<p><b>Note</b>: You may assume that <i>n</i> is not less than 2 and not larger than 58.</p>
</div>
</div>

**Companies**:  
[Google](https://leetcode.com/company/google), [Tencent](https://leetcode.com/company/tencent)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

Assume the result is `F(n)`. We can try different partition of `n`, from `1, n-1`, `2, n-2` to `ceil(sqrt(n)), n - ceil(sqrt(n))`.

```cpp
// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo(59, 0);
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) 
            for (int j = 1, b = ceil(sqrt(i)); j <= b; ++j)
                memo[i] = max(memo[i], max(j, memo[j]) * max(i - j, memo[i - j]));
        return memo[n];
    }
};
```

## Solution 2.

Try to find pattern.

```
F(2) = 1
F(3) = 1*2 = 2
F(4) = 2*2 = 4
F(5) = 2*3 = 6
F(6) = 3*3 = 9
F(7) = 2*2*3 = 12 = F(4) * 3
F(8) = 2*3*3 = 18 = F(5) * 3
F(9) = 3*3*3 = 27 = F(6) * 3
F(10) = 2*2*3*3 = 36 = F(7) * 3
...
```

**2** and **3** are the only two factors used.

4 is not used since we can use `2*2` instead.

5 is not used since if we split `5` into `2, 3` we can get larger result.

And so on.

Since number `5`, we can always factor out `3` first.

So we can compute from `F(5)` to `F(n)` using `F(i) = 3 * max(i - 3, F(i - 3))`.

```cpp
// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int integerBreak(int n) {
        int dp[max(n + 1, 5)];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        for (int i = 5; i <= n; ++i)
            dp[i] = 3 * max(i - 3, dp[i - 3]);
        return dp[n];
    }
};
```

What's the math behind it?

Reference: https://discuss.leetcode.com/topic/43055/why-factor-2-or-3-the-math-behind-this-problem/11
> @StefanPochmann:  
If an optimal product contains a factor `f >= 4`, then you can replace it with factors 2 and `f-2` without losing optimality, as `2*(f-2) = 2f-4 >= f`. So you never need a factor greater than or equal to 4, meaning you only need factors 1, 2 and 3 (and 1 is of course wasteful and you'd only use it for `n=2` and `n=3`, where it's needed).  
`3*3` is simply better than `2*2*2`, so you'd never use 2 more than twice.

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        return 3 * max(n - 3, integerBreak(n - 3));
    }
};
```

How to omit `max`?

6 = 3 + 3 and f(3) = 2 so 6 needs `max`

7 = 3 + 4 and f(4) = 4 so 7 is the first number that doesn't need `max`

So another version:
```cpp
// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/43042/easy-to-understand-c-with-explanation
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        if (n == 5) return 6;
        if (n == 6) return 9;
        return 3 * integerBreak(n - 3);
    }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/45341/a-simple-explanation-of-the-math-part-and-a-o-n-solution
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int p = 1;
        while (n > 4) {
            p *= 3;
            n -= 3;
        }
        p *= n;
        return p;
    }
};
```

## Solution 5.

```cpp
// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        if (n % 3 == 0) return pow(3, n / 3);
        if (n % 3 == 1) return pow(3, n / 3 - 1) * 2 * 2;
        return pow(3, n / 3) * 2;
    }
};
```