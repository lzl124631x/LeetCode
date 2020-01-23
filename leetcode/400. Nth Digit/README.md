# [400. Nth Digit (Medium)](https://leetcode.com/problems/nth-digit/)

<p>Find the <i>n</i><sup>th</sup> digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... </p>

<p><b>Note:</b><br>
<i>n</i> is positive and will fit within the range of a 32-bit signed integer (<i>n</i> &lt; 2<sup>31</sup>).
</p>

<p><b>Example 1:</b>
</p><pre><b>Input:</b>
3

<b>Output:</b>
3
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre><b>Input:</b>
11

<b>Output:</b>
0

<b>Explanation:</b>
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
</pre>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

There are `9` one-digit numbers (`1 ~ 9`) which have `1 * 9 = 9` digits in total.

There are `90` two-digit numbers (`10 ~ 99`) which have `2 * 90 = 180` digits in total.

There are `900` three-digit numbers (`100 ~ 999`) which have `3 * 900 = 2700` digits in total.

There are `9000` four-digit numbers (`1000 ~ 9999`) which have `4 * 9000 = 36000` digits in total.

...

Assume number `k` contains the `n`th digit. To find out the value of the `n`th digit, we'd better know the value of `k` and the index of the digit within `k`.

Assume `n = 361`, then `k` must be a three-digit number because `361 > 9 + 180 = 189` and `361 < 9 + 180 + 2700 = 2889`.

So `n` is the `361 - 9 - 180 - 1 = 171`st digit within the three-digit numbers, and it's within the `floor(171 / 3) = 57`th number. So `k = 100 + 57 = 157`.

And `n` is the `171 % 3 = 0`st digit within `k`, i.e. `1`.

Now we can generalize this algorithm.

We keep subtracting `cnt = 9 * len * pow(10, len - 1)` from `n` until `n` is not greater than `cnt`.

Then `n - 1` is the index of the digit within the `len`-digit numbers.

Then we have `k = pow(10, len - 1) + (n - 1) / len` and `r = (n - 1) % len`.

The last step is simply get the `r`th digit within `k`.

```cpp
// OJ: https://leetcode.com/problems/nth-digit/
// Author: github.com/lzl124631x
// Time: O(lgN)
// Space: O(1)
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, p = 1, cnt = 9;
        while (n > cnt) {
            n -= cnt;
            ++len;
            cnt = 9 * len * (p *= 10);
        }
        int k = p + (n - 1) / len, r = (n - 1) % len, i = len - r - 1;
        while (i--) k /= 10;
        return k % 10;
    }
};
```