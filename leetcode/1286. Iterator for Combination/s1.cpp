// OJ: https://leetcode.com/problems/iterator-for-combination/
// Author: github.com/lzl124631x
// Time:
//      CombinationIterator: O(C)
//      next: O(L)
//      hasNext: O(1)
// Space: O(C)
class CombinationIterator {
    string comb;
    int len;
    bool end = false;
    unordered_map<char, char> m;
public:
    CombinationIterator(string chars, int len) : comb(chars.substr(0, len)), len(len) {
        for (int i = chars.size() - 2; i >= 0; --i) m[chars[i]] = chars[i + 1];
    }
    string next() {
        string ans = comb;
        int i = len - 1;
        for (; i >= 0; --i) {
            if (!m.count(comb[i]) || (i < len - 1 && m[comb[i]] == comb[i + 1])) continue;
            comb[i] = m[comb[i]];
            while (++i < len) comb[i] = m[comb[i - 1]];
            break;
        }
        end = i < 0;
        return ans;
    }
    bool hasNext() {
        return !end;
    }
};