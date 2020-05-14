// OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N) on averge, O(N^2) in the worst case
// Space: O(1)
class Solution {
    int quickSelect(vector<int> &A, int L, int R) {
        int M = rand() % (R - L + 1) + L, p = A[M], i = L, j = R;
        swap(A[L], A[M]);
        while (i < j) {
            while (i < j && A[j] >= p) --j;
            while (i < j && A[i] <= p) ++i;
            if (i < j) swap(A[i], A[j]);
        }
        swap(A[L], A[i]);
        return i;
    }
public:
    int findKthLargest(vector<int>& A, int k) {
        int L = 0, R = A.size() - 1, M = -1;
        k = A.size() - k;
        srand(NULL);
        while (true) {
            M = quickSelect(A, L, R);
            if (M == k) return A[k];
            if (M > k) R = M - 1;
            else L = M + 1;
        }
    }
};