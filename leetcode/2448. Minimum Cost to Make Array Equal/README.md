# [2448. Minimum Cost to Make Array Equal (Hard)](https://leetcode.com/problems/minimum-cost-to-make-array-equal)

<p>You are given two <strong>0-indexed</strong> arrays <code>nums</code> and <code>cost</code> consisting each of <code>n</code> <strong>positive</strong> integers.</p>
<p>You can do the following operation <strong>any</strong> number of times:</p>
<ul>
	<li>Increase or decrease <strong>any</strong> element of the array <code>nums</code> by <code>1</code>.</li>
</ul>
<p>The cost of doing one operation on the <code>i<sup>th</sup></code> element is <code>cost[i]</code>.</p>
<p>Return <em>the <strong>minimum</strong> total cost such that all the elements of the array </em><code>nums</code><em> become <strong>equal</strong></em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,5,2], cost = [2,3,1,14]
<strong>Output:</strong> 8
<strong>Explanation:</strong> We can make all the elements equal to 2 in the following way:
- Increase the 0<sup>th</sup> element one time. The cost is 2.
- Decrease the 1<sup><span style="font-size: 10.8333px;">st</span></sup> element one time. The cost is 3.
- Decrease the 2<sup>nd</sup> element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,2,2,2], cost = [4,2,8,1,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> All the elements are already equal, so no operations are needed.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == nums.length == cost.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], cost[i] &lt;= 10<sup>6</sup></code></li>
	<li>Test cases are generated in a way that the output doesn't exceed&nbsp;2<sup>53</sup>-1</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Minimum Moves to Equal Array Elements II (Medium)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)
* [Maximum Product of the Length of Two Palindromic Substrings (Hard)](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/)
* [Minimum Amount of Time to Fill Cups (Easy)](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/)
* [Minimum Operations to Make All Array Elements Equal (Medium)](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/)

## Solution 1. Left-to-right State Transition

We first sort the arrays together in accending order of the **numbers**.

For example, `A = [1,3,5,2], C = [2,3,1,14]`, then after sorting, they become `A = [1,2,3,5], C = [2,14,3,1]`.

We scan the numbers from left to right. 

Let `rightSum` be the sum of costs of numbers greater than or equal to the current number, `leftSum` be the cost of numbers smaller than the current number, `totalCost` be the total cost needed to change all numbers to be the same as the current number.

When we move from `A[i-1]` to `A[i]`, let `d = A[i] - A[i-1]`, the `totalCost` need to `- d * rightSum` and `+ d * leftSum`.

For example, `A = [1,2,3,5], C = [2,14,3,1]`. When we move from `A[0] = 1` to `A[1] = 2`, `d = 1`, the `totalCost` at `A[0]` was `0 * 2 + 1 * 14 + 2 * 3 + 4 * 1`, and now we need to change `totalCost` by `- d * rightSum = -1 * (14 + 3 + 1)` and `+ d * leftSum = +1 * (2)`, so the `totalCost` becomes `1 * 2 + 0 * 14 + 1 * 3 + 3 * 1`.

After calculating `totalCost` for `A[i]`, we update `rightSum` by `-C[i]` and `leftSum` by `+C[i]`.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-make-array-equal
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    long long minCost(vector<int>& A, vector<int>& C) {
        long long rightSum = accumulate(begin(C), end(C), 0LL), leftSum = 0, ans = LLONG_MAX, N = A.size(), prev = 0, totalCost = 0;
        vector<int> id(N);
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return A[a] < A[b]; });
        for (int i = 0; i < N; ++i) totalCost += (long long)A[i] * C[i];
        for (int i = 0; i < N; ++i) {
            long long num = A[id[i]], cost = C[id[i]], d = num - prev;
            totalCost = totalCost + d * (leftSum - rightSum);
            ans = min(ans, totalCost);
            rightSum -= cost;
            leftSum += cost;
            prev = num;
        }
        return ans;
    }
};
```