// OJ: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: github.com/lzl124631x
class Codec {
private:
    TreeNode *getNode(vector<string> &v, int &i) {
        string s = v[i++];
        return s == "#" ? NULL : new TreeNode(stoi(s));
    }
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans;
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (!ans.empty()) ans += ',';
            if (root) {
                ans += to_string(root->val);
                q.push(root->left);
                q.push(root->right);
            } else ans += '#';
        }
        return ans;
    }
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string val;
        vector<string> v;
        while (getline(ss, val, ',')) v.push_back(val);
        TreeNode *root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (i < v.size()) {
            TreeNode *node = q.front();
            q.pop();
            node->left = getNode(v, i);
            node->right = getNode(v, i);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};