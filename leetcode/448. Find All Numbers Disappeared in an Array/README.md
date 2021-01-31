# [448. Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

<p>Given an array of integers where 1 ≤ a[i] ≤ <i>n</i> (<i>n</i> = size of array), some elements appear twice and others appear once.</p>

<p>Find all the elements of [1, <i>n</i>] inclusive that do not appear in this array.</p>

<p>Could you do it without extra space and in O(<i>n</i>) runtime? You may assume the returned list does not count as extra space.</p>

<p><b>Example:</b>
</p><pre><b>Input:</b>
[4,3,2,7,8,2,3,1]

<b>Output:</b>
[5,6]
</pre>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive/)
* [Find All Duplicates in an Array (Medium)](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            while (A[A[i] - 1] != A[i]) swap(A[A[i] - 1], A[i]);
        }
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            if (A[i] != i + 1) ans.push_back(i + 1);
        }
        return ans;
    }
};
```