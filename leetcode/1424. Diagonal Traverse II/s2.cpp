// OJ: https://leetcode.com/problems/diagonal-traverse-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& A) {
        unordered_map<int, vector<int>> m;
        int N = A.size(), maxKey = 0, cnt = 0;
        for (int i = N - 1; i >= 0; --i) {
            int M = A[i].size();
            cnt += M;
            for (int j = M - 1; j >= 0; --j) {
                m[i + j].push_back(A[i][j]);
                maxKey = max(maxKey, i + j);
            }
        }
        vector<int> ans;
        ans.reserve(cnt);
        for (int i = 0; i <= maxKey; ++i) {
            for (int n : m[i]) ans.push_back(n);
        }
        return ans;
    }
};