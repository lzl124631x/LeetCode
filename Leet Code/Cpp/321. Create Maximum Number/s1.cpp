// https://discuss.leetcode.com/topic/32272/share-my-greedy-solution
class Solution {
private:
    vector<int> maxSubarray(vector<int> &nums, int k) {
        int N = nums.size();
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            while (!ans.empty() && ans.back() < nums[i] && k - ans.size() < N - i) ans.pop_back();
            if (ans.size() < k) ans.push_back(nums[i]);
        }
        return ans;
    }
    
    bool greater(vector<int> &nums1, int i, vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            ++i;
            ++j;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
    
    vector<int> merge(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> v;
        for (int i = 0, j = 0, r = 0; r < k; ++r) {
            v.push_back(greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++]);
        }
        return v;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int M = nums1.size(), N = nums2.size();
        vector<int> ans;
        for (int i = max(0, k - N); i <= k && i <= M; ++i) {
            vector<int> a = maxSubarray(nums1, i), b = maxSubarray(nums2, k - i);
            vector<int> v = merge(a, b, k);
            if (greater(v, 0, ans, 0)) ans = v;
        }
        return ans;
    }
};