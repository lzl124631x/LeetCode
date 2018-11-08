// OJ: https://leetcode.com/problems/4sum-ii
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        for (auto a : A) {
            for (auto b : B) m[a + b]++;
        }
        int cnt = 0;
        for (auto c : C) {
            for (auto d : D) {
                if (m.find(-c - d) != m.end()) {
                    cnt += m[-c - d];
                }
            }
        }
        return cnt;
    }
};