# [1330. Reverse Subarray To Maximize Array Value (Hard)](https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/)

<p>You are given an integer array <code>nums</code>. The <em>value</em> of this array is defined as the sum of <code>|nums[i]-nums[i+1]|</code>&nbsp;for all&nbsp;<code>0 &lt;= i &lt; nums.length-1</code>.</p>

<p>You are allowed to select any subarray of the given array and reverse it. You can perform this operation <strong>only once</strong>.</p>

<p>Find maximum possible value of the final array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,1,5,4]
<strong>Output:</strong> 10
<b>Explanation: </b>By reversing the subarray [3,1,5] the array becomes [2,5,1,3,4] whose value is 10.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,4,9,24,2,1,10]
<strong>Output:</strong> 68
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3*10^4</code></li>
	<li><code>-10^5 &lt;= nums[i] &lt;= 10^5</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

Let `f` be the value function, i.e. `f = |A[0] - A[1]| + |A[1] - A[2] + ... + |A[N - 2] - A[N - 1]|`.

If the array is `[..., a, b, ..., c, d, ...]` and the subarray `[b, ..., c]` (whose length `>= 2`) is reversed, then the function `f` is only changed around the boundry `(a, b)` and `(c, d)`.

If the interval `[min(a,b), max(a,b)]` and `[min(c,d), max(c,d)]` intersect, then swapping the subarray can only keep the same value or decrease the value.


Since before the swap the value at the boundaries is:

```
|a-b| + |c-d| = max(a,b) - min(a,b) + max(c,d) - min(c,d)
```

After the swap, the value at the boundaries becomes:

```
|a-c| + |b-d|    = |max(a,b) - max(c,d)| + |min(a,b) - min(c,d)|        -- (1)
              OR = |max(a,b) - min(c,d)| + |min(a,b) - max(c,d)|        -- (2)
```

If the intervals have overlap:
* Before the swap the value counts the overlap **twice**
* After the swap, the value either counts the overlap **zero** (case 1) or **two** (case 2) times.

Hence we only consider the case where the intervals don't overlap -- the value changes from "containing no overlap before the swap" to "containing the overlap twice after the swap".

Our goal then becomes finding the maximum gap between the intervals.

The gap is one of the following cases:

*  `min(a,b) - max(c,d)` when `min(a,b) > max(c,d)`
*  `min(c,d) - max(a,b)` when `min(c,d) > max(a,b)`

For the case `min(a,b) - max(c,d)`, we need to keep track of the `high = max(min(a,b))`.
For the case `min(c,d) - max(a,b)`, we need to keep track of the `low = min(max(a,b))`.

Lastly, we need to consider the case where there is no `a` or `d`, i.e. the subarray starts at the begining of `A` or ends at the end of `A`.

```cpp
// OJ: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/discuss/489716/Python-O(n)
class Solution {
public:
    int maxValueAfterReverse(vector<int>& A) {
        if (A.size() == 2) return abs(A[0] - A[1]);
        int ans = 0, N = A.size(), maxGap = 0, low = max(A[0], A[1]), high = min(A[0], A[1]);
        for (int i = 1; i < N; ++i) ans += abs(A[i] - A[i - 1]);
        for (int i = 3; i < N; ++i) {
            maxGap = max({ maxGap, high - max(A[i - 1], A[i]), min(A[i - 1], A[i]) - low });
            high = max(high, min(A[i - 2], A[i - 1]));
            low = min(low, max(A[i - 2], A[i - 1]));
        }
        maxGap *= 2;
        for (int i = 0; i < N - 2; ++i) maxGap = max(maxGap, abs(A[N - 1] - A[i]) - abs(A[i + 1] - A[i]));
        for (int i = 2; i < N; ++i) maxGap = max(maxGap, abs(A[0] - A[i]) - abs(A[i] - A[i - 1]));
        return ans + maxGap;
    }
};
```