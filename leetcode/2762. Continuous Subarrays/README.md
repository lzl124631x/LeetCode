# [2762. Continuous Subarrays (Medium)](https://leetcode.com/problems/continuous-subarrays)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. A subarray of <code>nums</code> is called <strong>continuous</strong> if:</p>
<ul>
	<li>Let <code>i</code>, <code>i + 1</code>, ..., <code>j</code><sub> </sub>be the indices in the subarray. Then, for each pair of indices <code>i &lt;= i<sub>1</sub>, i<sub>2</sub> &lt;= j</code>, <code><font face="monospace">0 &lt;=</font> |nums[i<sub>1</sub>] - nums[i<sub>2</sub>]| &lt;= 2</code>.</li>
</ul>
<p>Return <em>the total number of <strong>continuous</strong> subarrays.</em></p>
<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [5,4,2,4]
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
Thereare no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.
</pre>
<p>&nbsp;</p>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Yahoo](https://leetcode.com/company/yahoo), [Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Queue](https://leetcode.com/tag/queue/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Ordered Set](https://leetcode.com/tag/ordered-set/), [Monotonic Queue](https://leetcode.com/tag/monotonic-queue/)

## Solution 1. Find Maximum Sliding Window + Monotonic Queue

```cpp
// OJ: https://leetcode.com/problems/continuous-subarrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long continuousSubarrays(vector<int>& A) {
        long long ans = 0, N = A.size();
        deque<int> mn, mx;
        for (int i = 0, j = 0; j < N; ++j) {
            while (mx.size() && A[mx.back()] <= A[j]) mx.pop_back();
            mx.push_back(j);
            while (mn.size() && A[mn.back()] >= A[j]) mn.pop_back();
            mn.push_back(j);
            while (mn.size() && A[mx.front()] - A[mn.front()] > 2) {
                if (mx.front() == i) mx.pop_front();
                if (mn.front() == i) mn.pop_front();
                ++i;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
```