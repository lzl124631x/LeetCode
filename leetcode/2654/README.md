# [2654. Minimum Number of Operations to Make All Array Elements Equal to 1 (Medium)](https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1)

<p>You are given a <strong>0-indexed</strong>&nbsp;array <code>nums</code> consisiting of <strong>positive</strong> integers. You can do the following operation on the array <strong>any</strong> number of times:</p>
<ul>
	<li>Select an index <code>i</code> such that <code>0 &lt;= i &lt; n - 1</code> and replace either of&nbsp;<code>nums[i]</code> or <code>nums[i+1]</code> with their gcd value.</li>
</ul>
<p>Return <em>the <strong>minimum</strong> number of operations to make all elements of </em><code>nums</code><em> equal to </em><code>1</code>. If it is impossible, return <code>-1</code>.</p>
<p>The gcd of two integers is the greatest common divisor of the two integers.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,6,3,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can do the following operations:
- Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
- Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
- Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
- Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,10,6,14]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be shown that it is impossible to make all the elements equal to 1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>
<p>&nbsp;</p>
<p><b>Follow-up:</b></p>
<p>The <code>O(n)</code> time complexity&nbsp;solution works, but could you find an <code>O(1)</code> constant time complexity solution?</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Number Theory](https://leetcode.com/tag/number-theory/)

## Solution 1.

* If GCD of all numbers is not 1, impossible.
* If some `A[i]` is already 1, assume there are `k` 1s, we need `N-k` operations to make all 1s.
* If GCD of two adjacent numbers is 1, we do one operation here to get a one, then take `N-1` operations to make all 1s.
* If no GCD of two adjacent numbers is 1, we find the minimum subarray whose GCD is 1. If this subarray is of length `K`, we take `K-1` operations to get a one, then take `N-1` operations to make all 1s.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& A) {
        int N = A.size(), mnLen = N, one = 0, all = A[0];
        for (int n : A) {
            one += n == 1;
            all = gcd(all, n);
        }
        if (one) return N - one;
        if (all > 1) return - 1;
        for (int i = N - 1; i >= 0; --i) {
            int val = A[i], j = i - 1;
            for (; j >= 0 && val > 1; --j) {
                val = gcd(val, A[j]);
            }
            if (val == 1) mnLen = min(mnLen, i - j);
            else break;
        }
        return mnLen + N - 2;
    }
};
```