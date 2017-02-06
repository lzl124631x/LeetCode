// https://discuss.leetcode.com/topic/58042/c-1-line-solution-with-explanation
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};