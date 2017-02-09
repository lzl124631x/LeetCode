class Solution {
private:
    void divide(vector<int> &a) {
        int n = 0, j = 0;
        for (int i = 0; i < a.size(); ++i) {
            n = n * 10 + a[i];
            if (n / 2 != 0 || j != 0) a[j++] = n / 2;
            n %= 2;
        }
        a.erase(a.begin() + j, a.end());
        if (a.empty()) a.push_back(0);
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.size() == 1 && b[0] == 0) return 1;
        bool even = b.back() % 2 == 0;
        long long ans = even ? 1 : a;
        divide(b);
        ans *= (long long)pow(superPow(a, b), 2) % 1337;
        return ans % 1337;
    }
};