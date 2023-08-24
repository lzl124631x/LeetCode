# [590. N-ary Tree Postorder Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-postorder-traversal)

<p>Given the <code>root</code> of an n-ary tree, return <em>the postorder traversal of its nodes' values</em>.</p>
<p>Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;">
<pre><strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
<strong>Output:</strong> [5,6,3,2,4,1]
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 296px; height: 241px;">
<pre><strong>Input:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>Output:</strong> [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>The height of the n-ary tree is less than or equal to <code>1000</code>.</li>
</ul>
<p>&nbsp;</p>
<p><strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?</p>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Binary Tree Postorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-postorder-traversal/)
* [N-ary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)
* [N-ary Tree Preorder Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)

## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        function<void(Node*)> dfs = [&](Node *root) {
            if (!root) return;
            for (auto n : root->children) dfs(n);
            ans.push_back(root->val);
        };
        dfs(root);
        return ans;
    }
};
```

## Solution 2. Iterative

Preorder traverse the mirrored tree and reverse the result!

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> s{{root}};
        while (s.size()) {
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            for (auto n : root->children) s.push(n);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```

## Solution 3. Iterative

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-postorder-traversal
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<pair<Node*, int>> s{{{root, 0}}};
        while (s.size()) {
            auto [n, i] = s.top();
            s.pop();
            if (i == n->children.size()) ans.push_back(n->val);
            else {
                s.emplace(n, i + 1);
                s.emplace(n->children[i], 0);
            }
        }
        return ans;
    }
};
```