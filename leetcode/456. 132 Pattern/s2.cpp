class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int right = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int n = nums[i];
            if (n < right) return true;
            while (!s.empty() && s.top() < n) {
                right = s.top();
                s.pop();
            }
            s.push(n);
        }
        return false;
    }
};