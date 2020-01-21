#ifndef binary_tree_h
#define binary_tree_h

#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string nilToken = "null";

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

#endif