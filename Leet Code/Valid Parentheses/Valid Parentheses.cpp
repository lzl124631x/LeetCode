class Solution {
public:
    // parentheses (), brackets [], braces {}
    bool isValid(string str) {
        char dic[] = "{[(";
        stack<char> s;
        string::iterator i = str.begin();
        for(; i != str.end(); ++i){
            int j = 0;
            switch(*i){
                case '(':
                case '[':
                case '{':
                    s.push(*i); break;
                case ')': j++;
                case ']': j++;
                case '}':
                    if(s.empty() || s.top() != dic[j]) return false;
                    s.pop(); break;
                default: break;
            }
        }
        return s.empty();
    }
};