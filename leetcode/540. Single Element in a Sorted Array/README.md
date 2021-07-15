# [540. Single Element in a Sorted Array (Medium)](https://leetcode.com/problems/single-element-in-a-sorted-array/)

<p>
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once. 
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,1,2,3,3,4,4,8,8]
<b>Output:</b> 2
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [3,3,7,7,10,11,11]
<b>Output:</b> 10
</pre>
<p></p>

<p><b>Note:</b>
Your solution should run in O(log n) time and O(1) space.
</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

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

## Solution 2. Binary Search

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