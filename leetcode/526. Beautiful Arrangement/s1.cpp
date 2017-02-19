class Solution {
private:
    int ans = 0;
    int N;
    void dfs(int start, set<int> s) {
        if (start == N + 1) {
            ++ans;
            return;
        }
        for (auto it = s.begin(); it != s.end();) {
            int n = *it++;
            if (n % start == 0 || start % n == 0) {
                s.erase(n);
                dfs(start + 1, s);
                s.insert(n);
            }
        }
    }
public:
    int countArrangement(int N) {
        this->N = N;
        set<int> s;
        for (int i = 1; i <= N; ++i) s.insert(i);
        dfs(1, s);
        return ans;
    }
};