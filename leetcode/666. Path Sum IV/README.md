# [666. Path Sum IV (Medium)](https://leetcode.com/problems/path-sum-iv/)

<p>
If the depth of a tree is smaller than <code>5</code>, then this tree can be represented by a list of three-digits integers.
</p>

<p>
For each integer in this list:<br>
</p><ol>
<li>The hundreds digit represents the depth <code>D</code> of this node, <code>1 &lt;= D &lt;= 4.</code></li>
<li>The tens digit represents the position <code>P</code> of this node in the level it belongs to, <code>1 &lt;= P &lt;= 8</code>. The position is the same as that in a full binary tree. </li>
<li>The units digit represents the value <code>V</code> of this node, <code>0 &lt;= V &lt;= 9.</code></li>
</ol>
<p></p>

<p>
Given a list of <code>ascending</code> three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [113, 215, 221]
<b>Output:</b> 12
<b>Explanation:</b> 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [113, 221]
<b>Output:</b> 4
<b>Explanation:</b> 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.
</pre>
<p></p>

**Companies**:  
[Alibaba](https://leetcode.com/company/alibaba)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Path Sum (Easy)](https://leetcode.com/problems/path-sum/)
* [Path Sum II (Medium)](https://leetcode.com/problems/path-sum-ii/)
* [Binary Tree Maximum Path Sum (Hard)](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
* [Path Sum III (Easy)](https://leetcode.com/problems/path-sum-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/path-sum-iv/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n / 10] = n % 10;
        }
        int sum = 0;
        for (int n : nums) {
            int d = n / 100, p = n / 10 % 10, v = m[d * 10 + p];
            int left = (d + 1) * 10 + p * 2 - 1, right = left + 1;
            if (m.find(left) != m.end()) m[left] += v;
            if (m.find(right) != m.end()) m[right] += v;
            if (m.find(left) == m.end() && m.find(right) == m.end()) sum += v;
        }
        return sum;
    }
};
```