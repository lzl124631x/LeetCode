#include <stdio.h>
#include <malloc.h>

typedef struct ListNode{
	int data;
	struct ListNode *next;
} ListNode;

ListNode* listnode_create(int data){
	ListNode *p = malloc(sizeof *p);
	p->data = data;
	p->next = NULL;
	return p;
}

void list_destroy(ListNode *head){
	ListNode *next;
	if(!head) return;
	while(head){
		next = head->next;
		free(head);
		head = next;
	}
}

ListNode* listnode_append(ListNode *head, int data){
	if(!head) return;
	while(head->next){
		head = head->next;
	}
	return head->next = listnode_create(data);
}

void print_list(ListNode *head){
	while(head){
		printf("[%d] ", head->data);
		head = head->next;
	}
	printf("\n");
}

ListNode *find_loop_entrance(ListNode *head){
	ListNode *p, *q;
	if(!head) return NULL;
	p = q = head;
	do{
		p = p->next;
		q = q->next->next;
	}while(p != q);
	p = head;
	while(p != q){
		p = p->next;
		q = q->next;
	}
	return p;
}

int main(){
	size_t N, n;
	int data;
	ListNode *head, *tail, *p, *ent;
	while(1){
		head = NULL;
		scanf("%u %u", &N, &n);
		while(N--){
			scanf("%d", &data);
			if(!head){
				head = tail = listnode_create(data);
			}else{
				tail = listnode_append(head, data);
			}
		}
		p = head;
		while(n-- && p) p = p->next;
		tail->next = p;

		ent = find_loop_entrance(head);
		printf("Loop Entrance: [%d]\n", ent->data);
		tail->next = NULL;
		print_list(head);
		list_destroy(head);
	}
	return 0;
}


/*
 * 如何判断一个单链表是否有环? 设置指针 p 和 q 从 head 出发, p 每次走一步, q 每次走两步, p 和 q 汇合则说明有环.
 * 汇合点是否有规律?
 * 假设入环前有 x 个点, 当 p 到达入环点时, q 超过入环点 x%n 个点.
 * 假设 p 再走 k 步即可和q汇合, 那么在环上, p 一共走了 k 个点, q 一共走了 x%n + 2k 个点.
 * 第一次汇合则说明 (x%n + 2k) - k = n, 即 x%n = n - k, 其中 n 为环上点的个数.
 * 从上式还可以看出 0 <= n - k < n, 即 0 < k <= n.
 * 考虑 n - k 的含义, 它是 p 从汇合点走到入环点所需的步数.
 * 记 x = x%n + a*n, 其中 a 为 x 除以 n 的商.
 * 由 x%n = n - k 可得, x = (n - k) + a*n.
 * 等号左侧含义为, 令指针 q 从 head 出发一步一点走 x 步到达入环点.
 * 等号右侧含义为, 令指针 p 从汇合点出发一步一点走 n - k 步并多走 a 圈到达入环点.
 */