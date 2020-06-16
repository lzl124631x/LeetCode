// OJ: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    bool valid(vector<int> &A, int n, int m, int k) {
        int N = A.size(), cnt = 0, j = 0;
        while (j < N) {
            int i = j;
            while (j < N && j - i < k && A[j] <= n) ++j; 
            if (j - i == k) ++cnt;
            if (cnt >= m) return true;
            while (j < N && A[j] > n) ++j;
        }
        return false;
    }
public:
    int minDays(vector<int>& A, int m, int k) {
        if (A.size() < m * k) return -1;
        set<int> s(begin(A), end(A));
        vector<int> u(begin(s), end(s));
        int L = 0, R = u.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(A, u[M], m, k)) R = M - 1;
            else L = M + 1;
        }
        return u[L];
    }
};