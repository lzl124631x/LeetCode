# [718. Maximum Length of Repeated Subarray (Medium)](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

<p>Given two integer arrays <code>A</code> and <code>B</code>, return the maximum length of an subarray that appears in both arrays.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>
A: [1,2,3,2,1]
B: [3,2,1,4,7]
<b>Output:</b> 3
<b>Explanation:</b> 
The repeated subarray with maximum length is [3, 2, 1].
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>1 &lt;= len(A), len(B) &lt;= 1000</li>
<li>0 &lt;= A[i], B[i] &lt; 100</li>
</ol>
<p></p>

**Companies**:  
[Intuit](https://leetcode.com/company/intuit)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.size() < B.size()) swap(A, B);
        int M = A.size(), N = B.size(), ans = 0;
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                dp[j + 1] = A[i] == B[j] ? 1 + dp[j] : 0;
                ans = max(ans, dp[j + 1]);
            }
        }
        return ans;
    }
};
```