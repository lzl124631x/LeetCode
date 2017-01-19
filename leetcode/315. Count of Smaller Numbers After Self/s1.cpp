class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for (int i = n - 1; i >= 0; --i) {
            int val = nums[i];
            int L = i + 1, R = n - 1;
            while (L <= R) {
                int M = L + (R - L) / 2;
                if (nums[M] >= val) {
                    L = M + 1;
                } else {
                    R = M - 1;
                }
            }
            for (int j = i; j < R; ++j) {
                nums[j] = nums[j + 1];
            }
            nums[R] = val;
            v[i] = n - R - 1;
        }
        return v;
    }
};