// OJ: https://leetcode.com/problems/complete-binary-tree-inserter/
// Author: github.com/lzl124631x
// Time:
//     CBTInserter: O(N)
//     insert: O(1)
//     get_root: O(1)
// Space: O(N)
class CBTInserter {
private:
    TreeNode *root;
    queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* root): root(root) {
        if (!root) return;
        queue<TreeNode*> tmp;
        tmp.push(root);
        while (tmp.size()) {
            root = tmp.front();
            tmp.pop();
            if (!root->left || !root->right) q.push(root);
            if (root->left) tmp.push(root->left);
            if (root->right) tmp.push(root->right);
        }
    }
    
    int insert(int v) {
        TreeNode *node = new TreeNode(v);
        TreeNode *parent = q.front();
        if (!parent->left) parent->left = node;
        else {
            parent->right = node;
            q.pop();
        }
        q.push(node);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};