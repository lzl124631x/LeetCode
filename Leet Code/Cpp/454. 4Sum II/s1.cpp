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
            auto it2 = CD.find(-it->first);
            if (it2 != CD.end()) cnt += it->second * it2->second;
        }
        return cnt;
    }
};