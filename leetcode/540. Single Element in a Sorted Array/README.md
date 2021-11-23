# [540. Single Element in a Sorted Array (Medium)](https://leetcode.com/problems/single-element-in-a-sorted-array/)

<p>You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.</p>

<p>Return <em>the single element that appears only once</em>.</p>

<p>Your solution must run in <code>O(log n)</code> time and <code>O(1)</code> space.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>Output:</strong> 2
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,3,7,7,10,11,11]
<strong>Output:</strong> 10
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if ((M % 2 == 0 && A[M] == A[M + 1])
               || (M % 2 == 1 && A[M] == A[M - 1])) L = M + 1;
                else R = M;
        }
        return A[L];
    }
};
```

## Solution 2. Binary Search on Even Indices Only

We make sure the `M` is always even number. Then we check whether `A[M] == A[M + 1]`.

* If equal, `L = M + 2`. (Example: `1 1 [2] 2 3`, or `1 1 [2] 2 3 3 4`)
* otherwise, `R = M`. (Example: `1 2 [2] 3 3`, or `1 2 [2] 3 3 4 4`, or `1 1 [2] 3 3`)

```cpp
// OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (M % 2) M--;
            if (A[M] == A[M + 1]) L = M + 2;
            else R = M;
        }
        return A[L];
    }
};
```

## Solution 3. Binary Search

```cpp
// OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int N = A.size(), L = 0, R = N - 1;
        auto valid = [&](int M) { // returns `true` is the index of the single element < M
            return M % 2 ? (M + 1 < N && A[M] == A[M + 1]) : (M - 1 >= 0 && A[M] == A[M - 1]);
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return A[R];
    }
};
```