class Solution {
private:
    struct Item {
        int x, y, v;
        Item (int x, int y, int v) : x(x), y(y), v(v) {}
    };
    struct Cmp {
        bool operator() (Item a, Item b) {
            return a.v > b.v;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int N = matrix.size();
        priority_queue<Item, vector<Item>, Cmp> q;
        for (int i = 0; i < N; ++i) q.push(Item(0, i, matrix[0][i]));
        while (--k) {
            auto item = q.top();
            int x = item.x, y = item.y;
            q.pop();
            if (x + 1 < N) {
                q.push(Item(x + 1, y, matrix[x + 1][y]));
            }
        }
        return q.top().v;
    }
};