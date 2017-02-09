struct CapCmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.first > b.first;
    }
};
struct ProCmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, CapCmp> cap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, ProCmp> pro;
        for (int i = 0; i < Profits.size(); ++i) cap.push({ Capital[i], Profits[i] });
        while (k--) {
            while (cap.size() && cap.top().first <= W) {
                pro.push(cap.top());
                cap.pop();
            }
            if (pro.empty()) return W;
            W += pro.top().second;
            pro.pop();
        }
        return W;
    }
};