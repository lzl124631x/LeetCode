// OJ: https://leetcode.com/problems/diagonal-traverse-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    typedef vector<int>::iterator iter;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& A) {
        vector<int> ans;
        int i = 0, N = A.size();
        list<pair<iter, iter>> q;
        while (i < N || q.size()) {
            if (i < N) {
                q.emplace_front(A[i].begin(), A[i].end());
                ++i;
            }
            int cnt = q.size();
            while (cnt--) {
                auto p = q.front();
                q.pop_front();
                ans.push_back(*p.first);
                p.first++;
                if (p.first != p.second) q.emplace_back(p.first, p.second);
            }
        }
        return ans;
    }
};