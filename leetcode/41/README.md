# [41. First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive/)

<p>Given an unsorted integer array, find the smallest missing&nbsp;positive integer.</p>

<p><strong>Example 1:</strong></p>

<pre>Input: [1,2,0]
Output: 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>Input: [3,4,-1,1]
Output: 2
</pre>

<p><strong>Example 3:</strong></p>

<pre>Input: [7,8,9,11,12]
Output: 1
</pre>

<p><strong>Note:</strong></p>

<p>Your algorithm should run in <em>O</em>(<em>n</em>) time and uses constant extra space.</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Missing Number (Easy)](https://leetcode.com/problems/missing-number/)
* [Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number/)
* [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
* [Couples Holding Hands (Hard)](https://leetcode.com/problems/couples-holding-hands/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/first-missing-positive/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int i, N = A.size();
        for (i = 0; i < N; ) {
            if (A[i] == i + 1 || A[i] < 1 || A[i] >= N + 1 || A[i] == A[A[i] - 1]) ++i;
            else swap(A[i], A[A[i] - 1]);
        }
        for (i = 0; i < N && A[i] == i + 1; ++i);
        return i + 1;
    }
};
```