// OJ: https://leetcode.com/problems/jump-game-iv/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    inline bool push(vector<int> &v, queue<int>& q, int i, int step) {
        if (v[i] == INT_MAX) {
            v[i] = step;
            q.push(i);
        }
        return !i;
    }
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> m;
        int N = arr.size(), step = 1;
        for (int i = 0; i < N; ++i) m[arr[i]].push_back(i);
        vector<int> v(N, INT_MAX);
        queue<int> q;
        q.push(N - 1);
        v[N - 1] = 0;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int i = q.front();
                q.pop();
                for (auto n : m[arr[i]]) {
                    if (push(v, q, n, step)) break;
                }
                if (i + 1 < N && push(v, q, i + 1, step)) break;
                if (i - 1 >= 0 && push(v, q, i - 1, step)) break;
            }
            ++step;
        }
        return v[0];
    }
};