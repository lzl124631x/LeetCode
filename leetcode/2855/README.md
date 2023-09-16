# [2855. Minimum Right Shifts to Sort the Array (Easy)](https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> of length <code>n</code> containing <strong>distinct</strong> positive integers. Return <em>the <strong>minimum</strong> number of <strong>right shifts</strong> required to sort </em><code>nums</code><em> and </em><code>-1</code><em> if this is not possible.</em></p>

<p>A <strong>right shift</strong> is defined as shifting the element at index <code>i</code> to index <code>(i + 1) % n</code>, for all indices.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,5,1,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
After the first right shift, nums = [2,3,4,5,1].
After the second right shift, nums = [1,2,3,4,5].
Now nums is sorted; therefore the answer is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> nums is already sorted therefore, the answer is 0.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,4]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It&#39;s impossible to sort the array using right shifts.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums</code> contains distinct integers.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumRightShifts(vector<int>& A) {
        int N = A.size(), i = 0;
        while (i + 1 < N && A[i + 1] > A[i]) ++i;
        if (i == N - 1) return 0;
        int j = i + 1;
        while (j + 1 < N && A[j + 1] > A[j]) ++j;
        return j == N - 1 && A.back() < A[0] ? N - 1 - i : -1;
    }
};
```