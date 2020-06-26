# [287. Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number/)

<p>Given an array <i>nums</i> containing <i>n</i> + 1 integers where each integer is between 1 and <i>n</i> (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> <code>[1,3,4,2,2]</code>
<b>Output:</b> 2
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [3,1,3,4,2]
<b>Output:</b> 3</pre>

<p><b>Note:</b></p>

<ol>
	<li>You <b>must not</b> modify the array (assume the array is read only).</li>
	<li>You must use only constant, <i>O</i>(1) extra space.</li>
	<li>Your runtime complexity should be less than <em>O</em>(<em>n</em><sup>2</sup>).</li>
	<li>There is only one duplicate number in the array, but it could be repeated more than once.</li>
</ol>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive/)
* [Single Number (Easy)](https://leetcode.com/problems/single-number/)
* [Linked List Cycle II (Medium)](https://leetcode.com/problems/linked-list-cycle-ii/)
* [Missing Number (Easy)](https://leetcode.com/problems/missing-number/)
* [Set Mismatch (Easy)](https://leetcode.com/problems/set-mismatch/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/find-the-duplicate-number/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int L = 1, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2, cnt = 0;
            for (int n : A) cnt += n <= M;
            if (cnt <= M) L = M + 1;
            else R = M;
        }
        return L;
    }
};
```

## Solution 2. Floyd's Tortoise and Hare (Cycle Detection)

```cpp
// OJ: https://leetcode.com/problems/find-the-duplicate-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int N = A.size(), slow = A[N - 1], fast = A[slow - 1];
        for (; slow != fast; slow = A[slow - 1], fast = A[A[fast - 1] - 1]);
        for (slow = N; slow != fast; slow = A[slow - 1], fast = A[fast - 1]);
        return slow;
    }
};
```