class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        string word;
        stringstream ss(s);
        while (ss >> word) ++cnt;
        return cnt;
    }
};