// OJ: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    vector<int> ans;
    void rec(Node *root) {
        if (!root) return;
        ans.push_back(root->val);
        for (auto ch : root->children) rec(ch);
    }
public:
    vector<int> preorder(Node* root) {
        rec(root);
        return ans;
    }
};