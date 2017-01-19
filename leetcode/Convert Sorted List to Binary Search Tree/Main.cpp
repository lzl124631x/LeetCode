#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "../+Helper/SinglyLinkedList.h"
#include "Convert Sorted List to Binary Search Tree.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		vector<int> v = scanVector();
		ListNode *head = vectorToList(v);
		PRINTCASE;
		CLK_START;
		cout << serialize(s.sortedListToBST(head)) << endl;
		CLK_END;
	}
	
	return 0;
}