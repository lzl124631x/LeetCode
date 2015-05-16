class Solution {
public:
    int singleNumber(int A[], int n) {
    	if(!A || n <= 0) return 0;
    	int x = 0;
    	while(n--){
    		x ^= A[n];
    	}
    	return x;
 	}
 };