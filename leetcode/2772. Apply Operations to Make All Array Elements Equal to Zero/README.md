# [2772. Apply Operations to Make All Array Elements Equal to Zero (Medium)](https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and a positive integer <code>k</code>.</p>
<p>You can apply the following operation on the array <strong>any</strong> number of times:</p>
<ul>
	<li>Choose <strong>any</strong> subarray of size <code>k</code> from the array and <strong>decrease</strong> all its elements by <code>1</code>.</li>
</ul>
<p>Return <code>true</code><em> if you can make all the array elements equal to </em><code>0</code><em>, or </em><code>false</code><em> otherwise</em>.</p>
<p>A <strong>subarray</strong> is a contiguous non-empty part of an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,3,1,1,0], k = 3
<strong>Output:</strong> true
<strong>Explanation:</strong> We can do the following operations:
- Choose the subarray [2,2,3]. The resulting array will be nums = [<strong><u>1</u></strong>,<strong><u>1</u></strong>,<strong><u>2</u></strong>,1,1,0].
- Choose the subarray [2,1,1]. The resulting array will be nums = [1,1,<strong><u>1</u></strong>,<strong><u>0</u></strong>,<strong><u>0</u></strong>,0].
- Choose the subarray [1,1,1]. The resulting array will be nums = [<u><strong>0</strong></u>,<u><strong>0</strong></u>,<u><strong>0</strong></u>,0,0,0].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,1,1], k = 2
<strong>Output:</strong> false
<strong>Explanation:</strong> It is not possible to make all the array elements equal to 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

**Companies**:
[Hudson River Trading](https://leetcode.com/company/hudson-river-trading)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Continuous Subarray Sum (Medium)](https://leetcode.com/problems/continuous-subarray-sum/)
* [Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold (Medium)](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)

## Solution 1. Diff Array

```cpp
// OJ: https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool checkArray(vector<int>& A, int k) {
        int N = A.size(), d = 0; 
        vector<int> diff(N + 1); 
class Solution {
public:
    bool checkArray(vector<int>& A, int k) {
        int N = A.size(), d = 0; // `d` is what we need to subtract at A[i]
        vector<int> diff(N + 1); // when we need to additionally subtract `x` at A[i], we set `diff[i + k] = -x.
        for (int i = 0; i < N; ++i) {
            d += diff[i];
            A[i] -= d;
            if (A[i] < 0) return false; // If A[i] becomes negative after subtracting d, return false
            if (A[i] > 0) { // If there is still some remnant A[i], we add it to `d` and set `diff[i + k] = -A[i]`.
                d += A[i];
                if (i + k > N) return false;  
                diff[i + k] = -A[i];
            } 
        }
        return true;
    }
};
```