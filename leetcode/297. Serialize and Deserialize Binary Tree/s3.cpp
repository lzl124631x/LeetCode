// OJ: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: github.com/lzl124631x
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        vector<TreeNode*> v;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            root = q.front();
            q.pop();
            v.push_back(root);
            if (root) {
                q.push(root->left);
                q.push(root->right);
            }
        }
        while (v.back() == NULL) v.pop_back();
        string ans = "[";
        for (int i = 0; i < v.size(); ++i) {
            ans += v[i] ? to_string(v[i]->val) : "null";
            ans += i == v.size() - 1 ? "]" : ",";
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        vector<TreeNode*> v;
        int i = 1, N = data.size() - 1;
        while (i < N) {
            TreeNode *node = NULL;
            if (data[i] == 'n') i += 4;
            else {
                long n = 0, sign = 1;
                if (data[i] == '-') {
                    sign = -1;
                    ++i;
                }
                while (i < N && isdigit(data[i])) n = n * 10 + (data[i++] - '0');
                node = new TreeNode(sign * n);
            }
            ++i;
            v.push_back(node);
        }
        TreeNode *root;
        queue<TreeNode**> q;
        q.push(&root);
        for (auto node : v) {
            auto p = q.front();
            q.pop();
            *p = node;
            if (node) {
                q.push(&node->left);
                q.push(&node->right);
            }
        }
        return root;
    }
};