# [137. Single Number II (Medium)](https://leetcode.com/problems/single-number-ii/)

<p>Given a <strong>non-empty</strong>&nbsp;array of integers, every element appears <em>three</em> times except for one, which appears exactly once. Find that single one.</p>

<p><strong>Note:</strong></p>

<p>Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,2,3,2]
<strong>Output:</strong> 3
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [0,1,0,1,0,1,99]
<strong>Output:</strong> 99</pre>


## Solution 1. Bit Manipulation

For each bit for each number, if the bit is 1 for 3 times, reset it to 0. The leftover is the bit for the single number.

```cpp
// OJ: https://leetcode.com/problems/single-number-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = 0;
            for (int n : nums) {
                bit += (n >> i) & 1;
                if (bit >= 3) bit = 0;
            }
            ans |= bit << i;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/single-number-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            unsigned long bit = 0, mask = 1 << i;
            for (int n : nums) {
                bit += (unsigned)n & mask;
                if (bit % 3 == 0) bit = 0;
            }
            ans |= bit;
        }
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/single-number-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;
        for (int n : nums) {
            int newLow, newHigh;
            newLow = low ^ n;
            newHigh = high | (low & n);
            low = newLow ^ (newLow & newHigh);
            high = newHigh ^ (newLow & newHigh);
        }
        return low;
    }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/single-number-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;
        for (int n : nums) {
            high ^= low & n;
            low ^= n;
            unsigned mask = ~(high & low);
            high &= mask;
            low &= mask;
        }
        return low;
    }
};
```