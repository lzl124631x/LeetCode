# [1095. Find in Mountain Array (Hard)](https://leetcode.com/problems/find-in-mountain-array/)

<p><em>(This problem is an <strong>interactive problem</strong>.)</em></p>

<p>You may recall that an array <code>arr</code> is a <strong>mountain array</strong> if and only if:</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>There exists some <code>i</code> with <code>0 &lt; i &lt; arr.length - 1</code> such that:
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>Given a mountain array <code>mountainArr</code>, return the <strong>minimum</strong> <code>index</code> such that <code>mountainArr.get(index) == target</code>. If such an <code>index</code> does not exist, return <code>-1</code>.</p>

<p><strong>You cannot access the mountain array directly.</strong> You may only access the array using a <code>MountainArray</code> interface:</p>

<ul>
	<li><code>MountainArray.get(k)</code> returns the element of the array at index <code>k</code> (0-indexed).</li>
	<li><code>MountainArray.length()</code> returns the length of the array.</li>
</ul>

<p>Submissions making more than <code>100</code> calls to <code>MountainArray.get</code> will be judged <em>Wrong Answer</em>. Also, any solutions that attempt to circumvent the judge will result in disqualification.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> array = [1,2,3,4,5,3,1], target = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> array = [0,1,2,4,2,1], target = 3
<strong>Output:</strong> -1
<strong>Explanation:</strong> 3 does not exist in <code>the array,</code> so we return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= mountain_arr.length() &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= mountain_arr.get(index) &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Apple](https://leetcode.com/company/apple), [Quora](https://leetcode.com/company/quora)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Interactive](https://leetcode.com/tag/interactive/)

**Similar Questions**:
* [Peak Index in a Mountain Array (Easy)](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
* [Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/find-in-mountain-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
    int binarySearch(int target, MountainArray &A, int L, int R, int dir) {
        while (L <= R) {
            int M = (L + R) / 2, val = A.get(M);
            if (val == target) return M;
            bool left = (dir == 1 && val < target) || (dir == -1 && val > target);
            if (left) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
    int findTop(MountainArray &A, int N) {
        int L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2, left = M - 1 >= 0 ? A.get(M - 1) : INT_MIN, val = A.get(M), right = M + 1 < N ? A.get(M + 1) : INT_MIN;
            if (val > left && val > right) return M;
            else if (val < left) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &A) {
        int N = A.length(), top = findTop(A, N);
        int a = binarySearch(target, A, 0, top, 1);
        int b = binarySearch(target, A, top + 1, N - 1, -1);
        return a != -1 ? a : b;
    }
};
```