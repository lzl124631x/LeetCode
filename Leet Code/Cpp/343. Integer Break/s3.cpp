// https://discuss.leetcode.com/topic/43042/easy-to-understand-c-with-explanation
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        if (n == 5) return 6;
        if (n == 6) return 9;
        return 3 * integerBreak(n - 3);
    }
};

// Another solution is
// class Solution {
// public:
//     int integerBreak(int n) {
//         if (n == 2) return 1;
//         if (n == 3) return 2;
//         if (n == 4) return 4;
//         return 3 * max(n - 3, integerBreak(n - 3));
//     }
// };
// How to omit `max`?
// 6 = 3 + 3 and f(3) = 2 so 6 needs `max`
// 7 = 3 + 4 and f(4) = 4 so 7 is the first number that doesn't need `max`

// https://discuss.leetcode.com/topic/43055/why-factor-2-or-3-the-math-behind-this-problem/11
// @StefanPochmann:
// If an optimal product contains a factor f >= 4,
// then you can replace it with factors 2 and f-2 without losing optimality,
// as 2*(f-2) = 2f-4 >= f. So you never need a factor greater than or equal to 4,
// meaning you only need factors 1, 2 and 3
// (and 1 is of course wasteful and you'd only use it for n=2 and n=3,
// where it's needed).

// 3*3 is simply better than 2*2*2, so you'd never use 2 more than twice.