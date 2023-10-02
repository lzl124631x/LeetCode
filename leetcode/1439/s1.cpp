// OJ: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
// Author: github.com/lzl124631x
typedef pair<int, string> Pair;
struct Cmp {
    bool operator()(const Pair &a, const Pair &b) {
        return a.first > b.first;
    }
};
class Solution {
    string hash(vector<int> &idx) {
        string s;
        for (int i = 0; i < idx.size(); ++i) {
            auto h = to_string(idx[i]);
            if (h.size() == 1) h = "0" + h;
            s += h;
        }
        return s;
    }
    vector<int> dehash(string s, int M) {
        vector<int> v(M);
        for (int i = 0; i < M; ++i) v[i] = (s[2 * i] - '0') * 10 + s[2 * i + 1] - '0';
        return v;
    }
public:
    int kthSmallest(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size(), sum = 0;
        unordered_set<string> seen;
        priority_queue<Pair, vector<Pair>, Cmp> q;
        vector<int> idx(M);
        auto idxHash = hash(idx);
        seen.insert(idxHash);
        for (int i = 0; i < M; ++i) sum += A[i][0];
        q.emplace(sum, idxHash);
        int x = 1;
        while (k--) {
            auto &p = q.top();
            sum = p.first;
            auto v = dehash(p.second, M);
            for (int i = 0; i < M; ++i) {
                if (v[i] + 1 >= N) continue;
                int nsum = sum + A[i][v[i] + 1] - A[i][v[i]];
                v[i]++;
                auto h = hash(v);
                if (!seen.count(h)) {
                    q.emplace(nsum, h);
                    seen.insert(h);
                }
                v[i]--;
            }
            q.pop();
        }
        return sum;
    }
};