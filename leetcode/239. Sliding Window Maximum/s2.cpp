// OJ: https://leetcode.com/problems/sliding-window-maximum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= k && q.size() && q.front() == A[i - k]) q.pop_front();
            while (q.size() && q.back() < A[i]) q.pop_back();
            q.push_back(A[i]);
            if (i >= k - 1) ans.push_back(q.front());
        }
        return ans;
    }
};