// OJ: https://leetcode.com/problems/mini-parser/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger(); // empty list
        if (s[0] == '[') { // nested list
            NestedInteger n;
            int i = 1, end = s.size() - 1;
            while (i < end) {
                int begin = i;
                if (s[i] == '[') { // element being nested list
                    int cnt = 0;
                    do {
                        if (s[i] == '[') ++cnt;
                        else if (s[i] == ']') --cnt;
                        ++i;
                    } while (cnt > 0);
                } else {
                    while (isdigit(s[i]) || s[i] == '-') ++i;
                }
                n.add(deserialize(s.substr(begin, i - begin)));
                ++i;
            }
            return n;
        }
        // plain number
        return NestedInteger(stoi(s));
    }
};