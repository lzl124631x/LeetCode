// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(K)
class Solution {
    int dist(const vector<int> &p) {
        return p[0] * p[0] + p[1] * p[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int K) {
        auto cmp = [&](const vector<int> &a, const vector<int> &b) {
            return dist(a) < dist(b);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (auto & p : A) {
            if (q.size() == K) {
                if (dist(p) >= dist(q.top())) continue;
                q.pop();
            }
            q.push(p);
        }
        vector<vector<int>> ans;
        while (q.size()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};