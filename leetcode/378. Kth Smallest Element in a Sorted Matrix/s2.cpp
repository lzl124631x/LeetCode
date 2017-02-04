// https://discuss.leetcode.com/topic/52948/share-my-thoughts-and-clean-java-code
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size(), L = matrix[0][0], R = matrix[N - 1][N - 1];
        while (L < R) {
            int M = L + (R - L) / 2;
            int cnt = 0, j = N - 1;
            for (int i = 0; i < N; ++i) {
                while (j >= 0 && matrix[i][j] > M) --j;
                cnt += j + 1;
            }
            if (cnt < k) L = M + 1;
            else R = M;
        }
        return L;
    }
};