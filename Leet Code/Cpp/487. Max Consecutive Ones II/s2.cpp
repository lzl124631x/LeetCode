//  @haiwei624
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int tot0 = 0, tot1 = 0, ans = 0;
        for(auto num : nums) {
        	tot0++;
        	tot1++;
        	if(num == 0) {
        		tot1 = tot0;
        		tot0 = 0;
        	}
        	ans = max(ans, max(tot0, tot1));
        }
        return ans;
    }
};