class Solution {
private:
    bool isVowel (char s) {
        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'
        || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U';
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size();
        while (i < j) {
            while (i < j && !isVowel(s[i])) ++i;
            while (i < j && !isVowel(s[j])) --j;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};