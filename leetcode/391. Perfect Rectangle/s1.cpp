class Solution {
private:
    inline string getKey(int x, int y) { return to_string(x) + " " + to_string(y); }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty() || rectangles[0].empty()) return false;
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN, area = 0;
        unordered_set<string> s;
        for (auto v : rectangles) {
            x1 = min(x1, v[0]);
            y1 = min(y1, v[1]);
            x2 = max(x2, v[2]);
            y2 = max(y2, v[3]);
            area += (v[2] - v[0]) * (v[3] - v[1]);
            string a = getKey(v[0], v[1]), b = getKey(v[0], v[3]), c = getKey(v[2], v[1]), d = getKey(v[2], v[3]);
            if (!s.erase(a)) s.insert(a);
            if (!s.erase(b)) s.insert(b);
            if (!s.erase(c)) s.insert(c);
            if (!s.erase(d)) s.insert(d);
        }
        return s.count(getKey(x1, y1))
            && s.count(getKey(x1, y2))
            && s.count(getKey(x2, y1))
            && s.count(getKey(x2, y2))
            && s.size() == 4
            && area == (x2 - x1) * (y2 - y1);
    }
};