// OJ: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// Author: github.com/lzl124631x
// Note: TLE on input [35,73,90,27,71,80,21,33,33,13,48,12,68,70,80,36,66,3,70,58]
class Solution {
private:
    string key(vector<int>& A) {
        string ans;
        for (auto n : A) {
            ans += to_string(n) + "#";
        }
        return ans;
    }
    unordered_map<string, int> m;
public:
    int minScoreTriangulation(vector<int>& A) {
        if (A.size() == 3) return A[0] * A[1] * A[2];
        auto k = key(A);
        if (m.find(k) != m.end()) return m[k];
        int ans = INT_MAX;
        for (int i = 0, N = A.size(); i < N; ++i) {
            int prev = (i - 1 + N) % N, next = (i + 1) % N;
            int prod = A[i] * A[prev] * A[next];
            vector<int> B = A;
            B.erase(B.begin() + i);
            int val = prod + minScoreTriangulation(B);
            ans = min(ans, val);
        }
        return m[k] = ans;
    }
};