class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int cnt = 0;
        int start = 0;
        while (start + 2 < n) {
            int end = start + 1, d = A[end] - A[start];
            while (end + 1 < n && A[end + 1] - A[end] == d) ++end;
            int len = end - start + 1;
            cnt += (len - 1) * (len - 2) / 2;
            start = end;
        }
        return cnt;
    }
};