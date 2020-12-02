# [1299. Replace Elements with Greatest Element on Right Side (Easy)](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)

<p>Given an array <code>arr</code>,&nbsp;replace every element in that array with the greatest element among the elements to its&nbsp;right, and replace the last element with <code>-1</code>.</p>

<p>After doing so, return the array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [17,18,5,4,6,1]
<strong>Output:</strong> [18,6,6,6,1,-1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^4</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^5</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> replaceElements(vector<int>& A) {
        int mx = -1;
        for (int i = A.size() - 1; i >= 0; --i) {
            int n = A[i];
            A[i] = mx;
            mx = max(mx, n);
        }
        return A;
    }
};
```