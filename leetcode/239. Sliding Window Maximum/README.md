# [239. Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)

<p>Given an array <em>nums</em>, there is a sliding window of size <em>k</em> which is moving from the very left of the array to the very right. You can only see the <em>k</em> numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.</p>

<p><strong>Follow up:</strong><br>
Could you solve it in linear time?</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> <em>nums</em> = <code>[1,3,-1,-3,5,3,6,7]</code>, and <em>k</em> = 3
<strong>Output: </strong><code>[3,3,5,5,6,7] 
<strong>Explanation: 
</strong></code>
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       <strong>3</strong>
 1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 1  3 [-1  -3  5] 3  6  7      <strong> 5</strong>
 1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 1  3  -1  -3  5 [3  6  7]      <strong>7</strong>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>-10^4&nbsp;&lt;= nums[i]&nbsp;&lt;= 10^4</code></li>
	<li><code>1 &lt;= k&nbsp;&lt;= nums.length</code></li>
</ul>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)
* [Min Stack (Easy)](https://leetcode.com/problems/min-stack/)
* [Longest Substring with At Most Two Distinct Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
* [Paint House II (Hard)](https://leetcode.com/problems/paint-house-ii/)

## Solution 1. Monotonous Deque

Assume the array is `[3, 1, 2, ...]` and `k = 3`, popping `3` out of the window will result in max value update, but popping `1` won't. This means that we can just keep track of `[3, 2]`, i.e. a monotonically decreasing sequence of values.

Here we store the `index` of the monotonoically decreasing sequence. When a new value `A[i]` is added to the window, we pop the trailing index in the deque which are pointing to values that are smaller or equal to `A[i]`. Then we can push `i` into the deque.

We need to pop the index which falls out of the window from the deque as well.

```cpp
// OJ: https://leetcode.com/problems/sliding-window-maximum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < A.size(); ++i) {
            if (q.size() && q.front() == i - k) q.pop_front();
            while (q.size() && A[q.back()] <= A[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) ans.push_back(A[q.front()]);
        }
        return ans;
    }
};
```

## Solution 2. Monotonous Deque

Similar to Solution 1, but here we store the values instead of the indexes in the deque.

```cpp
// OJ: https://leetcode.com/problems/sliding-window-maximum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= k && q.size() && q.front() == A[i - k]) q.pop_front();
            while (q.size() && q.back() < A[i]) q.pop_back();
            q.push_back(A[i]);
            if (i >= k - 1) ans.push_back(q.front());
        }
        return ans;
    }
};
```