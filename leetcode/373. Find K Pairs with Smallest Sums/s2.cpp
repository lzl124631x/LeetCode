// https://discuss.leetcode.com/topic/50481/clean-16ms-c-o-n-space-o-klogn-time-solution-using-priority-queue
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        int M = nums1.size(), N = nums2.size();
        if (!M || !N) return {};
        q.emplace(0, 0);
        vector<pair<int, int>> ans;
        while (!q.empty() && k--) {
            auto p = q.top();
            int i = p.first, j = p.second;
            q.pop();
            ans.emplace_back(nums1[i], nums2[j]);
            if (i + 1 < M) q.emplace(i + 1, j);
            if (i == 0 && j + 1 < N) q.emplace(i, j + 1);
        }
        return ans;
    }
};