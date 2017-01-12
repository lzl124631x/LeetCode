// https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references
class Solution {
private:
    int maxSumSubarray(vector<int> &array, int bound) {
        set<int> s;
        s.insert(0);
        int sum = 0, ans = INT_MIN;
        for (int n : array) {
            sum += n;
            auto it = s.lower_bound(sum - bound);
            if (it != s.end()) ans = max(ans, sum - *it);
            s.insert(sum);
        }
        return ans;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int bound) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int M = matrix.size(), N = matrix[0].size(), ans = INT_MIN;
        for (int i = 0; i < N; ++i) {
            vector<int> v(M, 0);
            for (int j = i; j < N; ++j) {
                int currMax = 0;
                for (int k = 0; k < M; ++k) {
                    v[k] += matrix[k][j];
                }
                ans = max(ans, maxSumSubarray(v, bound));
            }
        }
        return ans;
    }
};