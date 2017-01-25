class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        multiset<int> right(nums.begin() + 1, nums.end());
        int minLeft = nums[0];
        for (int i = 1; i < nums.size() - 1; ++i) {
            int mid = nums[i];
            auto it = right.find(mid);
            right.erase(it);
            if (mid <= minLeft) {
                minLeft = mid;
            } else {
                auto r = right.upper_bound(mid - 1);
                if (r != right.begin() && *prev(r) > minLeft) return true;
            }
        }
        return false;
    }
};