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
	// 堆栈中保存活节点. 活节点是左子树已经被访问的节点.
	// 创造活节点: 当前节点入栈, 左移.
	// 每次从栈中获取一个活节点, 访问, 右移, 创造活节点.
	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode*> s;
		vector<int> v;
		while(root){
			s.push(root);
			root = root->left;
		}
		while(!s.empty()){
			root = s.top(); s.pop();
			v.push_back(root->val);
			root = root->right;
			while(root){
				s.push(root);
				root = root->left;
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