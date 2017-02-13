class Solution {
private:
    NestedInteger deserialize(string s, int &i) {
        NestedInteger ni;
        if (i >= s.size()) return ni;
        if (s[i] != '[') {
            int n = 0, sign = 1;
            if (s[i] == '-') {
                sign = -1;
                ++i;
            }
            while (i < s.size() && isdigit(s[i])) n = n * 10 + s[i++] - '0';
            ni.setInteger(sign * n);
        } else {
            ++i;//[
            while (i < s.size() && s[i] != ']') {
                ni.add(deserialize(s, i));
                if (i < s.size() && s[i] == ',') ++i;
            }
            ++i;//]
        }
        return ni;
    }
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        return deserialize(s, i);
    }
};