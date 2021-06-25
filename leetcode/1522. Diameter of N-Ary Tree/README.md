# [1522. Diameter of N-Ary Tree (Medium)](https://leetcode.com/problems/diameter-of-n-ary-tree/)

<p>Given a <code>root</code> of an <a href="https://leetcode.com/articles/introduction-to-n-ary-trees/" target="_blank">N-ary tree</a>, you need to compute the length of the diameter of the tree.</p>

<p>The diameter of an N-ary tree is the length of the <strong>longest</strong> path between any two nodes in the tree. This path may or may not pass through the root.</p>

<p>(<em>Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.)</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/07/19/sample_2_1897.png" style="width: 324px; height: 173px;"></p>

<pre><strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
<strong>Output:</strong> 3
<strong>Explanation: </strong>Diameter is shown in red color.</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/07/19/sample_1_1897.png" style="width: 253px; height: 246px;"></strong></p>

<pre><strong>Input:</strong> root = [1,null,2,null,3,4,null,5,null,6]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/07/19/sample_3_1897.png" style="width: 369px; height: 326px;"></p>

<pre><strong>Input:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>Output:</strong> 7
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The depth of the n-ary tree is less than or equal to <code>1000</code>.</li>
	<li>The total number of nodes is between <code>[1, 10<sup>4</sup>]</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Diameter of Binary Tree (Easy)](https://leetcode.com/problems/diameter-of-binary-tree/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/diameter-of-n-ary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    int dfs(Node *root) {
        if (!root) return 0;
        int first = 0, second = 0;
        for (auto &c : root->children) {
            int d = dfs(c);
            if (d > first) {
                second = first;
                first = d;
            } else if (d > second) second = d;
        }
        ans = max(ans, first + second);
        return 1 + first;
    }
public:
    int diameter(Node* root) {
        dfs(root);
        return ans;
    }
};
```