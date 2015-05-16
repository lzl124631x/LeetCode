#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
    	int pow_n = n, coef = 1 << (m - 2), result = 0;
    	for(int i = 1; i <= m - 2; ++i){
    		coef >>= 1;
    		result += pow_n * coef;
    		pow_n *= n;
    	}
    	result += pow_n;
    	return result >> (m - 2);
    }
};

int main(){
	Solution s;
	cout << s.uniquePaths(4, 4) << endl;
	return 0;
}