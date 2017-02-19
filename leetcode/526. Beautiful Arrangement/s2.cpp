// https://discuss.leetcode.com/topic/79921/my-c-elegant-solution-with-back-tracking
class Solution {
private:
    int count(vector<int> &v, int N) {
        if (N <= 0) return 1;
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (v[i] % N == 0 || N % v[i] == 0) {
                swap(v[i], v[N - 1]);
                cnt += count(v, N - 1);
                swap(v[i], v[N - 1]);
            }
        }
        return cnt;
    }
public:
    int countArrangement(int N) {
        vector<int> v(N);
        for (int i = 0; i < N; ++i) v[i] = i + 1;
        return count(v, N);
    }
};