// OJ: https://leetcode.com/problems/interval-list-intersections/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(1)
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int M = A.size(), N = B.size();
        vector<Interval> ans;
        for (int i = 0, j = 0; i < M && j < N;) {
            while (j < N && A[i].start > B[j].end) ++j;
            if (j >= N) break;
            while (i < M && B[j].start > A[i].end) ++i;
            if (i >= M) break;
            int s = max(A[i].start, B[j].start), e = min(A[i].end, B[j].end);
            if (s <= e) ans.emplace_back(s, e);
            if (A[i].end < B[j].end) ++i;
            else ++j;
        }
        return ans;
    }
};