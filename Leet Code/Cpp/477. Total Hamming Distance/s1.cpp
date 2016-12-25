class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, N = nums.size();
        for (int i = 0; i < 32; ++i) {
            int k = 0, mask = (1 << i);
            for (int j = 0; j < N; ++j) {
                if (nums[j] & mask) ++k;
            }
            total += k * (N - k);
        }
        return total;
    }
};