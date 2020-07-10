# [662. Maximum Width of Binary Tree (Medium)](https://leetcode.com/problems/maximum-width-of-binary-tree/)

<p>Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a <b>full binary tree</b>, but some nodes are null. </p>

<p>The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the <code>null</code> nodes between the end-nodes are also counted into the length calculation.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

<b>Output:</b> 4
<b>Explanation:</b> The maximum width existing in the third level with the length 4 (5,3,null,9).
</pre>


<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 

          1
         /  
        3    
       / \       
      5   3     

<b>Output:</b> 2
<b>Explanation:</b> The maximum width existing in the third level with the length 2 (5,3).
</pre>


<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> 

          1
         / \
        3   2 
       /        
      5      

<b>Output:</b> 2
<b>Explanation:</b> The maximum width existing in the second level with the length 2 (3,2).
</pre>

<p><b>Example 4:</b><br>
</p><pre><b>Input:</b> 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
<b>Output:</b> 8
<b>Explanation:</b>The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


</pre>

<p><b>Note:</b>
Answer will in the range of 32-bit signed integer.
</p>

**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1. Pre-order Traversal

```cpp
// OJ: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    typedef unsigned long long ULL;
    vector<vector<ULL>> v;
    ULL ans = 0;
    void dfs(TreeNode *node, int lv, ULL nodeId) {
        if (!node) return;
        if (v.size() <= lv) v.push_back({ULLONG_MAX, 0});
        v[lv][0] = min(v[lv][0], nodeId);
        v[lv][1] = max(v[lv][1], nodeId);
        ans = max(ans, v[lv][1] - v[lv][0] + 1);
        dfs(node->left, lv + 1, 2 * nodeId);
        dfs(node->right, lv + 1, 2 * nodeId + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0, 0);
        return ans;
    }
};
```

## Solution 1. Level-order Traversal

```cpp
// OJ: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    typedef unsigned long long ULL;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, ULL>> q;
        q.emplace(root, 0);
        ULL ans = 0;
        while (q.size()) {
            ULL cnt = q.size(), minId, maxId; 
            for (int i = 0; i < cnt; ++i) {
                auto p = q.front();
                q.pop();
                auto node = p.first;
                ULL nodeId = p.second;
                if (node->left) q.emplace(node->left, nodeId * 2);
                if (node->right) q.emplace(node->right, nodeId * 2 + 1);
                if (i == 0) minId = nodeId;
                if (i == cnt - 1) maxId = nodeId;
            }
            ans = max(ans, maxId - minId + 1);
        }
        return ans;
    }
};
```

## Solution 3. Level-order Traversal

When there is only one node in this level, reset the `id` to be `0`.

```cpp
// OJ: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        int ans = 0;
        while (q.size()) {
            int cnt = q.size();
            if (cnt == 1) {
                q.emplace(q.front().first, 0);
                q.pop();
            }
            ans = max(ans, q.back().second - q.front().second + 1);
            while (cnt--) {
                root = q.front().first;
                int id = q.front().second;
                q.pop();
                if (root->left) q.emplace(root->left, 2 * id);
                if (root->right) q.emplace(root->right, 2 * id + 1);
            }
        }
        return ans;
    }
};
```