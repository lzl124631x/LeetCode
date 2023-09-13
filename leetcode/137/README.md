# [137. Single Number II (Medium)](https://leetcode.com/problems/single-number-ii)

<p>Given an integer array <code>nums</code> where&nbsp;every element appears <strong>three times</strong> except for one, which appears <strong>exactly once</strong>. <em>Find the single element and return it</em>.</p>

<p>You must&nbsp;implement a solution with a linear runtime complexity and use&nbsp;only constant&nbsp;extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,3,2]
<strong>Output:</strong> 3
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0,1,0,1,0,1,99]
<strong>Output:</strong> 99
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>Each element in <code>nums</code> appears exactly <strong>three times</strong> except for one element which appears <strong>once</strong>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Single Number (Easy)](https://leetcode.com/problems/single-number/)
* [Single Number III (Easy)](https://leetcode.com/problems/single-number-iii/)


## Note

Basically this problem asks us to implement a ternary system that when a digit reaches 3, this digit should be reset to 0.

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

## Solution 2. Bit Manipulation

Instead of counting each bit separately, we compute all the bits together.

Since we are simulating a ternary system, we need two binary bits to represent each ternary digit. 

$(00)_2 = (0)_3$

$(01)_2 = (1)_3$

$(10)_2 = (2)_3$

$(11)_2 = (0)_3$ When the ternary digit becomes 3, we reset it to 0 instead of carrying it over to the higher digit

We use `high`/`low` to represent all the left-/right-most bits of each ternary digit.

`high` and `low` won't have 1 at the same bit index, because it means that the ternary digit is 3 and should be reset to 0.

For each number `n` in `nums` array:
1. For the bit 1s that `n` and `low` DO NOT share in common (i.e. `n ^ low`), they are left as the new `low`. So, `newLow = low ^ n`
2. For the bit 1s that `n` and `low` share in common (i.e. `n & low`), they become new `high` digits. Together with the old `high` digits, `newHigh = high | (n & low)`.
3. If `newLow` and `newHigh` share any digit 1s in common, they should be reset to 0. So we should remove `newLow & newHigh` from `newLow` and `newHigh`

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