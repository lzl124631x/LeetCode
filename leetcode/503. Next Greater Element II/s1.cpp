// OJ: https://leetcode.com/problems/next-greater-element-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        stack<int> s;
        int N = A.size();
        vector<int> ans(N, -1);
        for (int i = 0; i < 2 * N; ++i) {
            int n = A[i % N];
            while (s.size() && A[s.top()] < n) {
                ans[s.top()] = n;
                s.pop();
            }
            s.push(i % N);
        }
        return ans;
    }
};