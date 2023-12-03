# [2951. Find the Peaks (Easy)](https://leetcode.com/problems/find-the-peaks)

<p>You are given a <strong>0-indexed</strong> array <code>mountain</code>. Your task is to find all the <strong>peaks</strong> in the <code>mountain</code> array.</p>

<p>Return <em>an array that consists of </em>indices<!-- notionvc: c9879de8-88bd-43b0-8224-40c4bee71cd6 --><em> of <strong>peaks</strong> in the given array in <strong>any order</strong>.</em></p>

<p><strong>Notes:</strong></p>

<ul>
	<li>A <strong>peak</strong> is defined as an element that is <strong>strictly greater</strong> than its neighboring elements.</li>
	<li>The first and last elements of the array are <strong>not</strong> a peak.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> mountain = [2,4,4]
<strong>Output:</strong> []
<strong>Explanation:</strong> mountain[0] and mountain[2] can not be a peak because they are first and last elements of the array.
mountain[1] also can not be a peak because it is not strictly greater than mountain[2].
So the answer is [].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> mountain = [1,4,3,8,5]
<strong>Output:</strong> [1,3]
<strong>Explanation:</strong> mountain[0] and mountain[4] can not be a peak because they are first and last elements of the array.
mountain[2] also can not be a peak because it is not strictly greater than mountain[3] and mountain[1].
But mountain [1] and mountain[3] are strictly greater than their neighboring elements.
So the answer is [1,3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= mountain.length &lt;= 100</code></li>
	<li><code>1 &lt;= mountain[i] &lt;= 100</code></li>
</ul>


**Similar Questions**:
* [Find Peak Element (Medium)](https://leetcode.com/problems/find-peak-element)
* [Find a Peak Element II (Medium)](https://leetcode.com/problems/find-a-peak-element-ii)

**Hints**:
* If <code>nums[i] > num[i - 1]</code> and <code>nums[i] > nums[i + 1]</code> <code>nums[i]</code> is a peak.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-peaks
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findPeaks(vector<int>& A) {
        vector<int> ans;
        for (int i = 1; i < A.size() - 1; ++i) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) ans.push_back(i);
        }
        return ans;
    }
};
```