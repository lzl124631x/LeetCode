// OJ: https://leetcode.com/problems/avoid-flood-in-the-city/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& A) {
        int N = A.size();
        vector<int> ans(N, -1), next(N, -1);
        unordered_map<int, int> m;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 0) continue;
            if (m.count(A[i])) next[m[A[i]]] = i;
            m[A[i]] = i;
        }
        unordered_set<int> s;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < N; ++i) {
            if (A[i] > 0) {
                if (s.count(A[i])) return {};
                if (next[i] == -1) continue;
                pq.push(next[i]);
                s.insert(A[i]);
            } else {
                if (pq.empty()) ans[i] = 1;
                else {
                    int j = pq.top();
                    pq.pop();
                    ans[i] = A[j];
                    s.erase(A[j]);
                }
            }
        }
        return ans;
    }
};