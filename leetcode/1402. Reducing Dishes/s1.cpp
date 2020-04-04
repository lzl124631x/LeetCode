// OJ: https://leetcode.com/problems/reducing-dishes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    typedef long long LL;
public:
    int maxSatisfaction(vector<int>& A) {
        int N = A.size();
        sort(A.begin(), A.end());
        LL ans = 0;
        for (int i = 0; i < N; ++i) {
            LL sum = 0;
            for (int j = i; j < N; ++j) sum += A[j] * (j - i + 1);
            ans = max(ans, sum);
        }
        return ans;
    }
};