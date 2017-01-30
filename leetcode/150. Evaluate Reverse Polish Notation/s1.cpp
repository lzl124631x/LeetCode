class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string s : tokens) {
            if (isdigit(s.back())) {
                nums.push(stoi(s));
            } else {
                int a, b;
                b = nums.top(); nums.pop();
                a = nums.top(); nums.pop();
                switch (s[0]) {
                    case '+': a += b; break;
                    case '-': a -= b; break;
                    case '*': a *= b; break;
                    case '/': a /= b; break;
                }
                nums.push(a);
            }
        }
        return nums.top();
    }
};