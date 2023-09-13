# [1013. Partition Array Into Three Parts With Equal Sum (Easy)](https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/)

<p>Given an array <code>A</code> of integers, return <code>true</code> if and only if we can partition the array into three <strong>non-empty</strong> parts with equal sums.</p>

<p>Formally, we can partition the array if we can find indexes <code>i+1 &lt; j</code> with <code>(A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])</code></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> A = [0,2,1,-6,6,-7,9,1,2,0,1]
<strong>Output:</strong> true
<strong>Explanation: </strong>0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> A = [0,2,1,-6,6,7,9,-1,2,0,1]
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> A = [3,3,6,5,-2,2,5,1,-9,4]
<strong>Output:</strong> true
<strong>Explanation: </strong>3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= A.length &lt;= 50000</code></li>
	<li><code>-10^4&nbsp;&lt;= A[i] &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int total = accumulate(begin(A), end(A), 0), cnt = 0, sum = 0;
        if (total % 3) return false;
        total /= 3;
        for (int i = 0; i < A.size() - 1; ++i) {
            sum += A[i];
            if (sum == total) {
                sum = 0;
                ++cnt;
            }
            if (cnt == 2) return true;
        }
        return false;
    }
};
```