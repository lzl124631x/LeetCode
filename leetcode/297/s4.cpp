// OJ: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: github.com/lzl124631x
// Ref: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74259/Recursive-preorder-Python-and-C%2B%2B-O(n)
class Codec {
    void serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else out << "# ";
    }
    TreeNode *deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") return NULL;
        auto root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};