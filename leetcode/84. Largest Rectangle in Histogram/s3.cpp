// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28902/5ms-O(n)-Java-solution-explained-(beats-96)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), ans = 0;
        vector<int> left(N), right(N);
        left[0] = -1;
        right[N - 1] = N;
        for (int i = 1; i < N; ++i) {
            int j = i - 1;
            while (j >= 0 && A[j] >= A[i]) j = left[j];
            left[i] = j;
        }
        for (int i = N - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < N && A[j] >= A[i]) j = right[j];
            right[i] = j;
        }
        for (int i = 0; i < N; ++i) ans = max(ans, (right[i] - left[i] - 1) * A[i]);
        return ans;
    }
};