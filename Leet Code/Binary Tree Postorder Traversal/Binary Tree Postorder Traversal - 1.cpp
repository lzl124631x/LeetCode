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
	vector<int> postorderTraversal(TreeNode *root) {
		stack<TreeNode*> s;
		vector<int> v;
		TreeNode *node = NULL;
		while(root || !s.empty()){
			if(root){					// 若root(当前节点)存在, 入栈, 左移.
				s.push(root);
				root = root->left;
			}else{						// 若root不存在, 取栈顶
				root = s.top();
				if(!root->right || root->right == node){	// 若root->right不存在或刚被访问过
					v.push_back(root->val);					// 访问当前节点
					s.pop();
					node = root;							// 将当前节点记录为node, 即刚访问过的节点
					root = NULL;							// node置为null以便继续取栈顶
				}else{
					root = root->right;						// 若root->right存在, 右移, 准备创造活节点.
				}
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