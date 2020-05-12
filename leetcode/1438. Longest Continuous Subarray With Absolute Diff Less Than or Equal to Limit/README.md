# [1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (Medium)](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

<p>Given an&nbsp;array of integers <code>nums</code> and an&nbsp;integer <code>limit</code>, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to&nbsp;<code>limit</code><em>.</em></p>

<p>In case there is no subarray satisfying the given condition return 0.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [8,2,4,7], limit = 4
<strong>Output:</strong> 2 
<strong>Explanation:</strong> All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 &lt;= 4.
[8,2] with maximum absolute diff |8-2| = 6 &gt; 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 &gt; 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 &gt; 4.
[2] with maximum absolute diff |2-2| = 0 &lt;= 4.
[2,4] with maximum absolute diff |2-4| = 2 &lt;= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 &gt; 4.
[4] with maximum absolute diff |4-4| = 0 &lt;= 4.
[4,7] with maximum absolute diff |4-7| = 3 &lt;= 4.
[7] with maximum absolute diff |7-7| = 0 &lt;= 4. 
Therefore, the size of the longest subarray is 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [10,1,2,4,7,2], limit = 5
<strong>Output:</strong> 4 
<strong>Explanation:</strong> The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 &lt;= 5.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,2,2,4,4,2,2], limit = 0
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^9</code></li>
	<li><code>0 &lt;= limit &lt;= 10^9</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Sliding Window

Use a `multiset<int> s` to keep track of the values within the window. We keep extending the right-hand side of the window indexed by `j` and add `A[j]` into `s`.

Whenever we find that the difference between max value and min value in `s` is greater than `k`, we shrink the window by moving the left-hand side of the window indexed by `i`. For every `A[i]` that we popped out from the window, we erase it from `s` as well.

In this way, we make sure the window is always valid. The maximum `j - i` is the answer.

```cpp
// OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int longestSubarray(vector<int>& A, int k) {
        multiset<int> s{ A[0] };
        int i = 0, j = 1, N = A.size(), ans = 1;
        while (j < N) {
            s.insert(A[j++]);
            while (*s.rbegin() - *s.begin() > k) s.erase(s.find(A[i++]));
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

## Solution 2. Monotonous Deque

We use monotonous deques to keep track of the max/min values within the window. See [239. Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/) for the idea.

```cpp
// OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestSubarray(vector<int>& A, int k) {
        deque<int> mx{A[0]}, mn{A[0]};
        int N = A.size(), ans = 1, i = 0, j = 1;
        while (j < N) {
            while (j < N && mx.front() - mn.front() <= k) { 
                while (mx.size() && mx.back() < A[j]) mx.pop_back();
                mx.push_back(A[j]);
                while (mn.size() && mn.back() > A[j]) mn.pop_back();
                mn.push_back(A[j]);
                ++j;
                if (mx.front() - mn.front() <= k) ans = max(ans, j - i);
            }
            while (i < j && mx.front() - mn.front() > k) {
                if (A[i] == mx.front()) mx.pop_front();
                if (A[i] == mn.front()) mn.pop_front();
                ++i;
            }
        }
        return ans;
    }
};
```

## Solution 3. Monotonous Deque

Similar to Solution 2, but since we are looking for the maximum window, we don't shrink the window.

If the window is valid, we only increment the right edge.

Otherwise, we increment the left edge as well to shift the window as a whole.

```cpp
// OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/609771/JavaC%2B%2BPython-Deques-O(N)
class Solution {
public:
    int longestSubarray(vector<int>& A, int k) {
        deque<int> mx, mn;
        int i = 0, j = 0;
        for (; j < A.size(); ++j) {
            while (mx.size() && mx.back() < A[j]) mx.pop_back();
            while (mn.size() && mn.back() > A[j]) mn.pop_back();
            mx.push_back(A[j]);
            mn.push_back(A[j]);
            if (mx.front() - mn.front() > k) {
                if (A[i] == mx.front()) mx.pop_front();
                if (A[i] == mn.front()) mn.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};
```