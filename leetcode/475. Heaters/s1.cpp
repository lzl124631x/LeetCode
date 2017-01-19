class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int i = 0, j = 0, m = houses.size(), n = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int r = INT_MIN;
        while (i < m) {
            int ir = abs(houses[i] - heaters[j]), nextR;
            while (j + 1 < n && (nextR = abs(houses[i] - heaters[j + 1])) <= ir) {
                ir = nextR;
                ++j;
            }
            r = max(r, ir);
            ++i;
        }
        return r;
    }
};