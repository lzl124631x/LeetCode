#include "BinaryTree.h"

int main(){
	string s = "3,9,20,#,#,15,7";
	TreeNode *root = deserialize(s);
	printVector(breathFirstTraversal(root));
	cout << serialize(root) << endl;
	return 0;
}