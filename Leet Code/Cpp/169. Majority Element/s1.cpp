class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cnt = 0, val = 0;
        for (int n : nums) {
            if (!cnt) {
                val = n;
                ++cnt;
            } else if (val != n) --cnt;
            else ++cnt;
        }
        return val;
    }
};