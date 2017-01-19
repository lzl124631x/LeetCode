class Solution {
public:
    bool binarySearch(int A[], int low, int high, int target){
        int mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(A[mid] == target) return true;
            else if(target > A[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    bool search(int A[], int n, int target) {
        if(n <= 0) return -1;
        int low = 0, high = n - 1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(A[mid] == target) return true;
            if()
        }
        return false;
    }
};