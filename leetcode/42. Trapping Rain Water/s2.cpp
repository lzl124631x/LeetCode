// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& A) {
        stack<int> s;
        int N = A.size(), ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (s.empty() || A[i] > A[s.top()]) s.push(i);
        }
        for (int i = 0; i < N - 1;) {
            int h = A[i];
            if (i == s.top()) {
                s.pop();
                h = A[s.top()];
            }
            int j = i + 1;
            while (j < N && A[j] < h) ans += h - A[j++];
            i = j;
        }
        return ans;
    }
};