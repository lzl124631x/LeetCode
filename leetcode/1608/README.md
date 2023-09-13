# [1608. Special Array With X Elements Greater Than or Equal X (Easy)](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/)

<p>You are given an array <code>nums</code> of non-negative integers. <code>nums</code> is considered <strong>special</strong> if there exists a number <code>x</code> such that there are <strong>exactly</strong> <code>x</code> numbers in <code>nums</code> that are <strong>greater than or equal to</strong> <code>x</code>.</p>

<p>Notice that <code>x</code> <strong>does not</strong> have to be an element in <code>nums</code>.</p>

<p>Return <code>x</code> <em>if the array is <strong>special</strong>, otherwise, return </em><code>-1</code>. It can be proven that if <code>nums</code> is special, the value for <code>x</code> is <strong>unique</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 values (3 and 5) that are greater than or equal to 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0]
<strong>Output:</strong> -1
<strong>Explanation:</strong> No numbers fit the criteria for x.
If x = 0, there should be 0 numbers &gt;= x, but there are 2.
If x = 1, there should be 1 number &gt;= x, but there are 0.
If x = 2, there should be 2 numbers &gt;= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [0,4,3,0,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 values that are greater than or equal to 3.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [3,6,7,7,0]
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int specialArray(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size();
        for (int i = 0; i <= N; ++i) {
            int cnt = N - (lower_bound(begin(A), end(A), i) - begin(A));
            if (cnt == i) return i;
        }
        return -1;
    }
};
```

## Solution 2.

We store the count of numbers in a `cnt` array. And we just need to iterate from `max(A)` towards `0` to find the valid value, because for any `k > max(A)`, there are 0 elements `>= k` and thus must be invalid.

```cpp
// OJ: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
// Author: github.com/lzl124631x
// Time: O(N + max(A))
// Space: O(max(A))
class Solution {
public:
    int specialArray(vector<int>& A) {
        int cnt[1001] = {};
        for (int n : A) cnt[n]++;
        for (int i = 999; i >= 0; --i) {
            cnt[i] += cnt[i + 1];
            if (cnt[i] == i) return i;
        }
        return -1;
    }
};
```

## Solution 3. Binary Search

The sorting part takes `O(NlogN)`. But the rest just takes `O(logN)`.

```cpp
// OJ: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int specialArray(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size(), L = 0, R = N;
        while (L <= R) {
            int M = (L + R) / 2;
            bool cur = M == 0 || A[N - M] >= M, prev = M == N || A[N - M - 1] < M;
            if (cur && prev) return M;
            if (!cur) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
};
```