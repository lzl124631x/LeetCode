# [2605. Form Smallest Number From Two Digit Arrays (Easy)](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays)

<strong>unique</strong>
<code>nums1</code>
<code>nums2</code>
<em>the <strong>smallest</strong> number that contains <strong>at least</strong> one digit from each array</em>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums1 = [4,1,3], nums2 = [5,7]
<strong>Output:</strong> 15
<strong>Explanation:</strong> The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums1 = [3,5,2,6], nums2 = [3,1,7]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The number 3 contains the digit 3 which exists in both arrays.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 9</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 9</code></li>
	<li>All digits in each array are <strong>unique</strong>.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Enumeration](https://leetcode.com/tag/enumeration/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int minNumber(vector<int>& A, vector<int>& B) {
        int a[10] = {}, b[10] = {};
        for (int n : A) a[n]++;
        for (int n : B) b[n]++;
        int x = -1, y = -1;
        for (int i = 1; i < 10; ++i) {
            if (a[i] && b[i]) return i;
            if (a[i] && x == -1) x = i; 
            if (b[i] && y == -1) y = i;
        }
        return x < y ? 10 * x + y : 10 * y + x;
    }
};
```