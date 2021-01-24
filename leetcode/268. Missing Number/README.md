# [268. Missing Number (Easy)](https://leetcode.com/problems/missing-number/)

<p>Given an array containing <i>n</i> distinct numbers taken from <code>0, 1, 2, ..., n</code>, find the one that is missing from the array.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> [3,0,1]
<b>Output:</b> 2
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [9,6,4,2,3,5,7,0,1]
<b>Output:</b> 8
</pre>

<p><b>Note</b>:<br>
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive/)
* [Single Number (Easy)](https://leetcode.com/problems/single-number/)
* [Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number/)
* [Couples Holding Hands (Hard)](https://leetcode.com/problems/couples-holding-hands/)

## Solution 1. Sum of Arithmetic Sequence

```cpp
// OJ: https://leetcode.com/problems/missing-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& A) {
        return (1 + A.size()) * A.size() / 2 - accumulate(begin(A), end(A), 0);
    }
};
```

## Solution 2. XOR

```cpp
// OJ: https://leetcode.com/problems/missing-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), xorVal = 0;
        for (int i = 0; i < n; ++i) xorVal ^= nums[i] ^ (i + 1);
        return xorVal;
    }
};
```