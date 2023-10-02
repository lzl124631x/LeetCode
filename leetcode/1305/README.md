# [1305. All Elements in Two Binary Search Trees (Medium)](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)

<p>Given two binary search trees <code>root1</code> and <code>root2</code>, return <em>a list containing all the integers from both trees sorted in <strong>ascending</strong> order</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/q2-e1.png" style="width: 457px; height: 207px;">
<pre><strong>Input:</strong> root1 = [2,1,4], root2 = [1,0,3]
<strong>Output:</strong> [0,1,1,2,3,4]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/q2-e5-.png" style="width: 352px; height: 197px;">
<pre><strong>Input:</strong> root1 = [1,null,8], root2 = [8,1]
<strong>Output:</strong> [1,1,8,8]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in each tree is in the range <code>[0, 5000]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Sorting](https://leetcode.com/tag/sorting/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(HA + HB)
class BstIterator {
    stack<TreeNode*> s;
    void pushNodes(TreeNode *node) {
        for (; node; node = node->left) s.push(node);
    }
public:
    BstIterator(TreeNode *root) {
        pushNodes(root);
    }
    int peek() {
        return hasNext() ? s.top()->val : INT_MIN;
    }
    bool hasNext() {
        return s.size();
    }
    void next() {
        if (!hasNext()) return;
        auto n = s.top();
        s.pop();
        pushNodes(n->right);
    }
};
class Solution {
public:
    vector<int> getAllElements(TreeNode* a, TreeNode* b) {
        BstIterator i(a), j(b);
        vector<int> ans;
        while (i.hasNext() || j.hasNext()) {
            if (!j.hasNext() || (i.hasNext() && i.peek() <= j.peek())) {
                ans.push_back(i.peek());
                i.next();
            } else {
                ans.push_back(j.peek());
                j.next();
            }
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(HA + HB)
class Solution {
    void pushNodes(stack<TreeNode*> &s, TreeNode *node) {
        for (; node; node = node->left) s.push(node);
    }
public:
    vector<int> getAllElements(TreeNode* a, TreeNode* b) {
        vector<int> ans;
        stack<TreeNode*> sa, sb;
        pushNodes(sa, a);
        pushNodes(sb, b);
        while (sa.size() || sb.size()) {
            auto &s = sb.empty() || (sa.size() && sa.top()->val <= sb.top()->val) ? sa : sb;
            ans.push_back(s.top()->val);
            auto n = s.top();
            s.pop();
            pushNodes(s, n->right);
        }
        return ans;
    }
};
```