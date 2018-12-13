// OJ: https://leetcode.com/problems/3sum-with-multiplicity/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        map<int, int> m;
        for (int n : A) m[n]++;
        vector<int> nums, cnts;
        for (auto &p : m) {
            nums.push_back(p.first);
            cnts.push_back(p.second);
        }
        int mod = 1e9 + 7, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] == t) ans = (ans + cnts[i] * cnts[j++] * cnts[k--]) % mod;
                else if (nums[j] + nums[k] > t) --k;
                else ++j;
            }
        }
        return ans;
    }
};