# [201. Bitwise AND of Numbers Range (Medium)](https://leetcode.com/problems/bitwise-and-of-numbers-range/)

<p>Given a range [m, n] where 0 &lt;= m &lt;= n &lt;= 2147483647, return the bitwise AND of all numbers in this range, inclusive.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [5,7]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [0,1]
<strong>Output:</strong> 0</pre>

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int k = 1 << i, a = m / k, b = n / k;
            ans |= (a == b && a % 2) << i;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m && n && m != n) {
            m >>= 1;
            n >>= 1;
            ++count;
        }
        return m << count;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) n = n & (n - 1);
        return n;
    }
};
```