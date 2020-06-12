// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(N + KlogN)
// Space: O(N)
class Solution {
    int dist(vector<int> &p) {
        return p[0] * p[0] + p[1] * p[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int K) {
        auto cmp = [&](vector<int> &a, vector<int> &b) {
            return dist(a) > dist(b);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(begin(A), end(A), cmp);
        vector<vector<int>> ans;
        while (ans.size() < K) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};