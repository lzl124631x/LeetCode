# [119. Pascal's Triangle II (Easy)](https://leetcode.com/problems/pascals-triangle-ii/)

<p>Given a non-negative&nbsp;index <em>k</em>&nbsp;where <em>k</em> ≤&nbsp;33, return the <em>k</em><sup>th</sup>&nbsp;index row of the Pascal's triangle.</p>

<p>Note that the row index starts from&nbsp;0.</p>

<p><img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif"><br>
<small>In Pascal's triangle, each number is the sum of the two numbers directly above it.</small></p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 3
<strong>Output:</strong> [1,3,3,1]
</pre>

<p><strong>Follow up:</strong></p>

<p>Could you optimize your algorithm to use only <em>O</em>(<em>k</em>) extra space?</p>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/pascals-triangle-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                ans[j] += ans[j - 1];
            }
        }
        return ans;
    }
};
```