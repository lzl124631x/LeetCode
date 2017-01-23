class Solution {
private:
    unordered_map<int, set<int>> next;
    vector<bool> v;
    bool hasCircle(int start) {
        if (v[start]) return true;
        v[start] = true;
        auto n = next[start];
        for (int to : n) {
            if (hasCircle(to)) return true;
            next[start].erase(to);
        }
        return v[start] = false;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        for (auto p : prerequisites) next[p.first].insert(p.second);
        for (int i = 0; i < numCourses; ++i) {
            v = vector<bool>(numCourses, false);
            if (hasCircle(i)) return false;
        }
        return true;
    }
};