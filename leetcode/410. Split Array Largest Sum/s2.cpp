// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N * log(S)) where S is sum of nums.
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java
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