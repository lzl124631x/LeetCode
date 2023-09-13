// OJ: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Author: github.com/lzl124631x
// Time:
//      CustomStack, push, pop: O(1)
//      increment: O(k)
// Space: O(N)
class CustomStack {
    int N;
    vector<int> v;
public:
    CustomStack(int maxSize): N(maxSize) {}
    void push(int x) {
        if (v.size() >= N) return;
        v.push_back(x);
    }
    int pop() {
        if (v.empty()) return -1;
        int n = v.back();
        v.pop_back();
        return n;
    }
    void increment(int k, int val) {
        k = min(k, (int)v.size());
        for (int i = 0; i < k; ++i) v[i] += val;
    }
};