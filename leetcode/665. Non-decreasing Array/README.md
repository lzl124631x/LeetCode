# [665. Non-decreasing Array (Medium)](https://leetcode.com/problems/non-decreasing-array/)

<p>Given an array <code>nums</code> with <code>n</code> integers, your task is to check if it could become non-decreasing by modifying <strong>at most one element</strong>.</p>

<p>We define an array is non-decreasing if <code>nums[i] &lt;= nums[i + 1]</code> holds for every <code>i</code> (<strong>0-based</strong>) such that (<code>0 &lt;= i &lt;= n - 2</code>).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,3]
<strong>Output:</strong> true
<strong>Explanation:</strong> You could modify the first <code>4</code> to <code>1</code> to get a non-decreasing array.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,1]
<strong>Output:</strong> false
<strong>Explanation:</strong> You can't get a non-decreasing array by modify at most one element.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Make Array Non-decreasing or Non-increasing (Hard)](https://leetcode.com/problems/make-array-non-decreasing-or-non-increasing/)
* [Find Good Days to Rob the Bank (Medium)](https://leetcode.com/problems/find-good-days-to-rob-the-bank/)

## Solution 1. Two Passes

This problem is asking whether the array is non-decreasing after deleting at most one element.

We can try deleting one element at each position, and return `true` if it satisfies the following condition:

```
A[i+1] >= A[i-1] && i >= R
```

where `A[R]` is the rightmost element that `A[R] > A[R+1]`. That is, for any `i >= R`, the right part `A[i+1 .. N-1]` is non-decreasing.

Once `A[i] < A[i-1]`, we should stop scanning because the left part won't be non-decreasing.

```cpp
// OJ: https://leetcode.com/problems/non-decreasing-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& A) {
        int N = A.size(), R = N - 2;
        for (; R >= 0 && A[R] <= A[R + 1]; --R);
        for (int i = 0; i < N; ++i) {
            if ((i == 0 || i == N - 1 || A[i + 1] >= A[i - 1]) && i >= R) return true;
            if (i - 1 >= 0 && A[i] < A[i - 1]) break;
        }
        return false;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/non-decreasing-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& A) {
        for (int i = 1, cnt = 0; i < A.size(); ++i) {
            if (A[i] >= A[i - 1]) continue;
            if (++cnt > 1) return false;
            if (i - 2 < 0 || min(A[i], A[i - 1]) >= A[i - 2]) A[i] = A[i - 1] = min(A[i], A[i - 1]);
            else A[i] = A[i - 1] = max(A[i], A[i - 1]);
        }
        return true;
    }
};
```