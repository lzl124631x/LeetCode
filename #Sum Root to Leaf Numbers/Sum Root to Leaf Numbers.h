#include "../+Helper/BinaryTree.h"
class Solution {
	void preorder(TreeNode *root, int &sum, int &num){
		if(!root) return;
		num *= 10;
		num += root->val;
		if(!root->left && !root->right) sum += num;
		preorder(root->left, sum, num);
		preorder(root->right, sum, num);
		num /= 10;
	}
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0, num = 0;
        preorder(root, sum, num);
        return sum;
    }
};