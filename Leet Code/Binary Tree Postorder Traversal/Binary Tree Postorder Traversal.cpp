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

class Solution {
public:
	// 思路:
	// 活节点: 左子树和右子树都已被访问的节点.
	// 创造待选活节点: 栈中先存放右节点, 再存放当前节点, 左移.
	// 每次退栈顶记为p:
	// 1. 若栈顶为p->right, 则p还不能访问. 退栈顶记为root, 压p入栈, 利用root创造伪活节点.
	// 2. 若栈顶不是p->right, 则访问p.
	vector<int> postorderTraversal(TreeNode *root) {
		stack<TreeNode*> s;
		vector<int> v;
		while(root){
			s.push(root->right);
			s.push(root);
			root = root->left;
		}
		while(!s.empty()){
			TreeNode *p = s.top(); s.pop();
			if(!s.empty() && p->right == s.top()){
				root = s.top(); s.pop();
				s.push(p);
				while(root){
					s.push(root->right);
					s.push(root);
					root = root->left;
				}
			}else{
				v.push_back(p->val);
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
	vector<int> data = s.postorderTraversal(root);
	vector<int>::iterator iter = data.begin();
	for(; iter != data.end(); iter++){
		cout << "[" << *iter << "] ";
	}
	cout << endl;
}