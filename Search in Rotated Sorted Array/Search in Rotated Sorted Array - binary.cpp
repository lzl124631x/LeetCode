class Solution {
public:
    int binarySearch(int A[], int low, int high, int target){
        int mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(A[mid] == target) return mid;
            else if(target > A[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    int search(int A[], int n, int target) {
        if(n <= 0) return -1;
        int low = 0, high = n - 1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(A[mid] == target) return mid;
            if(A[mid] >= A[low] && A[mid] > A[high]){
                if(target <= A[mid] && target >= A[low]) high = mid - 1;
                else low = mid + 1;
            }else if(A[mid] <= A[low] && A[mid] < A[high]){
                if(target >= A[mid] && target <= A[high]) low = mid + 1;
                else high = mid - 1;
            }else{
                return binarySearch(A, low, high, target);
            }
        }
        return -1;
    }
};