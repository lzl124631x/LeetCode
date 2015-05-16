#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// set中不应该存储"已经被访问的节点", 因为这可能导致队列中出现重复的待访问节点.
// set中应该存储"已经插入过队列的节点", 也就是紧随q.push(n)操作.
vector<int> breathFirstTraversal(UndirectedGraphNode *n){
	if(!n) return vector<int>();
	vector<int> v;
	set<int> s;
	queue<UndirectedGraphNode*> q;
	q.push(n);
	s.insert(n->label);
	while(!q.empty()){
		n = q.front(); q.pop();
		v.push_back(n->label);
		vector<UndirectedGraphNode*>::iterator i;
		i = n->neighbors.begin();
		for(; i != n->neighbors.end(); ++i){
			if(s.find((*i)->label) == s.end()){
				q.push(*i);
				s.insert((*i)->label);
			}
		}
	}
	return v;
}

void printVector(vector<int> v){
	vector<int>:: iterator i = v.begin();
	for(; i != v.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;
}

// Note: Invalid input is not considered yet.
UndirectedGraphNode* deserialize(string str){
	char *s = (char*)str.c_str(), *p = NULL;
	map<int, UndirectedGraphNode*> m;
	UndirectedGraphNode *ret = NULL;
	while(p = strsep(&s, "#")){
		char *q = NULL;
		UndirectedGraphNode *n = NULL;
		vector<UndirectedGraphNode*> v;
		while(q = strsep(&p, ",")){
			int label = atoi(q);
			if(m.find(label) != m.end()){
				n = m[label];
			}else{
				n = new UndirectedGraphNode(label);
				m[label] = n;
			}
			v.push_back(n);
		}
		n = v.front();
		v.erase(v.begin());
		n->neighbors = v;
		if(!ret){
			ret = n;
		}
	}
	return ret;
}

string serialize(UndirectedGraphNode* n){
	if(!n) return "";
	char buf[1000] = {0}, *p = buf;
	set<int> s;
	queue<UndirectedGraphNode*> q;
	q.push(n);
	s.insert(n->label);
	while(!q.empty()){
		n = q.front(); q.pop();
		p += sprintf(p, "%d,", n->label);
		vector<UndirectedGraphNode*>::iterator i;
		i = n->neighbors.begin();
		for(; i != n->neighbors.end(); ++i){
			int label = (*i)->label;
			p += sprintf(p, "%d,", label);
			if(s.find(label) == s.end()){
				q.push(*i);
				s.insert(label);
			}
		}
		*(p - 1) = '#';
	}
	*(p - 1) = '\0';
	return string(buf);
}

int main(){
	string s = "0,1,2#1,2#2,2";
	UndirectedGraphNode *n = deserialize(s);
	printVector(breathFirstTraversal(n));
	cout << serialize(n) << endl;
	return 0;
}