// OJ: hhttps://leetcode.com/problems/unique-email-addresses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    string normalize(string &email) {
        string ans;
        int i = 0;
        for (; email[i] != '@'; ++i) {
            if (isalpha(email[i])) ans += email[i];
            if (email[i] == '+') break;
        }
        while (email[i] != '@') ++i;
        return ans + email.substr(i);
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (auto email : emails) {
            s.insert(normalize(email));
        }
        return s.size();
    }
};