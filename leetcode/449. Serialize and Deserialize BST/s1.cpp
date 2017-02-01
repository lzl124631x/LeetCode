/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void preorder(TreeNode *root, string &ans) {
        if (!root) return;
        if (!ans.empty()) ans += ',';
        ans += to_string(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    
    TreeNode *deserialize(vector<TreeNode*> &data, int start, int end) {
        if (start == end) return NULL;
        TreeNode *root = data[start];
        int i = start + 1;
        while (i < end && data[i]->val < root->val) ++i;
        root->left = deserialize(data, start + 1, i);
        root->right = deserialize(data, i, end);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        preorder(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        vector<TreeNode*> nodes;
        while (getline(ss, val, ',')) nodes.push_back(new TreeNode(stoi(val)));
        return deserialize(nodes, 0, nodes.size());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));