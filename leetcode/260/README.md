# [260. Single Number III (Medium)](https://leetcode.com/problems/single-number-iii/)

<p>Given an array of numbers <code>nums</code>, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>  <code>[1,2,1,3,2,5]</code>
<strong>Output:</strong> <code>[3,5]</code></pre>

<p><b>Note</b>:</p>

<ol>
	<li>The order of the result is not important. So in the above example, <code>[5, 3]</code> is also correct.</li>
	<li>Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?</li>
</ol>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Single Number (Easy)](https://leetcode.com/problems/single-number/)
* [Single Number II (Medium)](https://leetcode.com/problems/single-number-ii/)

## Solution 1.

Assume result numbers are `a` and `b`, and `x` is the result of XORing all the numbers.

For any bit `1` in `x`, it means `a` and `b` differs in this bit, and we can use this bit to group the numbers in two groups, one containing `a` and the other containing `b`.

`x ^ (x & (x - 1))` is a trick that we can use to extract the lowest bit `1`.

```cpp
// OJ: https://leetcode.com/problems/single-number-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& A) {
        int x = 0;
        for (int n : A) x ^= n;
        int lb = x & -(unsigned)x, a = 0;
        for (int n : A) {
            if (n & lb) a ^= n;
        }
        return {a, x ^ a};
    }
};
```