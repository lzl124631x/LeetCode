// OJ: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    vector<int> ans;
    void rec(Node *root) {
        if (!root) return;
        for (auto ch : root->children) rec(ch);
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        rec(root);
        return ans;
    }
};