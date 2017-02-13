class Solution {
private:
    bool jump(vector<int> &stones, vector<unordered_map<int, bool>> &memo, int start, int lastMove) {
        if (start == stones.size() - 1) return true;
        if (memo[start].count(lastMove)) return memo[start][lastMove];
        int next = start + 1;
        for (int d = -1; d <= 1; ++d) {
            int move = lastMove + d;
            while (next < stones.size() && stones[next] - stones[start] < move) ++next;
            if (next < stones.size() && stones[next] - stones[start] == move && jump(stones, memo, next, move)) {
                return memo[start][lastMove] = true;
            }
        }
        return memo[start][lastMove] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        vector<unordered_map<int, bool>> memo(stones.size());
        return jump(stones, memo, 1, 1);
    }
};