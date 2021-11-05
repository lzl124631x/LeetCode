# [441. Arranging Coins (Easy)](https://leetcode.com/problems/arranging-coins/)

<p>You have <code>n</code> coins and you want to build a staircase with these coins. The staircase consists of <code>k</code> rows where the <code>i<sup>th</sup></code> row has exactly <code>i</code> coins. The last row of the staircase <strong>may be</strong> incomplete.</p>

<p>Given the integer <code>n</code>, return <em>the number of <strong>complete rows</strong> of the staircase you will build</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/09/arrangecoins1-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> Because the 3<sup>rd</sup> row is incomplete, we return 2.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/09/arrangecoins2-grid.jpg" style="width: 333px; height: 333px;">
<pre><strong>Input:</strong> n = 8
<strong>Output:</strong> 3
<strong>Explanation:</strong> Because the 4<sup>th</sup> row is incomplete, we return 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[Salesforce](https://leetcode.com/company/salesforce)

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

Or use `L < R`

```cpp
// OJ: https://leetcode.com/problems/arranging-coins/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        int L = 1, R = n;
        while (L < R) {
            long M = R - (R - L) / 2, sum = M * (1 + M) / 2;
            if (sum <= n) L = M;
            else R = M - 1;
        }
        return L;
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