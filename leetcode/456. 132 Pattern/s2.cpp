// OJ: https://leetcode.com/problems/132-pattern/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
class Solution {
public:
    bool find132pattern(vector<int>& A) {
        stack<int> s;
        int right = INT_MIN;
        for (int i = A.size() - 1; i >= 0; --i) {
            if (A[i] < right) return true;
            while (s.size() && s.top() < A[i]) {
                right = s.top();
                s.pop();
            }
            s.push(A[i]);
        }
        return false;
    }
};