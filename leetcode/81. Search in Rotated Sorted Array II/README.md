# [81. Search in Rotated Sorted Array II (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

<p>There is an integer array <code>nums</code> sorted in non-decreasing order (not necessarily with <strong>distinct</strong> values).</p>

<p>Before being passed to your function, <code>nums</code> is <strong>rotated</strong> at an unknown pivot index <code>k</code> (<code>0 &lt;= k &lt; nums.length</code>) such that the resulting array is <code>[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]</code> (<strong>0-indexed</strong>). For example, <code>[0,1,2,4,4,4,5,6,6,7]</code> might be rotated at pivot index <code>5</code> and become <code>[4,5,6,6,7,0,1,2,4,4]</code>.</p>

<p>Given the array <code>nums</code> <strong>after</strong> the rotation and an integer <code>target</code>, return <code>true</code><em> if </em><code>target</code><em> is in </em><code>nums</code><em>, or </em><code>false</code><em> if it is not in </em><code>nums</code><em>.</em></p>

<p>You must decrease the overall operation steps as much as possible.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,5,6,0,0,1,2], target = 0
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,5,6,0,0,1,2], target = 3
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is guaranteed to be rotated at some pivot.</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> This problem is similar to&nbsp;<a href="/problems/search-in-rotated-sorted-array/description/" target="_blank">Search in Rotated Sorted Array</a>, but&nbsp;<code>nums</code> may contain <strong>duplicates</strong>. Would this affect the runtime complexity? How and why?</p>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Search in Rotated Sorted Array (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## Solution 1.

* A[L] < A[R] => L
* A[L] == A[R]
  - A[M] > A[R] => L = M + 1
  - A[M] < A[R] => R = M
  - A[M] == A[R] => Special
* A[L] > A[R]
  - A[M] > A[R] => L = M + 1
  - A[M] < A[R] => R = M
  - A[M] == A[R] => R = M

Special part: `A[L] == A[M] == A[R]`

Find the first `L < k < R` that `A[k] != A[L]`:

* No such `k`, return `L`
* `A[k] < A[L]`, return `k`
* `A[k] > A[L]`, let `L = k + 1` and continue.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/lzl124631x
// Time: average O(logN), worst O(N)
// Space: O(1)
class Solution {
    int findStart(vector<int> &A) {
        int L = 0, R = A.size() - 1;
        while (L + 1 < R) {
            if (A[L] < A[R]) return L;
            int M = (L + R) / 2;
            if (A[M] > A[R]) L = M + 1;
            else if (A[M] < A[R] || (A[M] == A[R] && A[L] > A[R])) R = M;
            else {
                int k = L;
                while (k < R && A[L] == A[k]) ++k;
                if (k == R) return L;
                if (A[k] < A[L]) return k;
                L = k + 1;
            }
        }
        return A[L] < A[R] ? L : R;
    }
public:
    bool search(vector<int>& A, int T) {
        if (A.empty()) return false;
        int start = findStart(A), N = A.size(), L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2, mid = (start + M) % N;
            if (A[mid] == T) return true;
            if (A[mid] < T) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/lzl124631x
// Time: average O(logN), worst O(N)
// Space: O(1)
class Solution {
public:
    bool search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return true;
            if (A[0] > A[M]) {
                if (target > A[M]) {
                    if (target <= A.back()) L = M + 1;
                    else R = M - 1;
                } else R = M - 1;
            } else if (A[0] < A[M]) {
                if (target > A[M]) L = M + 1;
                else {
                    if (target >= A[0]) R = M - 1; 
                    else L = M + 1;
                }
            } else if (A[L] == target) return true;
            else ++L;
        }
        return false;
    }
};
```

We can compress the code a bit if we want.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/lzl124631x
// Time: average O(logN), worst O(N)
// Space: O(1)
class Solution {
public:
    bool search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target || A[L] == target) return true;
            if (A[0] == A[M]) ++L;
            else if ((A[0] > A[M] && target > A[M] && target <= A.back())
                || (A[0] < A[M] && (target > A[M] || target < A[0]))) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/lzl124631x
// Time: O(logN) on average, O(N) in the worst case
// Space: O(1)
class Solution {
public:
    bool search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return true;
            if (A[M] == A[R]) --R;
            else if (A[M] < A[R]) {
                if (A[M] > target) R = M - 1;
                else if (A[R] < target) R = M - 1;
                else L = M + 1;
            } else {
                if (A[M] < target) L = M + 1;
                else if (A[R] < target) R = M - 1;
                else L = M + 1;
            }
        }
        return false;
    }
};
```