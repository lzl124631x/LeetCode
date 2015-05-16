#include <stack>
#include <map>
using namespace std;
#include "../+Helper/BinaryTree.h"

class Solution {
public:
    // 后序遍历, 将深度记录在map中
    // 此算法还不如递归快, 也更浪费空间!
    // map需要占用额外空间(与树的总结点数成正比), 而且出入栈, map检索都要花费时间.
    // 递归之所以可取, 因为空间复杂度只与树的深度成正比.
    bool isBalanced(TreeNode *root) {
    	if(!root) return true;
    	stack<TreeNode*> s;
    	TreeNode *last = NULL;
    	map<TreeNode*, int> m;
    	m[NULL] = 0;
    	while(root || !s.empty()){
    		if(root){
                s.push(root);
    			root = root->left;
    		}else{
    			root = s.top();
    			if(!root->right || root->right == last){
    				s.pop();
    				int dl = m[root->left], dr = m[root->right];
    				if(dl - dr > 1 || dl - dr < -1) return false;
    				m[root] = 1 + max(dl, dr);
    				last = root;
    				root = NULL;
    			}else{
    				root = root->right;
    			}
    		}
    	}
    	return true;
    }
};