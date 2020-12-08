# [1089. Duplicate Zeros (Easy)](https://leetcode.com/problems/duplicate-zeros/)

<p>Given a fixed length&nbsp;array <code>arr</code> of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.</p>

<p>Note that elements beyond the length of the original array are not written.</p>

<p>Do the above modifications to the input array <strong>in place</strong>, do not return anything from your function.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,0,2,3,0,4,5,0]</span>
<strong>Output: </strong>null
<strong>Explanation: </strong>After calling your function, the <strong>input</strong> array is modified to: <span id="example-output-1">[1,0,0,2,3,0,0,4]</span>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,2,3]</span>
<strong>Output: </strong>null
<strong>Explanation: </strong>After calling your function, the <strong>input</strong> array is modified to: <span id="example-output-2">[1,2,3]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= arr.length &lt;= 10000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 9</code></li>
</ol>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/duplicate-zeros/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& A) {
        int cnt = 0;
        for (int n : A) cnt += n == 0;
        if (cnt == 0) return;
        for (int i = A.size() - 1; i >= 0; --i) {
            cnt -= A[i] == 0;
            int j = i + cnt;
            if (j < A.size()) A[j] = A[i];
            if (j + 1 < A.size() && A[i] == 0) A[j + 1] = 0;
        }
    }
};
```