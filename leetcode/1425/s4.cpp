// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
// Ref: https://leetcode.com/problems/constrained-subsequence-sum/discuss/597751/JavaC%2B%2BPython-O(N)-Decreasing-Deque
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        deque<int> q;
        int ans = A[0];
        for (int i = 0; i < A.size(); ++i) {
            A[i] += q.size() ? q.front() : 0;
            ans = max(ans, A[i]);
            while (q.size() && A[i] > q.back()) q.pop_back();
            if (A[i] > 0) q.push_back(A[i]);
            if (i >= k && q.size() && q.front() == A[i - k]) q.pop_front();
        }
        return ans;
    }
};