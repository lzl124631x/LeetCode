class Solution {
private:
    bool validSuffix(vector<int> &data, int &i, int cnt) {
        while (cnt && i < data.size() && (data[i] >> 6) == 2) ++i, --cnt;
        return cnt == 0;
    }
public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size(); ) {
            int n = data[i++];
            if (n >> 7 == 0) {
                // noop
            } else if (n >> 5 == 6) {
                if (!validSuffix(data, i, 1)) return false;
            } else if (n >> 4 == 14) {
                if (!validSuffix(data, i, 2)) return false;
            } else if (n >> 3 == 30) {
                if (!validSuffix(data, i, 3)) return false;
            } else return false;
        }
        return true;
    }
};