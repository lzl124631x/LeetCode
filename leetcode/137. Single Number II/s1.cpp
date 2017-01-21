class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;
        for (int n : nums) {
            int newLow, newHigh;
            newLow = low ^ n;
            newHigh = high | (low & n);
            low = newLow ^ (newLow & newHigh);
            high = newHigh ^ (newLow & newHigh);
        }
        return low;
    }
};