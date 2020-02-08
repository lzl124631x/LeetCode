// OJ: https://leetcode.com/problems/jump-game-v/
// Author: github.com/lzl124631x
// Time: O(ND)
// Space: O(N)
class Solution {
    int N, D;
    vector<int> v;
    int dfs(vector<int>& arr, int start) {
        if (v[start] > 0) return v[start];
        int left = 0, right = 0;
        for (int d = 1; d <= D && start - d >= 0 && arr[start - d] < arr[start]; ++d)
            left = max(left, dfs(arr, start - d));
        for (int d = 1; d <= D && start + d < N && arr[start + d] < arr[start]; ++d)
            right = max(right, dfs(arr, start + d));
        return v[start] = 1 + max(left, right);
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        N = arr.size(), D = d;
        v = vector<int>(N, 0);
        for (int i = 0; i < N; ++i) dfs(arr, i);
        int ans = 0;
        for (int i = 0; i < N; ++i) ans = max(ans, v[i]);
        return ans;
    }
};