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
        unsigned ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (unsigned n : nums) {
                cnt = (cnt + ((n >> i) & 1)) % 3;
            }
            ans |= cnt << i;
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

## Solution 4.

`a ^ b` has `1` in the bits where the corresponding bits in `a` and `b` are different, and `0` in the others. `0011 ^ 0101 = 0110`

`a & ~b` has the same bits as in `a` expect that those bits that are `1` in `b` are cleared as `0`. `0011 & ~0101 = 0010`

To get the new `one`:
* 

```
                 n:  0 0 0 0 1 1 1 1
               one:  0 0 1 1 0 0 1 1
               two:  0 1 0 1 0 1 0 1

             one^n:  0 0 1 1 1 1 0 0 // The bits that are `1`s after adding `one` and `n`.
one = (one^n)&~two:  0 0 1 0 1 0 0 0 // The bits summing to `3` are cleared from `one^n`. They are the ones that are `1`s both in `one^n` and `two`.
             two^n:  0 1 0 1 1 0 1 0 // The bits that are `1`s after adding `two` and `n`.
      (two^n)&~one:  0 1 0 1 0 0 1 0 // The bits summing to `3` are cleared from `two^n`. They are the ones that are `1`s both in `two^n` and `one`.
```

```cpp
// OJ: https://leetcode.com/problems/single-number-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int n : nums) {
            one = (one ^ n) & ~two;
            two = (two ^ n) & ~one;
        }
        return one;
    }
};
```