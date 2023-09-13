// OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/609771/JavaC%2B%2BPython-Deques-O(N)
class Solution {
public:
    int longestSubarray(vector<int>& A, int k) {
        deque<int> mx, mn;
        int i = 0, j = 0;
        for (; j < A.size(); ++j) {
            while (mx.size() && mx.back() < A[j]) mx.pop_back();
            while (mn.size() && mn.back() > A[j]) mn.pop_back();
            mx.push_back(A[j]);
            mn.push_back(A[j]);
            if (mx.front() - mn.front() > k) {
                if (A[i] == mx.front()) mx.pop_front();
                if (A[i] == mn.front()) mn.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};