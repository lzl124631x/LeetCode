// OJ: https://leetcode.com/problems/image-overlap/
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(1)
class Solution {
private:
    int N;
    int overlap(vector<vector<int>>& A, vector<vector<int>>& B, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if ((i + x) < 0 || (i + x) >= N) continue;
            for (int j = 0; j < N; ++j) {
                if ((j + y) >= 0 && (j + y) < N
                    && A[i + x][j + y] && B[i][j]) ++cnt;
            }
        }
        return cnt;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        N = A.size();
        int ans = 0;
        for (int x = -N + 1; x < N; ++x) {
            for (int y = -N + 1; y < N; ++y) {
                ans = max(ans, overlap(A, B, x, y));
            }
        }
        return ans;
    }
};