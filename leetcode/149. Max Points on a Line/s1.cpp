// OJ: https://leetcode.com/problems/max-points-on-a-line/
// Author: github.com/lzl124631x
// Time: O(N^3)
//   In worse case, when visiting ith point, there will be O(i^2)
//   lines, but all the lines are of constant size 2. So in
//   sum it's O(N^3), not O(N^4).
// Space: O(N^2)
namespace std {
    template <> struct hash<Point> {
        std::size_t operator () (const Point &p) const {
            return hash<int>()(p.x) ^ hash<int>()(p.y);
        }
    };
}

bool operator==(const Point& a, const Point& b) {
	return a.x == b.x && a.y == b.y;
}

class Solution {
private:
    bool onSameLine(Point &a, Point &b, Point &c) {
        return (long long)(a.x - b.x) * (a.y - c.y) == (long long)(a.x - c.x) * (a.y - b.y);
    }
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        unordered_map<Point, int> m;
        for (auto p : points) m[p]++;
        vector<pair<Point, int>> ps(m.begin(), m.end());
        vector<vector<int>> lines(1, vector<int>{ 0, 1 });
        int N = ps.size();
        for (int i = 2; i < N; ++i) {
            auto &p = ps[i].first;
            vector<int> bad(i, 1);
            for (auto &line : lines) {
                auto &p1 = ps[line[0]].first, &p2 = ps[line[1]].first;
                if (!onSameLine(p1, p2, p)) continue;
                for (int neighbor : line) bad[neighbor] = 0;
                line.push_back(i);
            }
            for (int j = 0; j < i; ++j) {
                if (bad[j]) lines.emplace_back(vector<int>{ j, i });
            }
        }
        int ans = 2;
        for (auto line : lines) {
            int cnt = 0;
            for (auto i : line) cnt += ps[i].second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};