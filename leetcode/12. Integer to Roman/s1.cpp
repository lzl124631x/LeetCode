class Solution {
private:
    const string CHAR = "IVXLCDM__";
public:
    string intToRoman(int num) {
        string ans;
        int i = 0;
        while (num) {
            int n = num % 10;
            char one = CHAR[i], five = CHAR[i + 1], ten = CHAR[i + 2];
            if (n <= 3) while (n--) ans += one;
            else if (n == 4) {
                ans += five;
                ans += one;
            } else if (n <= 8) {
                for (int i = n - 5; i > 0; --i) ans += one;
                ans += five;
            } else if (n == 9) {
                ans += ten;
                ans += one;
            }
            num /= 10;
            i += 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};