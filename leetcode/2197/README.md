# [2197. Replace Non-Coprime Numbers in Array (Hard)](https://leetcode.com/problems/replace-non-coprime-numbers-in-array/)

<p>You are given an array of integers <code>nums</code>. Perform the following steps:</p>

<ol>
	<li>Find <strong>any</strong> two <strong>adjacent</strong> numbers in <code>nums</code> that are <strong>non-coprime</strong>.</li>
	<li>If no such numbers are found, <strong>stop</strong> the process.</li>
	<li>Otherwise, delete the two numbers and <strong>replace</strong> them with their <strong>LCM (Least Common Multiple)</strong>.</li>
	<li><strong>Repeat</strong> this process as long as you keep finding two adjacent non-coprime numbers.</li>
</ol>

<p>Return <em>the <strong>final</strong> modified array.</em> It can be shown that replacing adjacent non-coprime numbers in <strong>any</strong> arbitrary order will lead to the same result.</p>

<p>The test cases are generated such that the values in the final array are <strong>less than or equal</strong> to <code>10<sup>8</sup></code>.</p>

<p>Two values <code>x</code> and <code>y</code> are <strong>non-coprime</strong> if <code>GCD(x, y) &gt; 1</code> where <code>GCD(x, y)</code> is the <strong>Greatest Common Divisor</strong> of <code>x</code> and <code>y</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [6,4,3,2,7,6,2]
<strong>Output:</strong> [12,7,6]
<strong>Explanation:</strong> 
- (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [<strong><u>12</u></strong>,3,2,7,6,2].
- (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [<strong><u>12</u></strong>,2,7,6,2].
- (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [<strong><u>12</u></strong>,7,6,2].
- (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,<u><strong>6</strong></u>].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [12,7,6].
Note that there are other ways to obtain the same resultant array.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,1,1,3,3,3]
<strong>Output:</strong> [2,1,1,3]
<strong>Explanation:</strong> 
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,<u><strong>3</strong></u>,3].
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,<u><strong>3</strong></u>].
- (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [<u><strong>2</strong></u>,1,1,3].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [2,1,1,3].
Note that there are other ways to obtain the same resultant array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li>The test cases are generated such that the values in the final array are <strong>less than or equal</strong> to <code>10<sup>8</sup></code>.</li>
</ul>


**Similar Questions**:
* [Remove All Adjacent Duplicates in String II (Medium)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)
* [Number of Pairs of Interchangeable Rectangles (Medium)](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/)

## Solution 1. Simulation + Two Pointers

**Intuition**: From left to right, replace two adjacent non-coprime numbers with their LCM. When a merge happens, try keep merging leftwards.

**Algorithm**: `i` is a read pointer scaning `A` from left to right. `j` is a write pointer. After reading a new number `A[j] = A[i]`, we keep trying to merge `A[j]` with `A[j-1]` if they are non-coprime. The new `A[j-1]` after merge is `LCM(A[j], A[j-1])`.

**Time Complexity**:

Since `gcd(a, b)`'s time complexity is `log(min(a, b))`, the time complexity is `O(NlogM)` overall where `M` is the maximum number in `A`.

```cpp
// OJ: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& A) {
        int j = 0, N = A.size();
        for (int i = 0; i < N; ++i, ++j) {
            A[j] = A[i];
            for (; j - 1 >= 0 && gcd(A[j], A[j - 1]) > 1; --j) { // When we can merge leftwards from `A[j]`, keep merging
                A[j - 1] = (long)A[j] * A[j - 1] / gcd(A[j], A[j - 1]); // replace `A[j-1]` with LCM of `A[j-1]` and `A[j]`.
            }
        }
        A.resize(j);
        return A;
    }
};
```

## Discuss

https://leetcode.com/problems/replace-non-coprime-numbers-in-array/discuss/1823592/