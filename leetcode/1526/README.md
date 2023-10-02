# [1526. Minimum Number of Increments on Subarrays to Form a Target Array (Hard)](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/)

<p>Given an array of positive integers <code>target</code> and an array <code>initial</code> of same size with all zeros.</p>

<p>Return the minimum number of operations to form a <code>target</code> array from <code>initial</code>&nbsp;if you are allowed to do the following operation:</p>

<ul>
	<li>Choose <strong>any</strong> subarray from <code>initial</code>&nbsp;and increment each value by one.</li>
</ul>
The answer is guaranteed to fit within the range of a 32-bit signed integer.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> target = [1,2,3,2,1]
<strong>Output:</strong> 3
<strong>Explanation: </strong>We need at least 3 operations to form the target array from the initial array.
[0,0,0,0,0] increment 1 from index 0 to 4&nbsp;(inclusive).
[1,1,1,1,1] increment 1 from index 1 to 3&nbsp;(inclusive).
[1,2,2,2,1] increment 1 at index 2.
[1,2,3,2,1] target array is formed.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> target = [3,1,1,2]
<strong>Output:</strong> 4
<strong>Explanation: </strong>(initial)[0,0,0,0] -&gt; [1,1,1,1] -&gt; [1,1,1,2] -&gt; [2,1,1,2] -&gt; [3,1,1,2] (target).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> target = [3,1,5,4,2]
<strong>Output:</strong> 7
<strong>Explanation: </strong>(initial)[0,0,0,0,0] -&gt; [1,1,1,1,1] -&gt; [2,1,1,1,1] -&gt; [3,1,1,1,1] 
                                  -&gt; [3,1,2,2,2] -&gt; [3,1,3,3,2] -&gt; [3,1,4,4,2] -&gt; [3,1,5,4,2] (target).
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> target = [1,1,1,1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= target[i] &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Segment Tree](https://leetcode.com/tag/segment-tree/)

## Solution 1. 

I found that a small number will break the increments into two parts. For example `[2, 1, 2]`, you can't increment both the first and last `2` at the same time because there is a smaller number `1` in between. So we need to pay attention to those small numbers.

I also tried to see if it's possible to resolve this problem using a linear scan, and it turns out working. Take some inputs as examples.

For input `[3 1 5]`:
* To get `3`, we need 3 increments.
* To get `1`, since it's smaller than `3`, we can get `1` while getting `3`, so we don't need additional increment.
* To get `5`, since `5` is greater than `1`, we need `5 - 1 = 4` more increments to get `5`.
* In total we need `3 + 0 + 4` increments.

I also verified this algorithm with inputs like `[1, 2, 3]` and `[2, 1, 2]` to check the correctness.

The algorithm would be as simple as:
* Linear scan the array.
* For `A[i]`, if it's greater than `A[i - 1]`, then increment answer by `A[i] - A[i - 1]`; otherwise, do nothing.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minNumberOperations(vector<int>& A) {
        int ans = A[0];
        for (int i = 1; i < A.size(); ++i) ans += max(0, A[i] - A[i - 1]);
        return ans;
    }
};
```

We can compress it into two lines.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minNumberOperations(vector<int>& A) {
        for (int i = A.size() - 1; i > 0; --i) A[i] = max(0, A[i] - A[i - 1]);
        return accumulate(begin(A), end(A), 0);
    }
};
```

This would be a one liner in python

```py
# OJ: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
# Author: github.com/lzl124631x
# Time: O(N)
# Space: O(1)
class Solution:
    def minNumberOperations(self, A: List[int]) -> int:
        return sum([max(0, x - y) for x, y in zip(A, [0] + A)])
```