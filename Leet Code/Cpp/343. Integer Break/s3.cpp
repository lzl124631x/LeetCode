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