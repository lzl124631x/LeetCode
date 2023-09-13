class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long long> v(3, LONG_LONG_MIN);
        for (int n : nums) {
            int i = 0;
            while (i < 3 && v[i] > n) ++i;
            if (i == 3 || v[i] == n) continue;
            for (int j = 2; j > i; --j) v[j] = v[j - 1];
            v[i] = n;
        }
        return v[2] == LONG_LONG_MIN ? v[0] : v[2];
    }
};