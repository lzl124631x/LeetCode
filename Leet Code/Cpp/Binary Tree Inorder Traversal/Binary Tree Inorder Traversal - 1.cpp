#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 期望合并原版中的向左下降的代码, 但是发现按照下面这种方式:
// 1. 逻辑更复杂. while(root || !s.empty()) 不如原版中的简单条件直观.
// 2. 实际上向左下降代码并没有省略, 还是有两个部分, 只不过第一个部分不需要while.
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode*> s;
		vector<int> v;
		if(root){
			s.push(root);
			root = root->left;
			while(root || !s.empty()){
				while(root){
					s.push(root);
					root = root->left;
				}
				root = s.top(); s.pop();
				v.push_back(root->val);
				root = root->right;
			}
		}
		return v;
	}
};

int main(){
	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	Solution s;
	vector<int> data = s.inorderTraversal(root);
	vector<int>::iterator iter = data.begin();
	for(; iter != data.end(); iter++){
		cout << "[" << *iter << "] ";
	}
	cout << endl;
}