class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> f, g;
        vector<double> ret;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (i >= k) {
                int rm = nums[i - k];
                if (f.find(rm) != f.end()) {
                    f.erase(f.find(rm));
                } else {
                    g.erase(g.find(rm));
                }
            }
            if (!g.empty() && *g.begin() <= x) {
                g.insert(x);
            } else {
                f.insert(x);
            }
            while (f.size() > g.size() + 1) {
                auto it = prev(f.end());
                f.erase(it);
                g.insert(*it);
            }
            while (g.size() > f.size()) {
                auto it = g.begin();
                g.erase(it);
                f.insert(*it);
            }
            if (i >= k - 1) {
                if (k % 2) {
                    ret.push_back(*f.rbegin());
                } else {
                    ret.push_back(.5 * ((long long)*f.rbegin() + *g.begin()));
                }
            }
        }
        return ret;
    }
};