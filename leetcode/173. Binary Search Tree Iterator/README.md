# [173. Binary Search Tree Iterator (Medium)](https://leetcode.com/problems/binary-search-tree-iterator/)

<p>Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.</p>

<p>Calling <code>next()</code> will return the next smallest number in the BST.</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>Example:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2018/12/25/bst-tree.png" style="width: 189px; height: 178px;"></strong></p>

<pre>BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ul>
	<li><code>next()</code> and <code>hasNext()</code> should run in average O(1) time and uses O(<i>h</i>) memory, where <i>h</i> is the height of the tree.</li>
	<li>You may assume that&nbsp;<code>next()</code>&nbsp;call&nbsp;will always be valid, that is, there will be at least a next smallest number in the BST when <code>next()</code> is called.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Oracle](https://leetcode.com/company/oracle), [Bloomberg](https://leetcode.com/company/bloomberg), [Qualtrics](https://leetcode.com/company/qualtrics), [Cloudera](https://leetcode.com/company/cloudera), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [LinkedIn](https://leetcode.com/company/linkedin), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [Flatten 2D Vector (Medium)](https://leetcode.com/problems/flatten-2d-vector/)
* [Zigzag Iterator (Medium)](https://leetcode.com/problems/zigzag-iterator/)
* [Peeking Iterator (Medium)](https://leetcode.com/problems/peeking-iterator/)
* [Inorder Successor in BST (Medium)](https://leetcode.com/problems/inorder-successor-in-bst/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-search-tree-iterator/
// Author: github.com/lzl124631x
// Time: O(1) amortized
// Space: O(logN)
class BSTIterator {
private:
    stack<TreeNode*> s;
    void pushNodes(TreeNode *node) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    int next() {
        auto node = s.top();
        s.pop();
        if (node->right) pushNodes(node->right);
        return node->val;
    }
    bool hasNext() {
        return s.size();
    }
};
```