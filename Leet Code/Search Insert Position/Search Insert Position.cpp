class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i = 0;
        while(i < n && A[i] < target) i++;
        return i;
    }
};