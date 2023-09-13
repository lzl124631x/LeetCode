# [1524. Number of Sub-arrays With Odd Sum (Medium)](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)

<p>Given an array of integers <code>arr</code>. Return <em>the number of sub-arrays</em> with <strong>odd</strong> sum.</p>

<p>As the answer may grow large, the answer&nbsp;<strong>must be</strong>&nbsp;computed modulo&nbsp;<code>10^9 + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,3,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [2,4,6]
<strong>Output:</strong> 0
<strong>Explanation:</strong> All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4,5,6,7]
<strong>Output:</strong> 16
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> arr = [100,100,99,99]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> arr = [7]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

Assume `sum[i]` is the sum of `A[0..(i - 1)]`, `sum[0] = 0`. We can get any subarray sum using `sum[j] - sum[i] = A[i] + .. + A[j-1]`. Given `0 < j <= N`, to find how many `0 <= i < j` can form odd subarray sum with `j`, we just need to know how many `sum[i]` are odd or even numbers.

If `sum[j]` is odd, then we use those even `sum[i]` to form odd subarray sum.

If `sum[j]` is even, then we use those odd `sum[i]` to form odd subarray sum.

So we just need to store how many odd `sum[i]` we've seen thus far in a variable `odd`. The number of even `sum[i]` is `j + 1 - odd`.

```cpp
// OJ: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numOfSubarrays(vector<int>& A) {
        long mod = 1e9+7, ans = 0, odd = 0, sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum % 2) ans = (ans + i + 1 - odd) % mod; // sum is odd, use those `i + 1 - odd` even numbers to form odd subarray sums.
            else ans = (ans + odd) % mod; // sum is even, use those `odd` odd numbers to form odd subarray sums.
            odd += sum % 2;
        }
        return ans;
    }
};
```