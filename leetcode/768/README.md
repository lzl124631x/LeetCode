# [768. Max Chunks To Make Sorted II (Hard)](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/)

<p><em>This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input array could be up to length <code>2000</code>, and the elements could be up to <code>10**8</code>.</em></p>

<hr>

<p>Given an array <code>arr</code> of integers (<strong>not necessarily distinct</strong>), we split the array into some number of "chunks" (partitions), and individually sort each chunk.&nbsp; After concatenating them,&nbsp;the result equals the sorted array.</p>

<p>What is the most number of chunks we could have made?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [5,4,3,2,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [2,1,3,4,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong>
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>arr</code> will have length in range <code>[1, 2000]</code>.</li>
	<li><code>arr[i]</code> will be an integer in range <code>[0, 10**8]</code>.</li>
</ul>

<p>&nbsp;</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Max Chunks To Make Sorted (Medium)](https://leetcode.com/problems/max-chunks-to-make-sorted/)

## Solution 1. Monoqueue

Use a `deque<int> q` to store the min values between `A[i]` and `A[N-1]`, `i = N-1, ..., 0`. 

Example, `A = [3, 1, 2], q = [1, 2]`.

When we visit `3`, `q.front() == 1` which means that there are smaller values after `3`, so we shouldn't split here.

When we visit `1`, `q.front() == 1` which means that we are visiting the smallest element among the elements we've seen thus far.

Should we split here? We need to take a look at the next element in `q`.

* If the next element in `q` is greater than or equal to the maximum value we've seen thus far, we can split at this element. (If there is no next element, we should split as well)
Examples: `A = [3, 1, 4], q = [1, 4]`; `A = [3, 1, 3], q = [1, 3]`.
* otherwise, we shouldn't split here.  
Example: `A = [3, 1, 2], q = [1, 2]`

Another example, `A = [2, 1, 1]`, `q = [1, 1]`.

When we visit the first `1`, `q.front() == 1` but the next element is also `1`. And `1` is smaller than the max value `2` we've seen thus far, so we shouldn't split after the first `1`.

Another example, `A = [1, 2, 2]`, `q = [1, 2, 2]`.

When we visit the first `2`, `q.front() == 2` and the next element is also `2`.

```cpp
// OJ: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        deque<int> q;
        int N = A.size(), ans = 0, mx = A[0];
        for (int i = N - 1; i >= 0; --i) {
            if (q.empty() || A[i] <= q.front()) q.push_front(A[i]);
        }
        for (int i = 0; i < N; ++i) {
            mx = max(mx, A[i]);
            if (q.front() != A[i]) continue;
            q.pop_front();
            if (q.empty() || mx <= q.front()) ++ans;
        }
        return ans;
    }
};
```

## Solution 2.

If we can split between `A[i - 1]` and `A[i]`, it means that the max value in `A[0..(i-1)]` is smaller than or equal to the max value in `A[i..(N-1)]`.

```cpp
// OJ: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int N = A.size(), ans = 1;
        vector<int> mx(N), mn(N);
        mx[0] = A[0];
        mn[N - 1] = A[N - 1];
        for (int i = 1; i < N; ++i) mx[i] = max(mx[i - 1], A[i]);
        for (int i = N - 2; i >= 0; --i) mn[i] = min(mn[i + 1], A[i]);
        for (int i = 1; i < N; ++i) {
            if (mn[i] >= mx[i - 1]) ++ans;
        }
        return ans;
    }
};
```