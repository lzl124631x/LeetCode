// OJ: https://leetcode.com/problems/split-array-with-same-average/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int N = A.size(), sum = accumulate(A.begin(), A.end(), 0);
        vector<unordered_set<int>> v(N + 1);
        v[0] = {0};
        for (int i = 0; i < N; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == N - 1) continue;
                for (int n : v[j]) {
                    int m = n + A[i];
                    if (m * N == sum * (j + 1)) return true;
                    v[j + 1].insert(m);
                }
            }
        }
        return false;
    }
};