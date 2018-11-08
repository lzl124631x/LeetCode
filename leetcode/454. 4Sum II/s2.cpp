// OJ: https://leetcode.com/problems/4sum-ii
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if (A.empty()) return 0;
        int N = A.size(), cnt = 0;
        unordered_map<int, int> AB, CD;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                AB[A[i] + B[j]]++;
                CD[C[i] + D[j]]++; 
            }
        }
        for (auto it = AB.begin(); it != AB.end(); ++it) {
            cnt += it->second * CD[-it->first];
        }
        return cnt;
    }
};