class Solution {
private:
    int cnt = 0;
    vector<pair<int, int>> tuple;
    vector<pair<int, int>> points;
    long long dist(pair<int, int> &a, pair<int, int> &b) {
        return pow(b.first - a.first, 2) + pow(b.second - a.second, 2);
    }
    void dfs(vector<pair<int, int>> &points, int start, int k) {
        if (!k) {
            int a = dist(tuple[0], tuple[1]);
            int b = dist(tuple[0], tuple[2]);
            int c = dist(tuple[1], tuple[2]);
            cnt += 2 * ((a == b) + (a == c) + (b == c));
            return;
        }
        for (int i = start; i <= points.size() - k; ++i) {
            tuple.push_back(points[i]);
            dfs(points, i + 1, k - 1);
            tuple.pop_back();
        }
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.size() < 3) return 0;
        dfs(points, 0, 3);
        return cnt;
    }
};
// Time O(n^3), Space O(1)