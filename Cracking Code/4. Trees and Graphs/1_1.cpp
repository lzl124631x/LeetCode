#include <iostream>
#include <algorithm>
using namespace std;
#define INT_MAX (((unsigned)~0) >> 1)
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode *root){
		if(!root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
	int minDepth(TreeNode *root){
		if(!root) return 0;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
	bool checkBalanced(TreeNode *root){
		if(!root) return true;
		return maxDepth(root) - minDepth(root) <= 1;
	}
};

int main(){
	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->left->left->left = new TreeNode(-1);
	root->right = new TreeNode(5);
	// root->right->left = new TreeNode(6);
	// root->right->right = new TreeNode(7);
	Solution s;
	cout << boolalpha << s.checkBalanced(root) << endl;
}