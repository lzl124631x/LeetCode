#include <iostream>
using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode*> in;
    vector<DirectedGraphNode*> out;
    DirectedGraphNode(int x) : label(x) {};
};


class Solution{
public:
	bool hasRootBetween(DirectedGraphNode* node, int i, int j){
		
		return true;
	}
};

int main(){

	return 0;
}