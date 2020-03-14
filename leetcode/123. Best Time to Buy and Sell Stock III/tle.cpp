// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    unordered_map<int, unordered_map<int, int>> p, m;
    int N;
    int dfs(int start, int k, vector<int> &A) {
        if (start >= N || !k) return 0;
        if (m[start].count(k)) return m[start][k];
        int ans = 0;
        for (int i = start; i < N; ++i) {
            ans = max(ans, p[start][i] + dfs(i + 1, k - 1, A));
        }
        return m[start][k] = ans;
    }
public:
    int maxProfit(vector<int>& A) {
        N = A.size();
        int k = 2;
        for (int i = 0; i < N; ++i) {
            int buy = -A[i],  sell = 0;
            for (int j = i; j < N; ++j) {
                buy = max(buy, -A[j]);
                sell = max(sell, A[j] + buy);
                p[i][j] = sell;
            }
        }
        return dfs(0, k, A);
    }
};