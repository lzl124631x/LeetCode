class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned x = 0, mask, a = 0;
        for (int n : nums) x ^= n;
        mask = x ^ (x & (x - 1));
        for (int n : nums) if (mask & n) a ^= n;
        return { a, x ^ a };
    }
};