// OJ: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> finalPrices(vector<int>& A) {
        stack<int> s;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.top()] >= A[i]) {
                A[s.top()] -= A[i];
                s.pop();
            }
            s.push(i);
        }
        return A;
    }
};