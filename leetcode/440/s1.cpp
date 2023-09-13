// https://discuss.leetcode.com/topic/64624/concise-easy-to-understand-java-5ms-solution-with-explaination
class Solution {
private:
    int calcSteps(int n, long n1, long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += min((long)n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int i = 1;
        --k;
        while (k) {
            int steps = calcSteps(n, i, i + 1);
            if (steps <= k) {
                i += 1;
                k -= steps;
            } else {
                i *= 10;
                --k;
            }
        }
        return i;
    }
};