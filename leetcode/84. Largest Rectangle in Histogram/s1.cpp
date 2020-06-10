// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.insert(A.begin(), 0);
        A.push_back(0);
        int N = A.size(), ans = 0;
        vector<int> left(N), right(N), s;
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.back()] > A[i]) {
                right[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        for (int i = N - 1; i >= 0; --i) {
            while (s.size() && A[s.back()] > A[i]) {
                left[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        for (int i = 0; i < N; ++i) ans = max(ans, (right[i] - left[i] - 1) * A[i]); 
        return ans;
    }
};