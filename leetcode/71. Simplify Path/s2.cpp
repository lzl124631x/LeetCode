class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> s;
        string name;
        while (getline(ss, name, '/')) {
            if (name == "..") {
                if (s.size()) s.pop_back();
            } else if (name.size() && name != ".") s.push_back(name);
        }
        string ans;
        for (auto n : s) ans += '/' + n;
        return ans.size() ? ans : "/";
    }
};