# [118. Pascal's Triangle (Easy)](https://leetcode.com/problems/pascals-triangle/)

<p>Given a non-negative integer&nbsp;<em>numRows</em>, generate the first <em>numRows</em> of Pascal's triangle.</p>

<p><img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" style="height:240px; width:260px"><br>
<small>In Pascal's triangle, each number is the sum of the two numbers directly above it.</small></p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 5
<strong>Output:</strong>
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
</pre>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/pascals-triangle/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; ++i) {
            ans[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};
```