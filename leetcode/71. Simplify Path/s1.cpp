class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string> s;
        string name;
        while (getline(ss, name, '/')) {
            if (name.empty() || name == ".") continue;
            if (name == "..") {
                if (s.size()) s.pop();
                continue;
            }
            s.push(name);
        }
        string ans;
        while (s.size()) {
            ans = '/' + s.top() + ans;
            s.pop();
        }
        return ans.size() ? ans : "/";
    }
};