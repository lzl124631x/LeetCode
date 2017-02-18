// https://discuss.leetcode.com/topic/63903/short-easy-c-using-set
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int n : nums) {
            s.insert(n);
            if (s.size() > 3) s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};