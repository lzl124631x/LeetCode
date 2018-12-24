// OJ: https://leetcode.com/problems/shopping-offers/
// Author: github.com/lzl124631x
// Time: O(NS) where N is length of `needs` and S is length of `special`.
// Space: O(NS)
class Solution {
private:
    int ans = INT_MAX;
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int index, int cost) {
        if (index == special.size()) {
            for (int i = 0; i < needs.size(); ++i) {
                cost += needs[i] * price[i];
            }
            ans = min(ans, cost);
            return;
        }
        bool done = true;
        for (int n : needs) {
            if (n) {
                done = false;
                break;
            }
        }
        if (done) {
            ans = min(ans, cost);
            return;
        }
        auto &offer = special[index];
        dfs(price, special, needs, index + 1, cost);
        for (int i = 0; true; ++i) {
            for (int j = 0; j < needs.size(); ++j) {
                needs[j] -= offer[j];
                if (needs[j] < 0) return;
            }
            dfs(price, special, needs, index + 1, cost += offer.back());
        }
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        dfs(price, special, needs, 0, 0);
        return ans;
    }
};