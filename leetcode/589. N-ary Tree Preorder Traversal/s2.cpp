// OJ: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> s;
        s.push(root);
        while (s.size()) {
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            for (int i = root->children.size() - 1; i >= 0; --i) {
                if (root->children[i]) s.push(root->children[i]);
            }
        }
        return ans;
    }
};