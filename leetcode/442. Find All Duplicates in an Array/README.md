# [442. Find All Duplicates in an Array (Medium)](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

<p>Given an array of integers, 1 ≤ a[i] ≤ <i>n</i> (<i>n</i> = size of array), some elements appear <b>twice</b> and others appear <b>once</b>.</p>

<p>Find all the elements that appear <b>twice</b> in this array.</p>

<p>Could you do it without extra space and in O(<i>n</i>) runtime?</p>
<p></p>
<p><b>Example:</b><br>
</p><pre><b>Input:</b>
[4,3,2,7,8,2,3,1]

<b>Output:</b>
[2,3]
</pre>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& A) {
        vector<int> ans;
        int i = 0, N = A.size();
        while (i < N) {
            if (A[i] == 0 || A[i] == i + 1) ++i;
            else if (A[i] == A[A[i] - 1]) {
                ans.push_back(A[i]);
                A[i++] = 0;
            } else swap(A[i], A[A[i] - 1]);
        }
        return ans;
    }
};
```