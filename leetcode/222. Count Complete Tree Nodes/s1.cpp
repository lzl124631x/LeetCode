/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
 public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left = countLeft(root);
        int right = countRight(root);
        if (left == right) {
            return countNodes(left);
        } else {
            int nextRight = countRight(root->left);
            if (left - 1 == nextRight) {
                return countNodes(left - 1) + 1 + countNodes(root->right);
            } else {
                return countNodes(right -1) + 1 + countNodes(root->left);
            }
        }
    }
    
private:
    int countLeft(TreeNode *root) {
        int cnt = 0;
        while(root) {
            ++cnt;
            root = root->left;
        }
        return cnt;
    }
    
    int countRight(TreeNode *root) {
        int cnt = 0;
        while(root) {
            ++cnt;
            root = root->right;
        }
        return cnt;
    }
    
    int countNodes(int height) {
        return (1 << height) - 1;
    }
};