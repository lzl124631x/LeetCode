class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while (--n) {
            string next;
            int i = 0;
            while (i < ans.size()) {
                char c = ans[i];
                int cnt = 0;
                while (i < ans.size() && ans[i] == c) ++cnt, ++i;
                next += to_string(cnt) + c;
            }
            ans = next;
        }
        return ans;
    }
};