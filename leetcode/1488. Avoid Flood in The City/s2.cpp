// OJ: https://leetcode.com/problems/avoid-flood-in-the-city/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& A) {
        int N = A.size();
        vector<int> ans(N, -1);
        unordered_map<int, int> m;
        set<int> s;
        for (int i = 0; i < N; ++i) {
            if (A[i] > 0) {
                if (m.count(A[i])) {
                    auto it = s.upper_bound(m[A[i]]);
                    if (it == s.end()) return {};
                    ans[*it] = A[i];
                    s.erase(it);
                }
                m[A[i]] = i;
            } else {
                s.insert(i);
                ans[i] = 1;
            }
        }
        return ans;
    }
};