# [918. Maximum Sum Circular Subarray (Medium)](https://leetcode.com/problems/maximum-sum-circular-subarray/)

<p>Given a <strong>circular&nbsp;array</strong>&nbsp;<strong>C</strong> of integers represented by&nbsp;<code>A</code>, find the maximum possible sum of a non-empty subarray of <strong>C</strong>.</p>

<p>Here, a&nbsp;<em>circular&nbsp;array</em> means the end of the array connects to the beginning of the array.&nbsp; (Formally, <code>C[i] = A[i]</code> when <code>0 &lt;= i &lt; A.length</code>, and <code>C[i+A.length] = C[i]</code>&nbsp;when&nbsp;<code>i &gt;= 0</code>.)</p>

<p>Also, a subarray may only include each element of the fixed buffer <code>A</code> at most once.&nbsp; (Formally, for a subarray <code>C[i], C[i+1], ..., C[j]</code>, there does not exist <code>i &lt;= k1, k2 &lt;= j</code> with <code>k1 % A.length&nbsp;= k2 % A.length</code>.)</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,-2,3,-2]</span>
<strong>Output: </strong><span id="example-output-1">3
<strong>Explanation: </strong>Subarray [3] has maximum sum 3</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[5,-3,5]</span>
<strong>Output: </strong><span id="example-output-2">10
</span><span id="example-output-3"><strong>Explanation:</strong>&nbsp;</span><span id="example-output-1">Subarray [5,5] has maximum sum </span><span>5 + 5 = 10</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[3,-1,2,-1]</span>
<strong>Output: </strong><span id="example-output-3">4
<strong>Explanation:</strong>&nbsp;</span><span id="example-output-1">Subarray [2,-1,3] has maximum sum </span><span>2 + (-1) + 3 = 4</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">[3,-2,2,-3]</span>
<strong>Output: </strong><span id="example-output-4">3
</span><span id="example-output-3"><strong>Explanation:</strong>&nbsp;</span><span id="example-output-1">Subarray [3] and [3,-2,2] both have maximum sum </span><span>3</span>
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input: </strong><span id="example-input-5-1">[-2,-3,-1]</span>
<strong>Output: </strong><span id="example-output-5">-1
</span><span id="example-output-3"><strong>Explanation:</strong>&nbsp;</span><span id="example-output-1">Subarray [-1] has maximum sum -1</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note: </strong></p>

<ol>
	<li><code>-30000 &lt;= A[i] &lt;= 30000</code></li>
	<li><code>1 &lt;= A.length &lt;= 30000</code></li>
</ol>
</div>
</div>
</div>
</div>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-sum-circular-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int N = A.size(), sum = 0, ans = INT_MIN;
        vector<int> p(2 * N + 1);
        for (int i = 0; i < 2 * N; ++i) {
            p[i + 1] = (sum += A[i % N]);
        }
        deque<int> q;
        for (int i = 0; i < 2 * N + 1; ++i) {
            if (i >= N && q.front() == i - N - 1) q.pop_front();
            if (q.size()) ans = max(ans, p[i] - p[q.front()]);
            while (q.size() && p[q.back()] >= p[i]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};
```