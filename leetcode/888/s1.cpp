// OJ: https://leetcode.com/problems/fair-candy-swap/
// Author: github.com/lzl124631x
// Time: O(A+B)
// Space: O(B)
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int s1 = accumulate(A.begin(), A.end(), 0);
        int s2 = accumulate(B.begin(), B.end(), 0);
        int d = (s1 - s2) / 2;
        unordered_set<int> s;
        for (int b : B) s.insert(b);
        for (int a : A) {
            if (s.find(a - d) != s.end()) return { a, a - d };
        }
    }
};