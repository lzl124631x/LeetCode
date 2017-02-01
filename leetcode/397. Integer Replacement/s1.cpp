class Solution {
private:
    static unordered_map<long long, int> memo;
    int rec(long long n) {
        if (memo.find(n) != memo.end()) return memo[n];
        if (n % 2 == 0) {
            return memo[n] = 1 + rec(n / 2);
        } else {
            return memo[n] = 1 + min(rec(n - 1), rec(n + 1));
        }
    }
public:
    int integerReplacement(int n) {
        return rec(n);
    }
};

unordered_map<long long, int> Solution::memo{{1, 0}};