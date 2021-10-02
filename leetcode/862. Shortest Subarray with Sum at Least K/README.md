# [862. Shortest Subarray with Sum at Least K (Hard)](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)

<p>Return the <strong>length</strong> of the shortest, non-empty, contiguous&nbsp;subarray of <code>A</code> with sum at least <code>K</code>.</p>

<p>If there is no non-empty subarray with sum at least <code>K</code>, return <code>-1</code>.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[1]</span>, K = <span id="example-input-1-2">1</span>
<strong>Output: </strong><span id="example-output-1">1</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">[1,2]</span>, K = <span id="example-input-2-2">4</span>
<strong>Output: </strong><span id="example-output-2">-1</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-3-1">[2,-1,2]</span>, K = <span id="example-input-3-2">3</span>
<strong>Output: </strong><span id="example-output-3">3</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 50000</code></li>
	<li><code>-10 ^ 5&nbsp;&lt;= A[i] &lt;= 10 ^ 5</code></li>
	<li><code>1 &lt;= K &lt;= 10 ^ 9</code></li>
</ol>
</div>
</div>
</div>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Queue](https://leetcode.com/tag/queue/)

## Solution 1. Sliding Window + Mono-deque

Let `P[i] = A[0] + ... A[i - 1]` where `i` &isin; `[1, N]`. Our goal is to find the smallest `y - x` such that `P[y] - P[x] >= K`.

Let `opt(y)` be the largest `x` such that `P[y] - P[x] >= K`. Two key observations:
1. If `x1 < x2` and `P[x1] >= P[x2]`, then we don't need to consider `x1` because if `P[y] - P[x1] >= K` then `P[y] - P[x2]` must `>= K` as well, and `y - x2 < y - x1`.
1. If `opt(y1) = x`, then we do not need to consider this `x` again. If we find some `y2 > y1` with `opt(y2) = x`, then it represents an answer `y2 - x` which is worse (larger) than `y1 - x`.

Rule 1 tells us that we just need to keep a strictly increasing sequence `P[a] < P[b] < P[c]...`.

Rule 2 tells us that we can further shrink the sequence from the front whenever the front element `P[x]` has been used as `opt(y)`.

**Algorithm**

Maintain a mono-deque of indices of `P`: a deque of indices `x_0, x_1, ...` such that `P[x_0], P[x_1], ...` is increasing.

When adding a new index `y`, we'll pop `x_i` from the end of the deque so that `P[x_0], P[x_1], ..., P[y]` will be increasing.

If `P[y] >= P[x_0] + K`, then (as previously described) we don't need to consider this `x_0` again, and we can pop it from the front of the deque.

```cpp
// OJ: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/articles/shortest-subarray-with-sum-atleast-k/
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size(), ans = INT_MAX;
        vector<long> P(N + 1);
        for (int i = 0; i < N; ++i) P[i + 1] = P[i] + A[i];
        deque<int> q;
        for (int y = 0; y < P.size(); ++y) {
            while (q.size() && P[y] <= P[q.back()]) q.pop_back();
            while (q.size() && P[y] >= P[q.front()] + K) {
                ans = min(ans, y - q.front());
                q.pop_front();
            }
            q.push_back(y);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```