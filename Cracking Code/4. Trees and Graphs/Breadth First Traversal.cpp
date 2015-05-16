#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> breadthFirstTraversal(TreeNode *root) {
		queue<TreeNode*> q;
		vector<int> v;
		if(root){
			q.push(root);
			while(!q.empty()){
				root = q.front(); q.pop();
				v.push_back(root->val);
				if(root->left) q.push(root->left);
				if(root->right) q.push(root->right);
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
	vector<int> data = s.breadthFirstTraversal(root);
	vector<int>::iterator iter = data.begin();
	for(; iter != data.end(); iter++){
		cout << "[" << *iter << "] ";
	}
	cout << endl;
}