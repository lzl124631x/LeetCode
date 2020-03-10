# [1104. Path In Zigzag Labelled Binary Tree (Medium)](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/)

<p>In an infinite binary tree where every node has two children, the nodes are labelled in row order.</p>

<p>In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/06/24/tree.png" style="width: 300px; height: 138px;"></p>

<p>Given the <code>label</code> of a node in this tree, return the labels in the path from the root of the tree to the&nbsp;node with that <code>label</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> label = 14
<strong>Output:</strong> [1,3,4,14]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> label = 26
<strong>Output:</strong> [1,2,6,10,26]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= label &lt;= 10^6</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
    inline int r(int label, int row) {
        return 3 * (1 << row) - label - 1;
    }
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans(1, label);
        while (label != 1) {
            int row = log2(label);
            if (row % 2) label = r(label, row) / 2;
            else label = r(label / 2, row - 1);
            ans.push_back(label);
            --row;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```