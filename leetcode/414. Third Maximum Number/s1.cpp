class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int m[3] = { 0 };
        bool b[3] = { false };
        for (int n : nums) {
            int i = 0;
            for (; i < 3 && b[i] && n < m[i]; ++i);
            if (i < 3) {
                if (b[i] && n > m[i]) {
                    for (int j = 2; j > i; --j) {
                        if (b[j - 1]) {
                            m[j] = m[j - 1];
                            b[j] = true;
                        }
                    }
                }
                b[i] = true;
                m[i] = n;
            }
        }
        return b[2] ? m[2] : m[0];
    }
};