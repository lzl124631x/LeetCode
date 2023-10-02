# [1199. Minimum Time to Build Blocks (Hard)](https://leetcode.com/problems/minimum-time-to-build-blocks)

<p>You are given a list of blocks, where <code>blocks[i] = t</code> means that the&nbsp;<code>i</code>-th block needs&nbsp;<code>t</code>&nbsp;units of time to be built. A block can only be built by exactly one worker.</p>
<p>A worker can either split into two workers (number of workers increases by one) or build a block then go home. Both decisions cost some time.</p>
<p>The time cost of spliting one worker into two workers is&nbsp;given as an integer <code>split</code>. Note that if two workers split at the same time, they split in parallel so the cost would be&nbsp;<code>split</code>.</p>
<p>Output the minimum time needed to build all blocks.</p>
<p>Initially, there is only <strong>one</strong> worker.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> blocks = [1], split = 1
<strong>Output:</strong> 1
<strong>Explanation: </strong>We use 1 worker to build 1 block in 1 time unit.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> blocks = [1,2], split = 5
<strong>Output:</strong> 7
<strong>Explanation: </strong>We split the worker into 2 workers in 5 time units then assign each of them to a block so the cost is 5 + max(1, 2) = 7.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> blocks = [1,2,3], split = 1
<strong>Output:</strong> 4
<strong>Explanation: </strong>Split 1 worker into 2, then assign the first worker to the last block and split the second worker into 2.
Then, use the two unassigned workers to build the first two blocks.
The cost is 1 + max(3, 1 + max(1, 2)) = 4.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= blocks.length &lt;= 1000</code></li>
	<li><code>1 &lt;= blocks[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= split &lt;= 100</code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

## Solution 1. Binary Answer

* After a series of splitting, we should start building the longer blocks first.
* If we have `N` blocks, we must split `N - 1` times.

With `k` splits, we have `2^k` workers. To cover all `N` blocks, we need `ceil(logN)` splits. So the upper bound of the time needed is `ceil(logN) * split + max(A)`.

The lower bound of the time needed can be set as `max(A)`.

We can binary search this answer range and find the minimum time needed to build all blocks.

`valid(time)` returns `true` if we can build all the blocks within `time`.

For a given `time` cost to build all blocks, we can traverse the blocks from longest to shortest.

Assume `used` is the time we've used to split the workers. For `A[i]`, we have `time - used - A[i]` excessive time to do `s = (time - used - A[i]) / split` splits. These splits will add `s * split` to `used`, and the number of workers `cnt` will be multiplied by `2^s` times. We use a single work for `A[i]` -- `--cnt`.

If there are still some blocks left but the `cnt` of workers becomes `0`, we return `false`. Otherwise we return `true`.

```cpp
// OJ: https://leetcode.com/problems/minimum-time-to-build-blocks
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minBuildTime(vector<int>& A, int split) {
        sort(begin(A), end(A));
        int N = A.size(), L = A.back(), R = split * ceil(log(N) / log(2)) + A.back();
        auto valid = [&](int time) {
            int cnt = 1, used = 0;
            for (int i = N - 1; i >= 0; --i) {
                if (cnt == 0) return false;
                int s = (time - used - A[i]) / split;
                if (s >= __builtin_clz(cnt)) return true;
                cnt <<= s;
                used += s * split;
                --cnt;
            }
            return true;
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```