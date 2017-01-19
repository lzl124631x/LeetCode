/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
  		if(!head) return NULL;
  		RandomListNode *new_head, *p, *q, *prev, *r, *s;      
  		p = head;
  		new_head = new RandomListNode(p->label);
  		prev = new_head;
  		p = p->next;
  		while(p){
  			q = new RandomListNode(p->label);
  			prev->next = q;
  			p = p->next;
  			prev = q;
  		}
  		p = head;
  		q = new_head;
  		while(p){
  			if(p->random){
  				r = head;
  				s = new_head;
  				while(r != p->random){
  					r = r->next;
  					s = s->next;
  				}
  				q->random = s;
  			}else{
  				q->random = NULL;
  			}
  			p = p->next;
  			q = q->next;
  		}
  		return new_head;
    }
};