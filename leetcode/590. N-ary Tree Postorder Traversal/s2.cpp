// OJ: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        stack<Node*> s;
        s.push(root);
        vector<int> ans;
        while (s.size()) {
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            for (auto c : root->children) s.push(c);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};