class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxCnt = 0;
        for (int n : nums) {
            if (n == 1) maxCnt = max(maxCnt, ++cnt);
            else cnt = 0;
        }
        return maxCnt;
    }
};