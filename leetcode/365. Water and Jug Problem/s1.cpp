class Solution {
private:
    set<int> s;
    queue<int> q;
    void push(int v) {
        if (!s.count(v) && v) {
            s.insert(v);
            q.push(v);
        }
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (!z || x == z || y == z) return true;
        if (x == y) return x == z || 2 * x == z;
        if (x < y) swap(x, y);
        q.push(x);
        q.push(y);
        while (q.size()) {
            int v = q.front();
            if (v == z) return true;
            q.pop();
            if (v <= x) {
                if (v > y) push(v - y);
                else {
                    push(v + x);
                    push(x - y + v);
                }
                push(v + y);
            }
        }
        return false;
    }
};