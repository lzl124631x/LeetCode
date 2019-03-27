// OJ: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int N = A.size(), begin = 0, maxVal = INT_MIN, cnt = 0;
        while (begin < N) {
            int end = begin;
            while (end < N && A[end] <= R) {
                maxVal = max(maxVal, A[end++]);
            }
            if (maxVal >= L) {
                while (true) {
                    int i = begin;
                    while (i < end && A[i] < L) ++i;
                    if (i == end) break;
                    cnt += (i - begin + 1) * (end - i);
                    begin = i + 1;
                }
            }
            begin = end + 1;
        }
        return cnt;
    }
};