#include <iostream>
#include "../+Serialization/BinaryTree.h"
#include <stack>

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    	vector<vector<int> > v;
    	if(!root) return v;
    	int n = 1;
    	bool l2r = true;
    	queue<TreeNode*> q;
    	q.push(root);
    	while(n){
    		vector<int> v1;
    		int nextN = 0;
    		stack<TreeNode*> s;
    		while(n--){
    			TreeNode *n = q.front(); q.pop();
    			v1.push_back(n->val);
    			if(l2r){
    				if(n->left){
    					nextN++;
    					s.push(n->left);
    				}
    				if(n->right){
    					nextN++;
    					s.push(n->right);
    				}
    			}else{
    				if(n->right){
    					nextN++;
    					s.push(n->right);
    				}
    				if(n->left){
    					nextN++;
    					s.push(n->left);
    				}
    			}
    		}
    		while(!s.empty()){
    			q.push(s.top()); s.pop();
    		}
    		l2r = !l2r;
    		n = nextN;
    		v.push_back(v1);
    	}
    	return v;
    }
};

int main(){
	string str = "3,9,20,#,#,15,7";
	TreeNode *root = deserialize(str);
	Solution s;
	vector<vector<int> > v = s.zigzagLevelOrder(root);
	vector<vector<int> >::iterator i = v.begin();
	for(; i != v.end(); ++i){
		vector<int>::iterator j = i->begin();
		for(; j != i->end(); ++j){
			cout << "[" << *j << "] ";
		}
		cout << endl;
	}
	return 0;
}