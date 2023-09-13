class Solution {
private:
    map<char, int> cnts;
    vector<int> cs;
    string ans;
    void helper(char c, string s, int i) {
        int cnt = cnts[c];
        for (char c : s) cnts[c] -= cnt;
        cs[i] = cnt;
    }
public:
    string originalDigits(string s) {
        cs = vector<int>(10, 0);
        for (char c : s) cnts[c]++;
        helper('z', "zero", 0);
        helper('w', "two", 2);
        helper('u', "four", 4);
        helper('x', "six", 6);
        helper('g', "eight", 8);
        helper('o', "one", 1);
        helper('h', "three", 3);
        helper('f', "five", 5);
        helper('s', "seven", 7);
        helper('i', "nine", 9);
        for (int i = 0; i <= 9; ++i) {
            while (cs[i]--) ans += '0' + i;
        }
        return ans;
    }
};