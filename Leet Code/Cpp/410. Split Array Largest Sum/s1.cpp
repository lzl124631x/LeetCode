//https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java
class Solution {
private:
    bool isValid(int M, vector<int> &nums, int m) {
        int sum = 0, cnt = 1;
        for (int n : nums) {
            if (sum + n > M) {
                sum = n;
                ++cnt;
                if (cnt > m) return false;
            } else {
                sum += n;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int N = nums.size(), maxNum = INT_MIN, sum = 0;
        for (int n : nums) {
            maxNum = max(maxNum, n);
            sum += n;
        }
        if (m == 1) return sum;
        int L = maxNum, R = sum;
        while (L <= R) {
            int M = (L + R) / 2;
            if (isValid(M, nums, m)) {
                R = M - 1;
            } else {
                L = M + 1;
            }
        }
        return L;
    }
};


// My TLE Solution
// class Solution {
// public:
//     int splitArray(vector<int>& nums, int m) {
//         if (nums.empty()) return 0;
//         int N = nums.size();
//         vector<vector<int>> dp(m, vector<int>(N, 0));
//         dp[0][0] = nums[0];
//         for (int i = 1; i < N; ++i) {
//             dp[0][i] = dp[0][i - 1] + nums[i];
//         }
//         for (int i = 1; i < m; ++i) {
//             for (int j = 0; j < N; ++j) {
//                 dp[i][j] = INT_MAX;
//                 for (int k = 0; k < j; ++k) {
//                     dp[i][j] = min(dp[i][j], max(dp[i - 1][k], dp[0][j] - dp[0][k]));
//                 }
//             }
//         }
//         return dp[m - 1][N - 1];
//     }
// };