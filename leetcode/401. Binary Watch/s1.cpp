class Solution {
private:
    int n = 0;
    vector<string> ans;
    void dfs(int start, int k) {
        if (!k) {
            if (valid()) ans.push_back(read());
            return;
        }
        for (int i = start; i <= 10 - k; ++i) {
            n |= 1 << i;
            dfs(i + 1, k - 1);
            n ^= 1 << i;
        }
    }
    bool valid() { return (n >> 6) < 12 && (n & ((1 << 6) - 1)) < 60; }
    string read() {
        string m = to_string(n & ((1 << 6) - 1));
        return to_string(n >> 6) + ':' + (m.size() == 1 ? '0' + m : m);
    }
public:
    vector<string> readBinaryWatch(int num) {
        dfs(0, num);
        return ans;
    }
};