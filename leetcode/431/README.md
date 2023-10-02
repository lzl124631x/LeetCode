# [431. Encode N-ary Tree to Binary Tree (Hard)](https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/)

<p>Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. Similarly, a binary tree is a rooted tree in which each node has no more than 2 children. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded to the original N-nary tree structure.</p>

<p><em>Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See following example).</em></p>

<p>For example, you may encode the following <code>3-ary</code> tree to a binary tree in this way:</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreebinarytreeexample.png" style="width: 100%; max-width: 640px"></p>

<pre><strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
</pre>

<p>Note that the above is just an example which <em>might or might not</em> work. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
<strong>Output:</strong> [1,null,3,2,4,null,5,6]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>Output:</strong> [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>The height of the n-ary tree is less than or equal to <code>1000</code></li>
	<li>Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.</li>
</ul>


**Companies**:  
[Flipkart](https://leetcode.com/company/flipkart)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Design](https://leetcode.com/tag/design/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Serialize and Deserialize N-ary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/)

## Solution 1. DFS

Use `node->right` to store its siblings and `node->left` to store its first child.

```cpp
// OJ: https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N) for all
// Space: O(H)
class Codec {
public:
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;
        TreeNode *n = new TreeNode(root->val), *prev = nullptr;
        for (auto &c : root->children) {
            auto cn = encode(c);
            if (!prev) n->left = cn;
            else prev->right = cn;
            prev = cn;
        }
        return n;
    }
    Node* decode(TreeNode* root) {
        if (!root) return nullptr;
        Node *n = new Node(root->val);
        root = root->left;
        while (root) {
            auto cn = decode(root);
            n->children.push_back(cn);
            root = root->right;
        }
        return n;
    }
};
```