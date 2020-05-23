// OJ: https://leetcode.com/problems/interval-list-intersections/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> ans;
        for (int i = 0, j = 0; i < M && j < N; ) {
            int s = max(A[i][0], B[j][0]), e = min(A[i][1], B[j][1]);
            if (s <= e) ans.push_back({ s, e });
            if (A[i][1] < B[j][1]) ++i;
            else ++j;
        }
        return ans;
    }
};