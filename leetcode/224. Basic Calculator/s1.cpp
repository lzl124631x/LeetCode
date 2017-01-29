class Solution {
private:
    stack<int> num;
    stack<char> op;
    void eval(bool popLeftParen) {
        while (!op.empty() && op.top() != '(') {
            char top = op.top();
            op.pop();
            int a, b, c;
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            switch (top) {
                case '+': c = b + a; break;
                case '-': c = b - a; break;
            }
            num.push(c);
        }
        if (popLeftParen) op.pop();
    }
public:
    int calculate(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                int n = 0;
                while (i < s.size() && isdigit(s[i])) {
                    n = n * 10 + s[i] - '0';
                    ++i;
                }
                --i;
                num.push(n);
            } else {
                switch(s[i]) {
                    case '+':
                    case '-':
                        eval(false);
                        // fall through
                    case '(': {
                        op.push(s[i]);
                        break;
                    }
                    case ')': {
                        eval(true);
                        break;
                    }
                }
            }
        }
        eval(false);
        return num.top();
    }
};