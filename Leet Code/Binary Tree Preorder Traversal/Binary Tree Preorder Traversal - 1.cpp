#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 当前节点即为活节点.
	// 每次退栈访问当前节点, 将当前节点的左右子节点作为活节点推入栈中.
	// 以下代码的缺陷是
	vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode*> s;
		vector<int> v;
		if(root){
			s.push(root);
			while(!s.empty()){
				root = s.top(); s.pop();
				v.push_back(root->val);
				if(root->right) s.push(root->right);
				if(root->left) s.push(root->left);
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
	vector<int> data = s.preorderTraversal(root);
	vector<int>::iterator iter = data.begin();
	for(; iter != data.end(); iter++){
		cout << "[" << *iter << "] ";
	}
	cout << endl;
}