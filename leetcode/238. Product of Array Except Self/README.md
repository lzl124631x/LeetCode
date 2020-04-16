# [238. Product of Array Except Self (Medium)](https://leetcode.com/problems/product-of-array-except-self/)

<p>Given an array <code>nums</code> of <em>n</em> integers where <em>n</em> &gt; 1, &nbsp;return an array <code>output</code> such that <code>output[i]</code> is equal to the product of all the elements of <code>nums</code> except <code>nums[i]</code>.</p>

<p><b>Example:</b></p>

<pre><b>Input:</b>  <code>[1,2,3,4]</code>
<b>Output:</b> <code>[24,12,8,6]</code>
</pre>

<p><strong>Constraint:</strong>&nbsp;It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.</p>

<p><strong>Note: </strong>Please solve it <strong>without division</strong> and in O(<em>n</em>).</p>

<p><strong>Follow up:</strong><br>
Could you solve it with constant space complexity? (The output array <strong>does not</strong> count as extra space for the purpose of space complexity analysis.)</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Trapping Rain Water (Hard)](https://leetcode.com/problems/trapping-rain-water/)
* [Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)
* [Paint House II (Hard)](https://leetcode.com/problems/paint-house-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/product-of-array-except-self/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& A) {
        int N = A.size(), prod = 1;
        vector<int> ans(A.begin(), A.end());
        for (int i = N - 2; i >= 0; --i) ans[i] *= ans[i + 1];
        for (int i = 0; i < N; ++i) {
            ans[i] = prod * (i + 1 >= N ? 1 : ans[i + 1]);
            prod *= A[i];
        }
        return ans;
    }
};
```