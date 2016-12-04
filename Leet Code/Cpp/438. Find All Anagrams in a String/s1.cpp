class Solution {
private:
    bool isAnagram (int S[], int P[]) {
        for (int i = 0; i < 26; ++i) {
            if (S[i] != P[i]) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> v;
        if (n > m) return v;
        int S[26] = {0}, P[26] = {0};
        for (int i = 0; i < n; ++i) {
            P[p[i] - 'a']++;
            S[s[i] - 'a']++;
        }
        if (isAnagram(S, P)) v.push_back(0);
        for (int i = 1; i <= m - n; ++i) {
            S[s[i - 1] - 'a']--;
            S[s[i + n - 1] - 'a']++;
            if (isAnagram(S, P)) {
                v.push_back(i);
            }
        }
        return v;
    }
};