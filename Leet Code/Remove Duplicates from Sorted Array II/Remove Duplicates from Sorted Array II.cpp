class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int p, q;
        p = q = 0;
        while(q < n){
            A[p] = A[q++];
            if(q < n && A[q] == A[p]){
                A[++p] = A[q++];
                while(q < n && A[q] == A[p]) q++;
            }
            p++;
        }
        return p;
    }
};