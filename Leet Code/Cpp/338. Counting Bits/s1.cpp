class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        int i = 1;
        while (i <= num) {
            v[i] = 1;
            for (int j = 1; j < i && i + j <= num; ++j) {
                v[i + j] = v[i] + v[j];
            }
            i *= 2;
        }
        return v;
    }
};