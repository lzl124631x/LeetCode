# [441. Arranging Coins (Easy)](https://leetcode.com/problems/arranging-coins/)

<p>You have a total of <i>n</i> coins that you want to form in a staircase shape, where every <i>k</i>-th row must have exactly <i>k</i> coins.</p>
 
<p>Given <i>n</i>, find the total number of <b>full</b> staircase rows that can be formed.</p>

<p><i>n</i> is a non-negative integer and fits within the range of a 32-bit signed integer.</p>

<p><b>Example 1:</b>
</p><pre>n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre>n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
</pre>
<p></p>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/arranging-coins/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        long i = 1, sum = 0;
        while (sum + i <= n) sum += i++;
        return i - 1;
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/arranging-coins/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        int L = 1, R = n;
        while (L <= R) {
            long M = L + (R - L) / 2, sum = M * (1 + M) / 2;
            if (sum == n) return M;
            if (sum < n) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```

## Solution 3. Math

```
x * (x + 1) / 2 <= n

x^2 + x - 2n <= 0

x <= (sqrt(8n + 1) - 1) / 2
```

```cpp
// OJ: https://leetcode.com/problems/arranging-coins/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt((long)8 * n + 1) - 1) / 2;
    }
};
```