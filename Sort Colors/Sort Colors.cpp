class Solution {
public:
    void sortColors(int A[], int n) {
        int P0 = 0, P1 = 0, P2 = 0;
        for(int i = 0; i < n; ++i){
        	switch(A[i]){
        		case 0:
        			A[P2++] = 2;
        			A[P1++] = 1;
        			A[P0++] = 0;
        			break;
        		case 1:
        			A[P2++] = 2;
        			A[P1++] = 1;
        			break;
        		case 2:
        			A[P2++] = 2;
        			break;
        		default: break;
        	}
        }
    }
};