// OJ: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Author: github.com/lzl124631x
// Time:
//      CustomStack: O(N)
//      push, pop, increment: O(1)
// Space: O(N)
// Ref: https://leetcode.com/problems/design-a-stack-with-increment-operation/discuss/539716/JavaC%2B%2BPython-Lazy-increment-O(1)
class CustomStack {
    stack<int> s;
    vector<int> update;
public:
    CustomStack(int maxSize) : update(maxSize) {}
    
    void push(int x) {
        if (s.size() == update.size()) return;
        s.push(x);
    }
    
    int pop() {
        if (s.empty()) return -1;
        int ans = s.top(), index = s.size() - 1;
        s.pop();
        ans += update[index];
        if (index - 1 >= 0) update[index - 1] += update[index];
        update[index] = 0;
        return ans;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)s.size()) - 1;
        if (k >= 0) update[k] += val;
    }
};