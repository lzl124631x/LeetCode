// OJ: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(logN)
class Solution {
private:
    vector<int> ans;
    int find(vector<int>& v, int begin, int end, int target) {
        int i = begin;
        while (i < end && v[i] != target) ++i;
        return i;
    }
    bool preorder(TreeNode *root, vector<int>& voyage, int begin, int end) {
        if (!root) return end == begin;
        if (end == begin || voyage[begin] != root->val) return false;
        if (!root->left && !root->right) return begin + 1 == end;
        int leftIndex = end, rightIndex = end;
        if (root->right) {
            rightIndex = find(voyage, begin + 1, end, root->right->val);
            if (rightIndex == end) return false;
        }
        if (root->left) {
            leftIndex = find(voyage, begin + 1, end, root->left->val);
            if (leftIndex == end) return false;
        }
        if (preorder(root->left, voyage, begin + 1, rightIndex)
                && preorder(root->right, voyage, rightIndex, end)) return true;
        if (preorder(root->left, voyage, leftIndex, end)
                && preorder(root->right, voyage, begin + 1, leftIndex)) {
            ans.push_back(root->val);
            return true;
        }
        return false;
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (preorder(root, voyage, 0, voyage.size())) return ans;
        return { -1 };
    }
};