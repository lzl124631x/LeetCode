# [852. Peak Index in a Mountain Array (Medium)](https://leetcode.com/problems/peak-index-in-a-mountain-array)

<p>An array <code>arr</code> a <strong>mountain</strong> if the following properties hold:</p>
<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>There exists some <code>i</code> with <code>0 &lt; i &lt; arr.length - 1</code> such that:
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i] </code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>
<p>Given a mountain array <code>arr</code>, return the index <code>i</code> such that <code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code>.</p>
<p>You must solve it in <code>O(log(arr.length))</code> time complexity.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [0,1,0]
<strong>Output:</strong> 1
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> arr = [0,2,1,0]
<strong>Output:</strong> 1
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> arr = [0,10,5,2]
<strong>Output:</strong> 1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>3 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>arr</code> is <strong>guaranteed</strong> to be a mountain array.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Find Peak Element (Medium)](https://leetcode.com/problems/find-peak-element/)
* [Find in Mountain Array (Hard)](https://leetcode.com/problems/find-in-mountain-array/)
* [Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)

## Solution 1. Binary Search
```cpp
// OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int L = 1, R = A.size() - 2;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] > A[M - 1]) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```