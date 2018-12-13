// OJ: https://leetcode.com/problems/asteroid-collision/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (auto n : asteroids) {
            int absn = abs(n);
            bool alive = true;
            while (ans.size()) {
                int m = ans.back(), absm = abs(m);
                if (m * n > 0 || (m < 0 && n > 0)) break;
                else if (absm == absn) {
                    ans.pop_back();
                    alive = false;
                    break;
                } else if (absm > absn) {
                    alive = false;
                    break;
                } else ans.pop_back();
            }
            if (alive) ans.push_back(n);
        }
        return ans;
    }
};