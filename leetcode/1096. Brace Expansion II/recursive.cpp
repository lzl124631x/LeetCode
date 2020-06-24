class Solution {
public:
    vector<string> braceExpansionII(string s) {
        stack<pair<bool, vector<string>>> ans; // bool -> isList
        vector<string> init{""};
        ans.push(make_pair(false, init));
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) {
                if (ans.top().first) {
                    vector<string> tmp{ string(1, s[i]) };
                    ans.push(make_pair(false, tmp));
                } else {
                    for (auto &a : ans.top().second) a += s[i];
                }
            } else if (s[i] == '{') {
                vector<string> tmp;
                ans.push(make_pair(true, tmp));
            } else { // , or }
                auto top = ans.top();
                ans.pop();
                if (ans.top().first) {
                    for (auto &a : top.second) ans.top().second.push_back(a);
                } else {
                    vector<string> tmp;
                    for (auto &a : ans.top().second)
                        for (auto &b : top.second)
                            tmp.push_back(a + b);
                    swap(tmp, ans.top().second);
                }
                if (s[i] == '}') {
                    auto top = ans.top();
                    ans.pop();
                    if (ans.top().first) {
                        for (auto &a : top.second) ans.top().second.push_back(a);
                    } else {
                        vector<string> tmp;
                        for (auto &a : ans.top().second)
                            for (auto &b : top.second)
                                tmp.push_back(a + b);
                        swap(tmp, ans.top().second);
                    }
                }
            }
            cout << i << endl;
        }
        auto &v = ans.top().second;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    }
};