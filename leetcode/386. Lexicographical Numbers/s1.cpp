class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int x = 1;
        vector<int> ans;
        while (ans.size() < n) {
            ans.push_back(x);
            if (x * 10 <= n) {
                x *= 10;
            } else {
                if (x + 1 > n) {
                    x /= 10;
                    ++x;
                } else ++x;
                while (x % 10 == 0) x /= 10;
            }
        }
        return ans;
    }
};