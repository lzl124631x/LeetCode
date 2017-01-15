class Solution {
private:
    int getSize(pair<int, int> cur, vector<int>& nums) {
        int curSize = cur.second - cur.first;
        if (cur.second < nums.size() || cur.first > 0) curSize++;
        return curSize;
    }
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size();) {
            while (i < nums.size() && nums[i] == 0) ++i;
            int start = i;
            while (i < nums.size() && nums[i] == 1) ++i;
            v.push_back(make_pair(start, i));
        }
        if (v.empty()) return 0;
        int maxCnt = getSize(v[0], nums);
        for (int i = 1; i < v.size(); ++i) {
            auto cur = v[i], prev = v[i - 1];
            maxCnt = max(maxCnt, getSize(cur, nums));
            if (prev.second + 1 == cur.first) {
                maxCnt = max(maxCnt, cur.second - cur.first + 1 + prev.second - prev.first);
            }
        }
        return maxCnt;
    }
};