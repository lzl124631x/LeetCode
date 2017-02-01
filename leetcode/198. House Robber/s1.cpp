class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, prev2 = 0;
        for (int n : nums) {
            int cur = max(prev, prev2 + n);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};