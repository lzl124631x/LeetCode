// OJ: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(begin(A), end(A));
        vector<int> sum = A;
        partial_sum(begin(sum), end(sum), begin(sum));
        int N = A.size(), L = 0, R = A.back(), minDiff = INT_MAX, ans = R;
        while (L <= R) {
            int M = (L + R) / 2;
            int i = lower_bound(begin(A), end(A), M) - begin(A);
            int total = (i - 1 >= 0 ? sum[i - 1] : 0) + (N - i) * M;
            int diff = abs(total - target);
            if (diff <= minDiff) {
                if (diff < minDiff) ans = M;
                else ans = min(ans, M);
                minDiff = diff;
            }
            if (total >= target) R = M - 1;
            else L = M + 1;
        }
        return ans;
    }
};