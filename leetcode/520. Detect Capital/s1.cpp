class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allCapital = true, firstCapital, remAllSmall = true, allSmall = true;
        for (int i = 0; i < word.size(); ++i) {
            bool b = isupper(word[i]);
            if (i == 0) firstCapital = b;
            else remAllSmall = remAllSmall && !b;
            allCapital = allCapital && b;
            allSmall = allSmall && !b;
        }
        return allCapital || firstCapital && remAllSmall || allSmall;
    }
};