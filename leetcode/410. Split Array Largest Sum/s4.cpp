// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N * log(S)) where S is sum of nums.
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java
class Solution {
    typedef long long LL;
    int split(vector<int> &A, LL M) {
        LL cnt = 0, sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum > M) {
                sum = A[i];
                ++cnt;
            }
        }
        return cnt + 1;
    }
public:
    int splitArray(vector<int>& A, int m) {
        LL sum = accumulate(begin(A), end(A), (LL)0);
        if (m == 1) return sum;
        LL L = *max_element(begin(A), end(A)), R = sum;
        while (L <= R) {
            LL M = (L + R) / 2;
            int n = split(A, M);
            if (n <= m) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};