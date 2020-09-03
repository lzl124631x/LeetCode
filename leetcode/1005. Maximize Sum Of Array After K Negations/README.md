# [1005. Maximize Sum Of Array After K Negations (Easy)](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/)

<p>Given an array <code>A</code> of integers, we <strong>must</strong>&nbsp;modify the array in the following way: we choose an <code>i</code>&nbsp;and replace&nbsp;<code>A[i]</code> with <code>-A[i]</code>, and we repeat this process <code>K</code> times in total.&nbsp; (We may choose the same index <code>i</code> multiple times.)</p>

<p>Return the largest possible sum of the array after modifying it in this way.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[4,2,3]</span>, K = <span id="example-input-1-2">1</span>
<strong>Output: </strong><span id="example-output-1">5
<strong>Explanation: </strong>Choose indices (1,) and A becomes [4,-2,3].</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">[3,-1,0,2]</span>, K = <span id="example-input-2-2">3</span>
<strong>Output: </strong>6
<span id="example-output-1"><strong>Explanation: </strong>Choose indices (1, 2, 2) and A becomes [3,1,0,2].</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-3-1">[2,-3,-1,5,-4]</span>, K = <span id="example-input-3-2">2</span>
<strong>Output: </strong><span id="example-output-3">13
</span><span id="example-output-1"><strong>Explanation: </strong>Choose indices (1, 4) and A becomes [2,3,-1,5,4].</span>
</pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 10000</code></li>
	<li><code>1 &lt;= K &lt;= 10000</code></li>
	<li><code>-100 &lt;= A[i] &lt;= 100</code></li>
</ol>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(begin(A), end(A));
        int sum = 0, i = 0;
        for (; K > 0 && i < A.size() && A[i] < 0; ++i, --K) sum += -A[i];
        if (K % 2 && (i == A.size() || A[i] != 0)) {
            if (i == 0) sum -= A[i];
            else if (i == A.size()) sum += 2 * A[i - 1];
            else if (-A[i - 1] < A[i]) sum += 2 * A[i - 1] + A[i];
            else sum -= A[i];
            ++i;
        }
        for (; i < A.size(); ++i) sum += A[i];
        return sum;
    }
};
```