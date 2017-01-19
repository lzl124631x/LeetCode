// Boyer-Moore Majority Vote algorithm
// https://discuss.leetcode.com/topic/17564/boyer-moore-majority-vote-algorithm-and-my-elaboration
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, v1 = 0, v2 = 1;
        for (int n : nums) {
            if (v1 == n) ++c1;
            else if (v2 == n) ++c2;
            else if (!c1) v1 = n, ++c1;
            else if (!c2) v2 = n, ++c2;
            else --c1, --c2;
        }
        c1 = c2 = 0;
        for (int n : nums) {
            if (v1 == n) ++c1;
            if (v2 == n) ++c2;
        }
        vector<int> v;
        if (c1 > nums.size() / 3) v.push_back(v1);
        if (c2 > nums.size() / 3) v.push_back(v2);
        return v;
    }
};