class Solution {
private:
    vector<string> ans { "JFK" };
    unordered_map<string, multiset<string>> m;
    int N;
    bool dfs() {
        if (ans.size() == N + 1) return true;
        string from = ans.back();
        auto s = m[from];
        for (auto it = s.begin(); it != s.end(); it = s.upper_bound(*it)) {
            string to = *it;
            ans.push_back(to);
            m[from].erase(m[from].find(to));
            if (dfs()) return true;
            m[from].insert(to);
            ans.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        N = tickets.size();
        for (auto p : tickets) m[p.first].insert(p.second);
        dfs();
        return ans;
    }
};