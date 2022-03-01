# [1490. Clone N-ary Tree (Medium)](https://leetcode.com/problems/clone-n-ary-tree/)

<p>Given a <code>root</code> of an N-ary tree, return a <a href="https://en.wikipedia.org/wiki/Object_copying#Deep_copy" target="_blank"><strong>deep copy</strong></a> (clone) of the tree.</p>

<p>Each node in the n-ary tree contains a val (<code>int</code>) and a list (<code>List[Node]</code>) of its children.</p>

<pre>class Node {
    public int val;
    public List&lt;Node&gt; children;
}
</pre>

<p><em>Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;"></p>

<pre><strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
<strong>Output:</strong> [1,null,3,2,4,null,5,6]
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 296px; height: 241px;"></p>

<pre><strong>Input:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>Output:</strong> [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The depth of the n-ary tree is less than or equal to <code>1000</code>.</li>
	<li>The total number of nodes is between <code>[0, 10<sup>4</sup>]</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up: </strong>Can your solution work for the <a href="https://leetcode.com/problems/clone-graph/" target="_blank">graph problem</a>?

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Clone Graph (Medium)](https://leetcode.com/problems/clone-graph/)
* [Copy List with Random Pointer (Medium)](https://leetcode.com/problems/copy-list-with-random-pointer/)
* [Clone Binary Tree With Random Pointer (Medium)](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/clone-n-ary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;
        auto cpy = new Node(root->val);
        for (auto &c : root->children) cpy->children.push_back(cloneTree(c));
        return cpy;
    }
};
```