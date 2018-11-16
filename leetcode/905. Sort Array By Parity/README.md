# [905. Sort Array By Parity (Easy)](https://leetcode.com/problems/sort-array-by-parity/)

<p>Given an array <code>A</code> of non-negative integers, return an array consisting of all the even elements of <code>A</code>, followed by all the odd elements of <code>A</code>.</p>

<p>You may return any answer array that satisfies this condition.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[3,1,2,4]</span>
<strong>Output: </strong><span id="example-output-1">[2,4,3,1]</span>
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 5000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 5000</code></li>
</ol>
</div>

## Solution 1.
```cpp
// OJ: https://leetcode.com/problems/sort-array-by-parity/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0, j = A.size() - 1; i < j; ++i, --j) {
            while (i < j && A[i] % 2 == 0) ++i;
            while (i < j && A[j] % 2 != 0) --j;
            if (i < j) swap(A[i], A[j]);
        }
        return A;
    }
};
```