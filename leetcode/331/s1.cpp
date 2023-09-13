class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> s;
        stringstream ss(preorder);
        string node;
        bool ended = false;
        while (getline(ss, node, ',')) {
            if (ended) return false;
            if (node == "#") {
                while (!s.empty() && ++s.top() == 2) {
                    s.pop();
                }
                if (s.empty()) ended = true;
            } else {
                s.push(0);
            }
        }
        return s.empty();
    }
};