// OJ: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/longest-consecutive-sequence/discuss/41116/C%2B%2B-Union-Find-amotrized-O(n)
class UnionFind {
    vector<int> id, size;
public:
    UnionFind(int n) : id(n), size(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        size[y] += size[x];
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    vector<int> &getSizes() {
        return size;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        UnionFind uf(nums.size());
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if (m.count(n)) continue;
            m[n] = i;
            if (m.count(n + 1)) uf.connect(m[n], m[n + 1]);
            if (m.count(n - 1)) uf.connect(m[n], m[n - 1]);
        }
        return *max_element(uf.getSizes().begin(), uf.getSizes().end());
    }
};