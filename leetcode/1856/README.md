# [1856. Maximum Subarray Min-Product (Medium)](https://leetcode.com/problems/maximum-subarray-min-product/)

<p>The <strong>min-product</strong> of an array is equal to the <strong>minimum value</strong> in the array <strong>multiplied by</strong> the array's <strong>sum</strong>.</p>

<ul>
	<li>For example, the array <code>[3,2,5]</code> (minimum value is <code>2</code>) has a min-product of <code>2 * (3+2+5) = 2 * 10 = 20</code>.</li>
</ul>

<p>Given an array of integers <code>nums</code>, return <em>the <strong>maximum min-product</strong> of any <strong>non-empty subarray</strong> of </em><code>nums</code>. Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>Note that the min-product should be maximized <strong>before</strong> performing the modulo operation. Testcases are generated such that the maximum min-product <strong>without</strong> modulo will fit in a <strong>64-bit signed integer</strong>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,<u>2,3,2</u>]
<strong>Output:</strong> 14
<strong>Explanation:</strong> The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
2 * (2+3+2) = 2 * 7 = 14.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,<u>3,3</u>,1,2]
<strong>Output:</strong> 18
<strong>Explanation:</strong> The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
3 * (3+3) = 3 * 6 = 18.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,<u>5,6,4</u>,2]
<strong>Output:</strong> 60
<strong>Explanation:</strong> The maximum min-product is achieved with the subarray [5,6,4] (minimum value is 4).
4 * (5+6+4) = 4 * 15 = 60.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

## Solution 1. Next Smaller Element

**Intuition**: For a given number `A[i]`, we only care about the subarray `[p + 1, q - 1]` where `p` and `q` are the index to the previous and next smaller element.

**Why do we use the next/previous smaller element as the boundary?**:
For example:

```
 0 1 2 3 4 5 // index
[3,1,5,6,4,2] // value
```

For `A[1] = 1`, it's the smallest value of the entire array. So we should use the sum of the entire array.

For `A[5] = 2`, it's the second smallest value. We won't want to extend the subarray to index `1` because then the minimum value will become `1` and fall back to the previous case. So we only use subarray `[5,6,4,2]`.

Similarly, for other numbers. In essense, we don't want to go over the previous/next smaller element.

**Algorithm**:

1. Store prefix sum in `sum` array.
2. Store the indexes to the previous/next smaller element into `prev`/`next` array. 
3. For `A[i]`, the max product including it is `A[i] * SUM(prev[i] + 1, next[i] - 1)` where `SUM(i, j)` is the sum of subarray `A[i..j]`.

For "how to get the next smaller element", check out the mono-stack solutions to [496. Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/)

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray-min-product/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSumMinProduct(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size(), ans = 0;
        vector<long> sum(N + 1); // prefix sum
        vector<int> prev(N, -1), next(N, N); // prev[i]/next[i] is the index of the previous/next smaller element
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        stack<int> s; // monotonic stack
        for (int i = 0; i < N; ++i) { // fill `next` array
            while (s.size() && A[s.top()] > A[i]) {
                next[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        s = {};
        for (int i = N - 1; i >= 0; --i) { // fill `prev` array
            while (s.size() && A[s.top()] > A[i]) {
                prev[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < N; ++i) {
            ans = max(ans, (sum[next[i]] - sum[prev[i] + 1]) * A[i]);
        }
        return ans % mod;
    }
};
```