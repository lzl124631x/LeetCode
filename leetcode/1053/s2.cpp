// OJ: https://leetcode.com/problems/previous-permutation-with-one-swap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        stack<pair<int, int>> s;
        int first = -1, second = -1;
        for (int i = 0; i < A.size(); ++i) {
            while (s.size() && A[i] >= s.top().second) s.pop();
            if (s.size() && (s.top().first >= second || (s.top().first == first && A[i] != A[second]))) {
                first = s.top().first;
                second = i;
            }
            s.emplace(i, A[i]);
        }
        if (first > -1) swap(A[first], A[second]);
        return A;
    }
};