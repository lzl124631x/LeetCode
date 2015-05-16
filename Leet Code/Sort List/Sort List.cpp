#include <iostream>
#include <fstream>
using namespace std;

#define CASET int ___T, case_n = 1; cin >> ___T; while (___T-- > 0)
#define PRINTCASE cout << "Case #" << case_n++ << ": "

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	// Node[start] is chosen as sentinel, i.e. node[mid].
	// Nodes whose data are smaller than sentinel are append to start_prev.
	// Other nodes are kept in place.
	static void sort(ListNode *start_prev, ListNode *start, ListNode* end){
		if(start == end) return;
		ListNode *cur, *prev, *mid;
		mid = start;
		prev = mid;
		cur = prev->next;
		while(cur != end){
			if(cur->val < mid->val){
				prev->next = cur->next;
				cur->next = start_prev->next;
				start_prev->next = cur;
			}else{
				prev = cur;
			}
			cur = prev->next;
		}
		sort(start_prev, start_prev->next, mid);
		sort(mid, mid->next, end);
	}

    ListNode *sortList(ListNode *head) {
    	ListNode *fake_head = new ListNode(0);
    	fake_head->next = head;
    	sort(fake_head, head, NULL);
    	head = fake_head->next;
    	delete fake_head;
        return head;
    }
};

int main(){
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	if(!fin.is_open() || !fout.is_open()){
		cout << "Failed to open file\n" << endl;
		return 1;
	}
	cin.rdbuf(fin.rdbuf());
	cout.rdbuf(fout.rdbuf());
	CASET{
		ListNode *head = NULL, *tail = NULL;
		int N = 0;
		cin >> N;
		while(N--){
			int data;
			cin >> data;
			if(!head){
				head = tail = new ListNode(data);
			}else{
				tail->next = new ListNode(data);
				tail = tail->next;
			}
		}
		Solution s;
		head = s.sortList(head);
		tail = head;
		PRINTCASE; 
		while(tail){
			cout << tail->val << " ";
			tail = tail->next;
		}
		cout << endl;
	}
	fin.close();
	fout.close();
	return 0;
}

/*
 * 单链表要尽量用append, 要排序需要prepend, 因此需要设置一个start_prev节点用于append
 * 
 */