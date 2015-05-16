class Solution {
public:
    int findLeftBound(int A[], int n, int target){
        int L = 0, R = n - 1;
        while(L <= R){
            int M = L + (R - L) / 2;
            if(target == A[M]){
                if(M == 0 || A[M - 1] != target) return M;
                else R = M - 1;
            }else if(target > A[M]){
                L = M + 1;
            }else{
                R = M - 1;
            }
        }
        return -1;
    }
    
    int findRightBound(int A[], int n, int target){
        int L = 0, R = n - 1;
        while(L <= R){
            int M = L + (R - L) / 2;
            if(target == A[M]){
                if(M == n - 1 || A[M + 1] != target) return M;
                else L = M + 1;
            }else if(target > A[M]){
                L = M + 1;
            }else{
                R = M - 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> v;
        v.push_back(findLeftBound(A, n, target));
        v.push_back(findRightBound(A, n, target));
        return v;
    }
};