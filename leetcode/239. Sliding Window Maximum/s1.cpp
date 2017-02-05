// https://discuss.leetcode.com/topic/19067/clean-c-o-n-solution-using-a-deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};