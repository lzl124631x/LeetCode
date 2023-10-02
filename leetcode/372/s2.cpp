// https://discuss.leetcode.com/topic/50430/c-ac-recursive-solution
class Solution {
private:
    int base = 1337;
    int myPow(int a, int b) {
        if (b == 0) return 1;
        if (b == 1) return a % base;
        long long ans = myPow(a, b / 2);
        return (ans * ans * (b % 2 ? a : 1)) % base;
    }
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int n : b) {
            ans = (myPow(ans, 10) * myPow(a, n)) % base;
        }
        return ans;
    }
};