// OJ: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/discuss/489716/Python-O(n)
class Solution {
public:
    int maxValueAfterReverse(vector<int>& A) {
        if (A.size() == 2) return abs(A[0] - A[1]);
        int ans = 0, N = A.size(), maxGap = 0, low = max(A[0], A[1]), high = min(A[0], A[1]);
        for (int i = 1; i < N; ++i) ans += abs(A[i] - A[i - 1]);
        for (int i = 3; i < N; ++i) {
            maxGap = max({ maxGap, high - max(A[i - 1], A[i]), min(A[i - 1], A[i]) - low });
            high = max(high, min(A[i - 2], A[i - 1]));
            low = min(low, max(A[i - 2], A[i - 1]));
        }
        maxGap *= 2;
        for (int i = 0; i < N - 2; ++i) maxGap = max(maxGap, abs(A[N - 1] - A[i]) - abs(A[i + 1] - A[i]));
        for (int i = 2; i < N; ++i) maxGap = max(maxGap, abs(A[0] - A[i]) - abs(A[i] - A[i - 1]));
        return ans + maxGap;
    }
};