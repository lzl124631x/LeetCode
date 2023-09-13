class Solution {
private:
    int dist (vector<pair<int, int>>& points, int i, int j) {
        return pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            map<int, int> mp;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int d = dist(points, i, j);
                mp[d]++;
            }
            for (auto i = mp.begin(); i != mp.end(); ++i) {
                cnt += i->second * (i->second - 1);
            }
        }
        return cnt;
    }
};
// Time O(n^2), Space O(n)