#include <vector>
#include <queue>
using namespace std;
#include "../+Helper/BinaryTree.h"
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        int n = 1;
        while(n){
        	int nextN = 0;
        	vector<int> v1;
        	while(n--){
        		root = q.front(); q.pop();
        		v1.push_back(root->val);
        		if(root->left){
        			nextN++;
        			q.push(root->left);
        		}
        		if(root->right){
        			nextN++;
        			q.push(root->right);
        		}
        	}
        	v.push_back(v1);
        	n = nextN;
        }
        return v;
    }
};