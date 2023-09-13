// OJ: https://leetcode.com/problems/sum-of-even-numbers-after-queries/
// Author: github.com/lzl124631x
// Time: O(A + Q)
// Space: O(1)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        int sum = 0;
        for (int n : A) {
            if (n % 2 == 0) sum += n;
        }
        for (int i = 0; i < queries.size(); ++i) {
            auto q = queries[i];
            int val = q[0], index = q[1], prev = A[index];
            A[index] += val;
            bool wasEven = prev % 2 == 0, even = A[index] % 2 == 0;
            if (wasEven && even) {
                ans[i] = (sum += val);
            } else if (wasEven && !even) {
                ans[i] = (sum -= prev);
            } else if (!wasEven && even) {
                ans[i] = (sum += A[index]);
            } else ans[i] = sum;
        }
        return ans;
    }
};