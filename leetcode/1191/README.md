# [1191. K-Concatenation Maximum Sum (Medium)](https://leetcode.com/problems/k-concatenation-maximum-sum/)

<p>Given an integer array <code>arr</code> and an integer <code>k</code>, modify the array by repeating it <code>k</code> times.</p>

<p>For example, if <code>arr = [1, 2]</code> and <code>k = 3 </code>then the modified array will be <code>[1, 2, 1, 2, 1, 2]</code>.</p>

<p>Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be <code>0</code> and its sum in that case is <code>0</code>.</p>

<p>As the answer can be very large, return the answer <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2], k = 3
<strong>Output:</strong> 9
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,-2,1], k = 5
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [-1,-2], k = 7
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/k-concatenation-maximum-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/k-concatenation-maximum-sum/discuss/382885/Short-and-concise-O(N)-C%2B%2B-solution
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& A, int k) {
        long N = A.size(), sum = A[0], mx = A[0], total = accumulate(begin(A), end(A), 0L), mod = 1e9 + 7;
        for (int i = 1; i < N * min(k, 2); ++i) {
            sum = max((long)A[i % N], sum + A[i % N]);
            mx = max(mx, sum);
        }
        return max({ 0L, mx, total * max(0, k - 2) + mx }) % mod;
    }
};
```

## TODO

write explanation