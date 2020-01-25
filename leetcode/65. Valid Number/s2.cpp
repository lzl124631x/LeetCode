// OJ: https://leetcode.com/problems/valid-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
enum State {
    LeadingSpace,
    AfterNumSign,
    NumInteger,
    AfterOnlyDot,
    AfterIntegerAndDot,
    NumDecimal,
    AfterE,
    AfterExpSign,
    Exp,
    TrailingSpace
};

class Solution {
public:
    bool isNumber(string s) {
        State state = LeadingSpace;
        for (int i = 0, N = s.size(); i < N + 1; ++i) {
            switch (state) {
                case LeadingSpace:
                    if (s[i] == ' ') continue;
                    else if (s[i] == '+' || s[i] == '-') state = AfterNumSign;
                    else if (isdigit(s[i])) state = NumInteger;
                    else if (s[i] == '.') state = AfterOnlyDot;
                    else return false;
                    break;
                case AfterNumSign:
                    if (s[i] == '.') state = AfterOnlyDot;
                    else if (isdigit(s[i])) state = NumInteger;
                    else return false;
                    break;
                case NumInteger:
                    if (isdigit(s[i])) continue;
                    else if (s[i] == '.') state = AfterIntegerAndDot;
                    else if (s[i] == 'e') state = AfterE;
                    else if (s[i] == ' ') state = TrailingSpace;
                    else if (s[i] == '\0') return true;
                    else return false;
                    break;
                case AfterOnlyDot:
                    if (isdigit(s[i])) state = NumDecimal;
                    else return false;
                    break;
                case AfterIntegerAndDot:
                    if (isdigit(s[i])) state = NumDecimal;
                    else if (s[i] == ' ') state = TrailingSpace;
                    else if (s[i] == 'e') state = AfterE;
                    else if (s[i] == '\0') return true;
                    else return false;
                    break;
                case NumDecimal:
                    if (s[i] == ' ') state = TrailingSpace;
                    else if (isdigit(s[i])) state = NumDecimal;
                    else if (s[i] == 'e') state = AfterE;
                    else if (s[i] == '\0') return true;
                    else return false;
                    break;
                case AfterE:
                    if (s[i] == '+' || s[i] == '-') state = AfterExpSign;
                    else if (isdigit(s[i])) state = Exp;
                    else return false;
                    break;
                case AfterExpSign:
                    if (isdigit(s[i])) state = Exp;
                    else if (s[i] == ' ') state = TrailingSpace;
                    else return false;
                    break;
                case Exp:
                    if (isdigit(s[i])) continue;
                    else if (s[i] == ' ') state = TrailingSpace;
                    else if (s[i] == '\0') return true;
                    else return false;
                    break;
                case TrailingSpace:
                    if (s[i] == ' ') continue;
                    else if (s[i] == '\0') return true;
                    else return false;
                    break;
            }
        }
        return false;
    }
};