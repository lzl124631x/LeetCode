// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        unordered_map<char, int> cnt;
        unordered_set<char> added;
        stack<char> st;
        for (char c : s) cnt[c]++;
        for (char c : s) {
            cnt[c]--;
            if (added.find(c) != added.end()) continue;
            while (st.size() && c < st.top() && cnt[st.top()]) {
                added.erase(st.top());
                st.pop();
            }
            st.push(c);
            added.insert(c);
        }
        string ans;
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};