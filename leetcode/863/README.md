# [863. All Nodes Distance K in Binary Tree (Medium)](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

<p>We are given a binary tree (with root node&nbsp;<code>root</code>), a <code>target</code> node, and an integer value <code>K</code>.</p>

<p>Return a list of the values of all&nbsp;nodes that have a distance <code>K</code> from the <code>target</code> node.&nbsp; The answer can be returned in any order.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>root = <span id="example-input-1-1">[3,5,1,6,2,0,8,null,null,7,4]</span>, target = <span id="example-input-1-2">5</span>, K = <span id="example-input-1-3">2</span>

<strong>Output: </strong><span id="example-output-1">[7,4,1]</span>

<strong>Explanation: </strong>
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png" style="width: 280px; height: 240px;">

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The given tree is non-empty.</li>
	<li>Each node in the tree has unique values&nbsp;<code>0 &lt;= node.val &lt;= 500</code>.</li>
	<li>The <code>target</code>&nbsp;node is a node in the tree.</li>
	<li><code>0 &lt;= K &lt;= 1000</code>.</li>
</ol>
</div>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. DFS + Level Order

Consider a simpler question: given `root`, find the nodes that have a distance `K` from the `root` node. We can simply use level order traversal to find the nodes at `K`th level.

For this question, we need to consider the `target`'s parents and the nodes in parents' substrees. We can use DFS to locate the `target` node, and if `target` node is found, return the distance to `target` node; otherwise return `INT_MAX` which means the current node is not `target`'s parent and should be ignored.

For the `target`'s parents, we use the level order traversal in the other subtree that doesn't contain `target`.

```cpp
// OJ: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    vector<int> ans;
    TreeNode *target;
    int K;
    int inorder(TreeNode *root) {
        if (!root) return INT_MAX;
        if (root == target) return 1;
        int left = inorder(root->left);
        if (left != INT_MAX) {
            if (left < K) levelOrder(root->right, K - left - 1);
            else if (left == K) ans.push_back(root->val);
            return left + 1;
        }
        int right = inorder(root->right);
        if (right != INT_MAX) {
            if (right < K) {
                levelOrder(root->left, K - right - 1);
            } else if (right == K) ans.push_back(root->val);
            return right + 1;
        }
        return INT_MAX;
    }
    void levelOrder(TreeNode *root, int K) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                TreeNode *node = q.front();
                q.pop();
                if (level == K) ans.push_back(node->val);
                else {
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            ++level;
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        this->target = target;
        this->K = K;
        levelOrder(target, K);
        inorder(root);
        return ans;
    }
};
```

## Solution 2. DFS + BFS

DFS to build the graph of the tree, then BFS to find the nodes at level `k`.

```cpp
// OJ: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> G;
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode *node, TreeNode *parent) {
            if (!node) return;
            if (parent) {
                G[parent->val].push_back(node->val);
                G[node->val].push_back(parent->val);
            }
            dfs(node->left, node);
            dfs(node->right, node);
        };
        dfs(root, nullptr);
        queue<int> q{{target->val}};
        while (q.size() && k--) {
            int cnt = q.size();
            while (cnt--) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) {
                    if (G.count(v)) q.push(v);
                }
                G.erase(u);
            }
        }
        vector<int> ans;
        while (q.size()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
```