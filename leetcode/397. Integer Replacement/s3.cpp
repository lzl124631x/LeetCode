// https://discuss.leetcode.com/topic/58425/java-12-line-4-5-ms-iterative-solution-with-explanations-no-other-data-structures
class Solution {
private:
    int helper(long long n) {
        int c = 0;
        while (n != 1) {
            if (n % 2 == 0) n >>= 1;
            else if ((n + 1) % 4 != 0 || n == 3) --n;
            else ++n;
            ++c;
        }
        return c;
    }
public:
    int integerReplacement(int n) {
        return helper(n);
    }
};