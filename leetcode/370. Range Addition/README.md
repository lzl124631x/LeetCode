# [370. Range Addition (Medium)](https://leetcode.com/problems/range-addition/)

<p>Assume you have an array of length <b><i>n</i></b> initialized with all <b>0</b>'s and are given <b><i>k</i></b> update operations.</p>

<p>Each operation is represented as a triplet: <b>[startIndex, endIndex, inc]</b> which increments each element of subarray <b>A[startIndex ... endIndex]</b> (startIndex and endIndex inclusive) with <b>inc</b>.</p>

<p>Return the modified array after all <b><i>k</i></b> operations were executed.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input: </strong>length = <span id="example-input-1-1">5</span>, updates = <span id="example-input-1-2">[[1,3,2],[2,4,3],[0,2,-2]]</span>
<strong>Output: </strong><span id="example-output-1">[-2,0,3,5,3]</span>
</pre>

<p><b>Explanation:</b></p>

<pre>Initial state:
[0,0,0,0,0]

After applying operation [1,3,2]:
[0,2,2,2,0]

After applying operation [2,4,3]:
[0,2,5,5,3]

After applying operation [0,2,-2]:
[-2,0,3,5,3]
</pre>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Range Addition II (Easy)](https://leetcode.com/problems/range-addition-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/range-addition/
// Author: github.com/lzl124631x
// Time: O(N+U)
// Space: O(1)
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for (auto &u : updates) {
            int start = u[0], end = u[1], val = u[2];
            ans[start] += val;
            if (end + 1 < length) ans[end + 1] -= val;
        }
        partial_sum(ans.begin(), ans.end(), ans.begin());
        return ans;
    }
};
```