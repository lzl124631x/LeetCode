// class Solution {
// private:
//     long long dist (vector<pair<int, int>>& points, int i, int j) {
//         return pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
//     }
// public:
//     int numberOfBoomerangs(vector<pair<int, int>>& points) {
//         int n = points.size(), cnt = 0;
//         multiset<pair<int, long long>> ms;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int d = dist(points, i, j);
//                 ms.insert(make_pair(i, d));
//                 ms.insert(make_pair(j, d));
//             }
//         }
//         for (auto i = ms.begin(); i != ms.end(); i = ms.upper_bound(*i)) {
//             int c = ms.count(*i);
//             cnt += c * (c - 1);
//         }
//         return cnt;
//     }
// };

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