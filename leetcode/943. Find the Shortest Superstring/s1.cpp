class Solution {
private:
    int countDup(string &a, string &b) {
        for (int len = min(a.size(), b.size()); len >= 0; --len) {
            if (a.compare(a.size() - len, len, b)) return len;
        }
    }
public:
    string shortestSuperstring(vector<string>& A) {
        unordered_map<int, unordered_map<int, int>> m;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                m[i][j] = countDup(A[i], A[j]);
                m[j][i] = countDup(A[j], A[i]);
            }
        }
        
        return "";
    }
};