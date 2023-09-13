// OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int longestSubarray(vector<int>& A, int k) {
        multiset<int> s{ A[0] };
        int i = 0, j = 1, N = A.size(), ans = 1;
        while (j < N) {
            s.insert(A[j++]);
            while (*s.rbegin() - *s.begin() > k) s.erase(s.find(A[i++]));
            ans = max(ans, j - i);
        }
        return ans;
    }
};