class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        stack<int> s;
        vector<int> ans(N, -1);
        for (int i = 0; i < 2 * N; ++i) {
            int num = nums[i % N];
            while (s.size() && nums[s.top()] < num) {
                ans[s.top()] = num;
                s.pop();
            }
            if (i < N) s.push(i);
        }
        return ans;
    }
};