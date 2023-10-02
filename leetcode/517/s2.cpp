// OJ: https://leetcode.com/problems/super-washing-machines/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/79938/very-short-easy-java-o-n-solution
class Solution {
public:
    int findMinMoves(vector<int>& m) {
        int sum = accumulate(m.begin(), m.end(), 0), N = m.size();
        if (sum % N) return -1;
        int target = sum / N, ans = 0, cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt += m[i] - target;
            ans = max(ans, max(abs(cnt), m[i] - target));
        }
        return ans;
    }
};