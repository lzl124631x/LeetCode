class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0) return {};
        vector<set<int>> out(numCourses);
        vector<int> in(numCourses);
        for (auto p : prerequisites) {
            if (out[p.second].find(p.first) == out[p.second].end()) {
                out[p.second].insert(p.first);
                in[p.first]++;
            }
        }
        queue<int> live;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) live.push(i);
        }
        vector<int> ans;
        while (!live.empty()) {
            int n = live.front();
            live.pop();
            ans.push_back(n);
            for (int o : out[n]) {
                in[o]--;
                if (in[o] == 0) live.push(o);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};