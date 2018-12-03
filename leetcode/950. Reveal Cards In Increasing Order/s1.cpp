// OJ: https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int N = deck.size();
        vector<int> ans(N), movedTo;
        queue<int> q;
        for (int i = 0; i < N; ++i) q.push(i);
        while (q.size()) {
            int n = q.front();
            movedTo.push_back(n);
            q.pop();
            if (q.size()) {
                int m = q.front();
                q.pop();
                q.push(m);
            }
        }
        for (int i = 0; i < N; ++i) ans[movedTo[i]] = deck[i];
        return ans;
    }
};