// OJ: https://leetcode.com/problems/gray-code/
// Author: github.com/lzl124631x
// Time: O(2^(N-1))
// Space: O(1)
class Solution {
public:
    vector<int> grayCode(int n) {
        int N = (1 << n);
        vector<int> ans(N, 0);
        for (int i = 0; true; ++i) {
            int j = (1 << i), d = (1 << (i + 1));
            if (j >= N) break;
            for (; j < N; j += 2 * d) {
                for (int k = j; k < N && k < j + d; ++k) ans[k] |= (1 << i);
            }
        }
        return ans;
    }
};