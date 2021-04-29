# [907. Sum of Subarray Minimums (Medium)](https://leetcode.com/problems/sum-of-subarray-minimums/)

<p>Given an array of integers arr, find the sum of <code>min(b)</code>, where <code>b</code> ranges over every (contiguous) subarray of <code>arr</code>. Since the answer may be large, return the answer <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [3,1,2,4]
<strong>Output:</strong> 17
<strong>Explanation:</strong> 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [11,81,94,43,3]
<strong>Output:</strong> 444
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 3 * 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1. Mono Stack


```cpp
// OJ: https://leetcode.com/problems/sum-of-subarray-minimums/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<int> q; // index
        q.push(-1);
        long N = A.size(), ans = 0, sum = 0, mod = 1e9+7;
        for (int i = 0; i < N; ++i) {
            sum = (sum + A[i]) % mod;
            while (q.top() != -1 && A[q.top()] >= A[i]) {
                int j = q.top();
                q.pop();
                int c = j - q.top();
                sum = (sum + c * (A[i] - A[j]) % mod) % mod;
            }
            q.push(i);
            ans = (ans + sum) % mod;
        }
        return ans;
    }
};
```