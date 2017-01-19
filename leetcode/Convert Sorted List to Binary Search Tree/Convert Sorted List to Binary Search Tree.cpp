#include "../+Helper/SinglyLinkedList.h"
#include "../+Helper/BinaryTree.h"
#include <vector>
using namespace std;

class Solution {
public:
	ListNode* getListNodeByIndex(ListNode *head, int index){
		while(head && index-- > 0){
			head = head->next;
		}
		return head;
	}

	int listLength(ListNode *head){
		int len = 0;
		while(head){
			head = head->next; len++;
		}
		return len;
	}

	TreeNode *insertData(TreeNode *root, int data){
		TreeNode *node = new TreeNode(data);
		while(root){
			if(data > root->val){
				if(root->right){
					root = root->right;
				}else{
					root->right = node;
					root = NULL;
				}
			}else{
				if(root->left){
					root = root->left;
				}else{
					root->left = node;
					root = NULL;
				}
			}
		}
		return node;
	}

	TreeNode *recursiveInsert(TreeNode *root, ListNode *head, int len){
		if(!head || !len) return NULL;
		int mid = len / 2;
		ListNode *dataNode = getListNodeByIndex(head, mid);
		TreeNode *node = insertData(root, dataNode->val);
		recursiveInsert(node, head, mid);
		recursiveInsert(node, dataNode->next, len - mid - 1);
		return node;
	}

	TreeNode *sortedListToBST(ListNode *head) {
		return recursiveInsert(NULL, head, listLength(head));
	}
};