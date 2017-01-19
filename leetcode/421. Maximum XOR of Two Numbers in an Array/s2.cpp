// https://discuss.leetcode.com/topic/63213/java-o-n-solution-using-bit-manipulation-and-hashmap
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        unordered_set<int> s;
        int mask = 0, maxVal = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            s.clear();
            for (int n : nums) {
                s.insert(n & mask);
            }
            int next = maxVal | (1 << i);
            for (int prefix : s) {
                if (s.count(next ^ prefix)) {
                    maxVal |= (1 << i);
                    break;
                }
            }
        }
        return maxVal;
    }
};