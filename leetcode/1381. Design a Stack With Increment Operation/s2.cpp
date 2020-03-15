// OJ: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Author: github.com/lzl124631x
// Time:
//      CustomStack: O(N)
//      push, pop, increment: O(1)
// Space: O(N)
// Ref: https://leetcode.com/problems/design-a-stack-with-increment-operation/discuss/539716/JavaC%2B%2BPython-Lazy-increment-O(1)
class CustomStack {
    int N;
    stack<int> v;
    vector<int> inc;
public:
    CustomStack(int maxSize): N(maxSize), inc(N) {
    }
    
    void push(int x) {
        if (v.size() >= N) return;
        v.push(x);
    }
    
    int pop() {
        if (v.empty()) return -1;
        int n = v.top(), i = v.size() - 1;
        v.pop();
        n += inc[i];
        if (i - 1 >= 0) inc[i - 1] += inc[i];
        inc[i] = 0;
        return n;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)v.size()) - 1;
        if (k >= 0) inc[k] += val;
    }
};