// Two stacks are used instead of function reverse.
// However, this method is slower and consume more space...
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > v;
        if(!root) return v;
        stack<int> s, sn;
        queue<TreeNode*> q;
        q.push(root);
        int n = 1;
        while(n){
            sn.push(n);
        	int nextN = 0;
        	while(n--){
        		root = q.front(); q.pop();
        		s.push(root->val);
                if(root->right){
                    nextN++;
                    q.push(root->right);
                }
        		if(root->left){
        			nextN++;
        			q.push(root->left);
        		}
        	}
        	n = nextN;
        }
        while(!sn.empty()){
            vector<int> v1;
            n = sn.top(); sn.pop();
            while(n--){
                v1.push_back(s.top()); s.pop();
            }
            v.push_back(v1);
        }
        return v;
    }
};