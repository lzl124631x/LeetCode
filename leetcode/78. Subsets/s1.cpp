class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int start, vector<int> &sub, int leftLen) {
        if (leftLen == 0) {
            ans.push_back(sub);
            return;
        }
        for (int i = start; i <= nums.size() - leftLen; ++i) {
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, leftLen - 1);
            sub.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        for (int i = 0; i <= nums.size(); ++i) dfs(nums, 0, v, i);
        return ans;
    }
};