#define SWAP_INT(a, b) do{int tmp = a; a = b; b = tmp;}while(0)
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	for(int i = 0; i < n; ){
    		if(A[i] == elem){
    			SWAP_INT(A[i], A[n - 1]);
    			n--;
    		}else{
    			i++;
    		}
    	}
    	return n;
    }
};