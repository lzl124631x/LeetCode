#include <vector>
using namespace std;

#define SWAP(a, b) do{int tmp = a; a = b; b = tmp;}while(0)
class Solution {
public:
	void permute(int layer, vector<vector<int> > &v, vector<int> &num){
		if(layer == num.size()){
			v.push_back(num);
			return;
		}
		for(int i = layer; i < num.size(); ++i){
			SWAP(num[layer], num[i]);
			permute(layer + 1, v, num);
			SWAP(num[layer], num[i]);
		}
	}

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > v;
        permute(0, v, num);
        return v;
    }
};