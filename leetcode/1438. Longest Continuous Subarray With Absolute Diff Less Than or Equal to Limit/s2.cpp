// OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestSubarray(vector<int>& A, int k) {
        deque<int> mx{A[0]}, mn{A[0]};
        int N = A.size(), ans = 1, i = 0, j = 1;
        while (j < N) {
            while (j < N && mx.front() - mn.front() <= k) { 
                while (mx.size() && mx.back() < A[j]) mx.pop_back();
                mx.push_back(A[j]);
                while (mn.size() && mn.back() > A[j]) mn.pop_back();
                mn.push_back(A[j]);
                ++j;
                if (mx.front() - mn.front() <= k) ans = max(ans, j - i);
            }
            while (i < j && mx.front() - mn.front() > k) {
                if (A[i] == mx.front()) mx.pop_front();
                if (A[i] == mn.front()) mn.pop_front();
                ++i;
            }
        }
        return ans;
    }
};