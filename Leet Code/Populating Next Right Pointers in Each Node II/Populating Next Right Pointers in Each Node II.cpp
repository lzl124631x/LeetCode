#include <queue>
using namespace std;
#include "../+Helper/TreeLinkNode.cpp"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        int n = 1;
        while(n){
        	TreeLinkNode *prev = NULL, *p = NULL;
        	int nextN = 0;
        	while(n--){
        		prev = p;
        		p = q.front(); q.pop();
        		if(prev) prev->next = p;
        		if(!n) p->next = NULL;
        		if(p->left){
        			q.push(p->left); nextN++;
        		}
        		if(p->right){
        			q.push(p->right); nextN++;
        		}
        	}
        	n = nextN;
        }
    }
};