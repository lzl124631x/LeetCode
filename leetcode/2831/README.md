# [2831. Find the Longest Equal Subarray (Medium)](https://leetcode.com/problems/find-the-longest-equal-subarray)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>k</code>.</p>
<p>A subarray is called <strong>equal</strong> if all of its elements are equal. Note that the empty subarray is an <strong>equal</strong> subarray.</p>
<p>Return <em>the length of the <strong>longest</strong> possible equal subarray after deleting <strong>at most</strong> </em><code>k</code><em> elements from </em><code>nums</code>.</p>
<p>A <b>subarray</b> is a contiguous, possibly empty sequence of elements within an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,2,3,1,3], k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> It's optimal to delete the elements at index 2 and index 4.
After deleting them, nums becomes equal to [1, 3, 3, 3].
The longest equal subarray starts at i = 1 and ends at j = 3 with length equal to 3.
It can be proven that no longer equal subarrays can be created.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,2,2,1,1], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> It's optimal to delete the elements at index 2 and index 3.
After deleting them, nums becomes equal to [1, 1, 1, 1].
The array itself is an equal subarray, so the answer is 4.
It can be proven that no longer equal subarrays can be created.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
</ul>

**Companies**:
[Palo Alto Networks](https://leetcode.com/company/palo-alto networks)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1.

* Group the indices of the numbers based on the corresponding number. For example, `A = [1,1,2,2,1,1]` is turned into `{ 1 => [0,1,4,5], 2 => [2,3] }`.
* For each of the group of indices, use deque to find the longest window that has at most `k` other numbers.

```cpp
// OJ: https://leetcode.com/problems/find-the-longest-equal-subarray
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestEqualSubarray(vector<int>& A, int k) {
        int N = A.size(), ans = 1;
        unordered_map<int, vector<int>> index;
        for (int i = 0; i < N; ++i) index[A[i]].push_back(i);
        for (auto &[n, v] : index) {
            deque<int> q;
            for (int i : v) {
                q.push_back(i);
                while (i - q.front() + 1 - q.size() > k) q.pop_front();
                ans = max(ans, (int)q.size());
            }
        }
        return ans;
    }
};
```

## Solution 2. Non-shrinkable Sliding Window

```cpp
// OJ: https://leetcode.com/problems/find-the-longest-equal-subarray
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/find-the-longest-equal-subarray/solutions/3934172
class Solution {
public:
    int longestEqualSubarray(vector<int>& A, int k) {
        int N = A.size(), ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0, j = 0; j < N; ++j) {
            ans = max(ans, ++cnt[A[j]]);
            if (j - i + 1 - ans > k) --cnt[A[i++]];
        }
        return ans;
    }
};
```