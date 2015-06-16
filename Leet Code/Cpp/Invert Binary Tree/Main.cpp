#include <iostream>
#include "../+Helper/helper.h"
using namespace std;

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return NULL;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	CLK_INIT;
	Solution s;
	CASET{
		string str;
		cin >> str;
		TreeNode *root = deserialize(str);
		PRINTCASE;
		CLK_START;
		cout << serialize(s.invertTree(root)) << endl;
		CLK_END;
	}

	return 0;
}