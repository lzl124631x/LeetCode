class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int cnt[26] = {0};
        int len, res = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i - 1] - 'a' + 1) % 26 == p[i] - 'a') ++len;
            else len = 1;
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], len);
        }
        for (int n : cnt) res += n;
        return res;
    }
};

// Slightly different solution
// class Solution {
// public:
//     int findSubstringInWraproundString(string p) {
//         int cnt[26] = {0};
//         int len, res = 0;
//         for (int i = 0; i < p.size(); ++i) {
//             if (i > 0 && (p[i - 1] - 'a' + 1) % 26 == p[i] - 'a') ++len;
//             else len = 1;
//             int index = p[i] - 'a';
//             if (len > cnt[index]) {
//                 res += len - cnt[index];
//                 cnt[index] = len;
//             }
//         }
//         return res;
//     }
// };