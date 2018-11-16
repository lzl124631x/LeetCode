// OJ: https://leetcode.com/problems/subdomain-visit-count/
// Author: github.com/lzl124631x
// Time: O(N*S^2) where N is count of cpdomains, S is max length of cpdomain string.
// Space: O(N)
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (auto cpdomain : cpdomains) {
            int cnt = stoi(cpdomain), i = cpdomain.find_first_of(" ");
            string domain = cpdomain.substr(i + 1);
            while (true) {
                m[domain] += cnt;
                i = domain.find_first_of(".");
                if (i == string::npos) break;
                domain = domain.substr(i + 1);
            }
        }
        vector<string> v;
        for (auto p : m) {
            v.push_back(to_string(p.second) + " " + p.first);
        }
        return v;
    }
};