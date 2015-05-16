#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	    if(!node) return NULL;
	    queue<UndirectedGraphNode*> q;
	    q.push(node);
	    map<UndirectedGraphNode*, UndirectedGraphNode*> m;
	    UndirectedGraphNode *n1 = NULL, *n2 = NULL;
	    while(!q.empty()){
	    	n1 = q.front(); q.pop();
	    	n2 = new UndirectedGraphNode(n1->label);
	    	m[n1] = n2;
	    	vector<UndirectedGraphNode*>::iterator iter;
	    	iter = n1->neighbors.begin();
	    	for(; iter != n1->neighbors.end(); ++iter){
	    		if(m.find(*iter) == m.end()){
	    			q.push(*iter);
	    		}
	    	}
	    }
	    map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator iter1;
	    for(iter1 = m.begin(); iter1 != m.end(); ++iter1){
	    	n1 = iter1->first;
	    	n2 = iter1->second;
	    	vector<UndirectedGraphNode*>::iterator iter2;
	    	iter2 = n1->neighbors.begin();
	    	for(; iter2 != n1->neighbors.end(); ++iter2){
	    		n2->neighbors.push_back(m[*iter2]);
	    	}
	    }
	    return m[node];
    }
};

int main(){
	UndirectedGraphNode n0(0), n1(1), n2(2);
	n0.neighbors.push_back(&n1);
	n0.neighbors.push_back(&n2);
	n1.neighbors.push_back(&n0);
	n1.neighbors.push_back(&n2);
	n2.neighbors.push_back(&n0);
	n2.neighbors.push_back(&n1);
	n2.neighbors.push_back(&n2);
	Solution s;
	UndirectedGraphNode *n = s.cloneGraph(&n0);
	return 0;
}