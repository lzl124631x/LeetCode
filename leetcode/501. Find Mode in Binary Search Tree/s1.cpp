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
private:
    unordered_map<int, int> m;
    void count(TreeNode *root) {
        if (!root) return;
        m[root->val]++;
        count(root->left);
        count(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        count(root);
        int maxCnt = 0;
        for (auto p : m) {
            maxCnt = max(maxCnt, p.second);
        }
        vector<int> ans;
        for (auto p : m) {
            if (p.second == maxCnt) ans.push_back(p.first);
        }
        return ans;
    }
};