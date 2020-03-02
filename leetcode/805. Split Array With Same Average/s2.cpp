// OJ: https://leetcode.com/problems/split-array-with-same-average/
// Author: github.com/lzl124631x
// Time: O(n^3 * M) where M the maximum possible number in `A`
// Space: O(n^2 * M)
// Ref: https://leetcode.com/problems/split-array-with-same-average/discuss/120667/C%2B%2B-Solution-with-explanation-early-termination-(Updated-for-new-test-case)
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int N = A.size(), sum = accumulate(A.begin(), A.end(), 0), M = N / 2;
        bool possible = false;
        for (int i = 1; i <= N && !possible; ++i) possible = sum * i % N == 0;
        if (!possible) return false;
        vector<unordered_set<int>> v(M + 1);
        v[0] = {0};
        for (int i = 0; i < N; ++i) {
            for (int j = min(M, i + 1); j >= 1; --j) {
                for (int n : v[j - 1]) {
                    int m = n + A[i];
                    if (m * N == sum * j) return true;
                    v[j].insert(m);
                }
            }
        }
        return false;
    }
};