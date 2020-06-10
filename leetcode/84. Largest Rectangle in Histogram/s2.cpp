// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.push_back(0);
        int N = A.size(), ans = 0;
        stack<int> s;
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.top()] > A[i]) {
                int h = A[s.top()];
                s.pop();
                int j = s.size() ? s.top() : -1;
                ans = max(ans, h * (i - j - 1));
            }
            s.push(i);
        }
        return ans;
    }
};