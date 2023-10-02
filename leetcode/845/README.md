# [845. Longest Mountain in Array (Medium)](https://leetcode.com/problems/longest-mountain-in-array/)

<p>Let's call any (contiguous) subarray B (of A)&nbsp;a <em>mountain</em> if the following properties hold:</p>

<ul>
	<li><code>B.length &gt;= 3</code></li>
	<li>There exists some <code>0 &lt; i&nbsp;&lt; B.length - 1</code> such that <code>B[0] &lt; B[1] &lt; ... B[i-1] &lt; B[i] &gt; B[i+1] &gt; ... &gt; B[B.length - 1]</code></li>
</ul>

<p>(Note that B could be any subarray of A, including the entire array A.)</p>

<p>Given an array <code>A</code>&nbsp;of integers,&nbsp;return the length of the longest&nbsp;<em>mountain</em>.&nbsp;</p>

<p>Return <code>0</code> if there is no mountain.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>[2,1,4,7,3,2,5]
<strong>Output: </strong>5
<strong>Explanation: </strong>The largest mountain is [1,4,7,3,2] which has length 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>[2,2,2]
<strong>Output: </strong>0
<strong>Explanation: </strong>There is no mountain.
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= A.length &lt;= 10000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 10000</code></li>
</ol>

<p><strong>Follow up:</strong></p>

<ul>
	<li>Can you solve it using only one pass?</li>
	<li>Can you solve it in <code>O(1)</code> space?</li>
</ul>


**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-mountain-in-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int dir = 0, N = A.size(), start = -1, ans = 0;
        for (int i = 1; i < N; ++i) {
            int d = A[i] == A[i - 1] ? 0 : (A[i] > A[i - 1] ? 1 : -1); // the new direction
            if (d == dir) continue; // if the direction is the same, skip
            if (dir == -1 && start != -1) ans = max(ans, i - start); // if we have a valid starting point and we are going downwards, we can try to update the answer
            dir = d;
            if (dir == 1) start = i - 1; // if new direction is upwards, set the starting point
            else if (dir == 0) start = -1; // going horizontal will invalidate the starting point.
        }
        if (dir == -1 && start != -1) ans = max(ans, N - start); // handle the case where the downward section reaches the end.
        return ans;
    }
};
```