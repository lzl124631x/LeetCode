// OJ: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: github.com/lzl124631x
vector<string> stringToVector(string str) {
	str = str.substr(1, str.size() - 2);
	istringstream ss(str);
	string token;
	vector<string> ans;
	while (getline(ss, token, ',')) ans.push_back(token);
	return ans;
}

string vectorToString(vector<string> v){
	auto i = v.begin();
	ostringstream ans;
    ans << "[";
	for(; i != v.end(); ++i) {
		ans << *i;
		if (i + 1 != v.end()) ans << ",";
	}
	ans << "]";
	return ans.str();
}

class Codec {
private:
    string nilToken = "null";
public:
    TreeNode* deserialize(string str) {
        auto v = stringToVector(str);
        if (v.empty()) return NULL;
        queue<TreeNode*> q;
        auto root = new TreeNode(stoi(v[0]));
        q.push(root);
        for (int i = 1, N = v.size(); i < N;) {
            auto node = q.front();
            q.pop();
            if (v[i] != nilToken) q.push(node->left = new TreeNode(stoi(v[i])));
            ++i;
            if (i < N && v[i] != nilToken) q.push(node->right = new TreeNode(stoi(v[i])));
            ++i;
        }
        return root;
    }

    string serialize(TreeNode* root) {
        vector<string> v;
        if (!root) return vectorToString(v);
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            root = q.front();
            q.pop();
            if (root) {
                v.push_back(to_string(root->val));
                q.push(root->left);
                q.push(root->right);
            } else v.push_back(nilToken);
            
        }
        while (v.back() == nilToken) v.pop_back();
        return vectorToString(v);
    }
};