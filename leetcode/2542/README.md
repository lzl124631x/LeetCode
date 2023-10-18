# [2542. Maximum Subsequence Score (Medium)](https://leetcode.com/problems/maximum-subsequence-score)

<p>You are given two <strong>0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code> of equal length <code>n</code> and a positive integer <code>k</code>. You must choose a <strong>subsequence</strong> of indices from <code>nums1</code> of length <code>k</code>.</p>

<p>For chosen indices <code>i<sub>0</sub></code>, <code>i<sub>1</sub></code>, ..., <code>i<sub>k - 1</sub></code>, your <strong>score</strong> is defined as:</p>

<ul>
	<li>The sum of the selected elements from <code>nums1</code> multiplied with the <strong>minimum</strong> of the selected elements from <code>nums2</code>.</li>
	<li>It can defined simply as: <code>(nums1[i<sub>0</sub>] + nums1[i<sub>1</sub>] +...+ nums1[i<sub>k - 1</sub>]) * min(nums2[i<sub>0</sub>] , nums2[i<sub>1</sub>], ... ,nums2[i<sub>k - 1</sub>])</code>.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> possible score.</em></p>

<p>A <strong>subsequence</strong> of indices of an array is a set that can be derived from the set <code>{0, 1, ..., n-1}</code> by deleting some or no elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
<strong>Output:</strong> 12
<strong>Explanation:</strong> 
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
<strong>Output:</strong> 30
<strong>Explanation:</strong> 
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[j] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [DE Shaw](https://leetcode.com/company/de-shaw)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Greedy](https://leetcode.com/tag/greedy), [Sorting](https://leetcode.com/tag/sorting), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue)

**Similar Questions**:
* [IPO (Hard)](https://leetcode.com/problems/ipo)
* [Minimum Cost to Hire K Workers (Hard)](https://leetcode.com/problems/minimum-cost-to-hire-k-workers)

**Hints**:
* How can we use sorting here?
* Try sorting the two arrays based on second array.
* Loop through nums2 and compute the max product given the minimum is nums2[i]. Update the answer accordingly.

## Solution 1. Sorting + Heap

**Intuition**: If we sort `B` and traverse `B` in a specific order, we can easily know the minimum value. The next thing we need to figure out is the maximum `k` elements in `A`.

**Algorithm**:

Zip `A` and `B` into an array `C` such that `C[i] = (A[i], B[i])`. Sort `C` in descending order of the 2nd dimension, i.e. `B` values.

Traverse `C` from left to right. The last seen `B` value is the minimum value. To track the top `K` elements, we use a min heap. Whenever we visit a new `C[i]`, we push its `A` value into the heap, and add this value to `sum`. When heap has more than `K` elements, we pop the top, and remove this top value from `sum`. In this way, we keep track of the `sum` of the top `K` elements.

```cpp
// OJ: https://leetcode.com/problems/maximum-subsequence-score
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    long long maxScore(vector<int>& A, vector<int>& B, int k) {
        vector<pair<int, int>> C;
        long long N = A.size(), sum = 0, ans = 0;
        for (int i = 0; i < N; ++i) C.emplace_back(A[i], B[i]);
        sort(begin(C), end(C), [](auto &a, auto &b) { return a.second > b.second; });
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < N; ++i) {
            auto &[a, b] = C[i];
            pq.push(a);
            sum += a;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (i >= k - 1) ans = max(ans, b * sum);
        }
        return ans;
    }
};
```