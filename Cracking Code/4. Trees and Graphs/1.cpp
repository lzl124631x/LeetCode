#include <iostream>
#include <stack>
#include <utility>
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
	bool checkBalanced(TreeNode *root){
		if(!root) return true;
		stack<pair<TreeNode*, int> > s;
		int max_dep = 0, min_dep = INT_MAX;
		s.push(make_pair(root, 1));
		while(!s.empty()){
			pair<TreeNode*, int> p = s.top(); s.pop();
			root = p.first;
			if(!root->left && !root->right){
				if(p.second > max_dep) max_dep = p.second;
				if(p.second < min_dep) min_dep = p.second;
				if(max_dep - min_dep > 1) return false;
			}else{
				if(root->left) s.push(make_pair(root->left, p.second + 1));
				if(root->right) s.push(make_pair(root->right, p.second + 1));
			}
		}
		return true;
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