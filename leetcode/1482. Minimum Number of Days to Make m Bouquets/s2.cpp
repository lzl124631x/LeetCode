// OJ: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Author: github.com/lzl124631x
// Time: O(Nlog(max(A)))
// Space: O(1)
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/686316/JavaC%2B%2BPython-Binary-Search
class Solution {
public:
    int minDays(vector<int>& A, int m, int k) {
        int N = A.size(), L = 1, R = 1e9;
        if (N < m * k) return -1;
        while (L <= R) {
            int M = (L + R) / 2, cnt = 0, cur = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] > M) cur = 0;
                else if (++cur >= k) {
                    ++cnt;
                    cur = 0;
                }
            }
            if (cnt < m) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};