// OJ: https://leetcode.com/problems/falling-squares/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
class Solution {
    vector<int> tree;
    int N = 0;
    void updateAt(int i, int val) {
        i += N;
        tree[i] = val;
        while (i > 0) {
            i /= 2;
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void update(int begin, int end, int val) {
        for (int i = begin; i < end; ++i) updateAt(i, val);
    }
    int maxRange(int i, int j) {
        i += N;
        j += N;
        int ans = 0;
        while (i <= j) {
            if (i % 2) ans = max(ans, tree[i++]);
            if (j % 2 == 0) ans = max(ans, tree[j--]);
            i /= 2;
            j /= 2;
        }
        return ans;
    }
public:
    vector<int> fallingSquares(vector<vector<int>>& P) {
        set<int> ps;
        for (auto &p : P) {
            ps.insert(p[0]);
            ps.insert(p[0] + p[1] - 1);
        }
        unordered_map<int, int> m;
        for (int n : ps) m[n] = N++;
        tree.resize(2 * N);
        vector<int> ans;
        int top = 0;
        for (auto &p : P) {
            int a = m[p[0]], b = m[p[0] + p[1] - 1];
            int tmp = p[1] + maxRange(a, b);
            update(a, b + 1, tmp);
            top = max(top, tmp);
            ans.push_back(top);
        }
        return ans;
    }
};