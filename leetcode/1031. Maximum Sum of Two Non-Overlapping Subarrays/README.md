# [1031. Maximum Sum of Two Non-Overlapping Subarrays (Medium)](https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/)

<p>Given an array <code>A</code> of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths&nbsp;<code>L</code> and <code>M</code>.&nbsp; (For clarification, the <code>L</code>-length subarray could occur before or after the <code>M</code>-length subarray.)</p>

<p>Formally,&nbsp;return the largest <code>V</code> for which&nbsp;<code>V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1])</code> and either:</p>

<ul>
	<li><code>0 &lt;= i &lt; i + L - 1 &lt; j &lt; j + M - 1 &lt; A.length</code>, <strong>or</strong></li>
	<li><code>0 &lt;= j &lt; j + M - 1 &lt; i &lt; i + L - 1 &lt; A.length</code>.</li>
</ul>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[0,6,5,2,2,5,1,9,4]</span>, L = <span id="example-input-1-2">1</span>, M = <span id="example-input-1-3">2</span>
<strong>Output: </strong><span id="example-output-1">20
<strong>Explanation:</strong> One choice of subarrays is [9] with length 1, and [6,5] with length 2.</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">[3,8,1,3,2,1,8,9,0]</span>, L = <span id="example-input-2-2">3</span>, M = <span id="example-input-2-3">2</span>
<strong>Output: </strong><span id="example-output-2">29
</span><span id="example-output-1"><strong>Explanation:</strong> One choice of subarrays is</span><span> [3,8,1] with length 3, and [8,9] with length 2.</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-3-1">[2,1,5,6,0,9,5,0,3,8]</span>, L = <span id="example-input-3-2">4</span>, M = <span id="example-input-3-3">3</span>
<strong>Output: </strong><span id="example-output-3">31
</span><span id="example-output-1"><strong>Explanation:</strong> One choice of subarrays is</span><span> [5,6,0,9] with length 4, and [3,8] with length 3.</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>L &gt;= 1</code></li>
	<li><code>M &gt;= 1</code></li>
	<li><code>L + M &lt;= A.length &lt;= 1000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 1000</code></li>
</ol>
</div>
</div>
</div>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int get(vector<int> &v, int i) {
        return (i >= 0 && i < v.size()) ? v[i] : 0;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int N = A.size(), ans = 0;
        partial_sum(A.begin(), A.end(), A.begin());
        vector<int> maxLeft(N, 0), maxRight(N, 0);
        for (int i = L - 1; i < N; ++i) maxLeft[i] = max(get(maxLeft, i - 1), A[i] - get(A, i - L));
        for (int i = N - L; i >= 0; --i) maxRight[i] = max(get(maxRight, i + 1), A[i + L - 1] - get(A, i - 1));
        for (int i = M - 1; i < N; ++i) {
            int sum = A[i] - get(A, i - M)
                + max(get(maxLeft, i - M), get(maxRight, i + 1));
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/discuss/278251/JavaC%2B%2BPython-O(N)Time-O(1)-Space
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        partial_sum(A.begin(), A.end(), A.begin());
        int ans = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
        for (int i = L + M; i < A.size(); ++i) {
            Lmax = max(Lmax, A[i - M] - A[i - L - M]);
            Mmax = max(Mmax, A[i - L] - A[i - L - M]);
            ans = max(ans, max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
        }
        return ans;
    }
};
```