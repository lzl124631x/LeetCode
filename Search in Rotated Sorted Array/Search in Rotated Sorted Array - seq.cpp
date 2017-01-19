class Solution {
public:
    int search(int A[], int n, int target) {
        if(n <= 0) return -1;
        int i;
        if(target >= A[0]){
            for(i = 0; i < n && A[i] >= A[0] && A[i] < target; i++);
        }else{
            for(i = n - 1; i >= 0 && A[i] <= A[n - 1] && A[i] > target; i--);
        }
        if(i >= 0 && i < n && A[i] == target) return i;
        return -1;
    }
};