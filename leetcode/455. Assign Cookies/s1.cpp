class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        auto ig = g.begin(), is = s.begin();
        int cnt = 0;
        while (ig != g.end() && is != s.end()) {
            if (*is >= *ig) {
                ++is;
                ++cnt;
            }
            ++ig;
        }
        return cnt;
    }
};