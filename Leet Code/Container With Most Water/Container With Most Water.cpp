#include <vector>
using namespace std;

#define VOLUME(h, i, j) (((j) - (i)) * min((h)[i], (h)[j]))
class Solution {
public:
    int maxArea(vector<int> &height) {
    	int len = height.size();
    	int maxVal = VOLUME(height, 0, len - 1);
    	cout << maxVal << endl;
    	for(int i = 0; i < len; ++i){
    		if(!height[i]) continue;
    		int d = maxVal / height[i] + 1;
    		for(int j = i + d; j < len; ++j){
    			if(height[j] >= height[i]){
    				maxVal = VOLUME(height, i, j);
    			}
    		}
    	}
    	return maxVal;      
    }
};