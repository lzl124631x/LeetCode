# [1586. Binary Search Tree Iterator II (Medium)](https://leetcode.com/problems/binary-search-tree-iterator-ii/)

<p>Implement the <code>BSTIterator</code> class that represents an iterator over the <strong><a href="https://en.wikipedia.org/wiki/Tree_traversal#In-order_(LNR)">in-order traversal</a></strong> of a binary search tree (BST):</p>

<ul>
	<li><code>BSTIterator(TreeNode root)</code> Initializes an object of the <code>BSTIterator</code> class. The <code>root</code> of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.</li>
	<li><code>boolean hasNext()</code> Returns <code>true</code> if there exists a number in the traversal to the right of the pointer, otherwise returns <code>false</code>.</li>
	<li><code>int next()</code> Moves the pointer to the right, then returns the number at the pointer.</li>
	<li><code>boolean hasPrev()</code> Returns <code>true</code> if there exists a number in the traversal to the left of the pointer, otherwise returns <code>false</code>.</li>
	<li><code>int prev()</code> Moves the pointer to the left, then returns the number at the pointer.</li>
</ul>

<p>Notice that by initializing the pointer to a non-existent smallest number, the first call to <code>next()</code> will return the smallest element in the BST.</p>

<p>You may assume that <code>next()</code> and <code>prev()</code> calls will always be valid. That is, there will be at least a next/previous number in the in-order traversal when <code>next()</code>/<code>prev()</code> is called.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/untitled-diagram-1.png" style="width: 201px; height: 201px;"></strong></p>

<pre><strong>Input</strong>
["BSTIterator", "next", "next", "prev", "next", "hasNext", "next", "next", "next", "hasNext", "hasPrev", "prev", "prev"]
[[[7, 3, 15, null, null, 9, 20]], [null], [null], [null], [null], [null], [null], [null], [null], [null], [null], [null], [null]]
<strong>Output</strong>
[null, 3, 7, 3, 7, true, 9, 15, 20, false, true, 15, 9]

<strong>Explanation</strong>
// The underlined element is where the pointer currently is.
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]); // state is <u> </u> [3, 7, 9, 15, 20]
bSTIterator.next(); // state becomes [<u>3</u>, 7, 9, 15, 20], return 3
bSTIterator.next(); // state becomes [3, <u>7</u>, 9, 15, 20], return 7
bSTIterator.prev(); // state becomes [<u>3</u>, 7, 9, 15, 20], return 3
bSTIterator.next(); // state becomes [3, <u>7</u>, 9, 15, 20], return 7
bSTIterator.hasNext(); // return true
bSTIterator.next(); // state becomes [3, 7, <u>9</u>, 15, 20], return 9
bSTIterator.next(); // state becomes [3, 7, 9, <u>15</u>, 20], return 15
bSTIterator.next(); // state becomes [3, 7, 9, 15, <u>20</u>], return 20
bSTIterator.hasNext(); // return false
bSTIterator.hasPrev(); // return true
bSTIterator.prev(); // state becomes [3, 7, 9, <u>15</u>, 20], return 15
bSTIterator.prev(); // state becomes [3, 7, <u>9</u>, 15, 20], return 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li>At most <code>10<sup>5</sup></code> calls will be made to <code>hasNext</code>, <code>next</code>, <code>hasPrev</code>, and <code>prev</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you solve the problem without precalculating the values of the tree?

**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Design](https://leetcode.com/tag/design/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/), [Iterator](https://leetcode.com/tag/iterator/)

**Similar Questions**:
* [Binary Search Tree Iterator (Medium)](https://leetcode.com/problems/binary-search-tree-iterator/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-search-tree-iterator-ii/
// Author: github.com/lzl124631x
// Time:
//      BSTIterator: O(H)
//      hasNext: O(1)
//      next: amortized O(1)
//      hasPrev: O(1)
//      prev: O(1)
// Space: O(N)
class BSTIterator {
    vector<int> seen;
    int i = -1;
    stack<TreeNode*> s;
    void pushNodes(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    bool hasNext() {
        return i < seen.size() - 1 || s.size();
    }
    int next() {
        ++i;
        if (i == seen.size()) {
            auto node = s.top();
            s.pop();
            seen.push_back(node->val);
            pushNodes(node->right);
            return node->val;
        }
        return seen[i];
    }
    bool hasPrev() {
        return i > 0;
    }
    int prev() {
        return seen[--i];
    }
};
```