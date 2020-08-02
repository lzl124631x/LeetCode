# [1534. Count Good Triplets (Easy)](https://leetcode.com/problems/count-good-triplets/)

<p>Given an array of integers <code>arr</code>, and three integers&nbsp;<code>a</code>,&nbsp;<code>b</code>&nbsp;and&nbsp;<code>c</code>. You need to find the number of good triplets.</p>

<p>A triplet <code>(arr[i], arr[j], arr[k])</code>&nbsp;is <strong>good</strong> if the following conditions are true:</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt;&nbsp;arr.length</code></li>
	<li><code>|arr[i] - arr[j]| &lt;= a</code></li>
	<li><code>|arr[j] - arr[k]| &lt;= b</code></li>
	<li><code>|arr[i] - arr[k]| &lt;= c</code></li>
</ul>

<p>Where <code>|x|</code> denotes the absolute value of <code>x</code>.</p>

<p>Return<em> the number of good triplets</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong>&nbsp;There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,1,2,2,3], a = 0, b = 0, c = 1
<strong>Output:</strong> 0
<strong>Explanation: </strong>No triplet satisfies all conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 100</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= a, b, c &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/count-good-triplets/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    int countGoodTriplets(vector<int>& A, int a, int b, int c) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    if (abs(A[i] - A[j]) <= a && abs(A[j] - A[k]) <= b && abs(A[i] - A[k]) <= c) ++ans;
                }
            }
        }
        return ans;
    }
};
```