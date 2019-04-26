// OJ: https://leetcode.com/problems/max-consecutive-ones-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, ans = 0, k = 0;
        while (true) {
            for (; j < A.size() && k <= K; ++j) {
                if (A[j] == 0) ++k;
            }
            ans = max(ans, j - i - (k > K ? 1 : 0));
            if (j >= A.size()) break;
            for (; k > K; ++i) {
                if (A[i] == 0) --k;
            }
        }
        return ans;
    }
};