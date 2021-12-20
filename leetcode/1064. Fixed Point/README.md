# [1064. Fixed Point (Easy)](https://leetcode.com/problems/fixed-point/)

<p>Given an array of distinct integers <code>arr</code>, where <code>arr</code> is sorted in <strong>ascending order</strong>, return the smallest index <code>i</code> that satisfies <code>arr[i] == i</code>. If there is no such index, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [-10,-5,0,3,7]
<strong>Output:</strong> 3
<strong>Explanation:</strong> For the given array, <code>arr[0] = -10, arr[1] = -5, arr[2] = 0, arr[3] = 3</code>, thus the output is 3.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [0,2,5,8,17]
<strong>Output:</strong> 0
<strong>Explanation:</strong> <code>arr[0] = 0</code>, thus the output is 0.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [-10,-5,3,4,7,9]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no such <code>i</code> that <code>arr[i] == i</code>, thus the output is -1.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt; 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> The <code>O(n)</code> solution is very straightforward. Can we do better?

**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Search (L <= R)

```cpp
// OJ: https://leetcode.com/problems/fixed-point/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int N = A.size(), L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] < M) L = M + 1;
            else R = M - 1;
        }
        return L < N && A[L] == L ? L : -1;
    }
};
```

## Solution 2. Binary Search (L < R)

```cpp
// OJ: https://leetcode.com/problems/fixed-point/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int N = A.size(), L = 0, R = N - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] < M) L = M + 1;
            else R = M;
        }
        return L < N && A[L] == L ? L : -1;
    }
};
```