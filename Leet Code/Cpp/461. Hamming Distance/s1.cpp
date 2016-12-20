class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y, dist = 0;
        while (z) {
            z &= z - 1;
            ++dist;
        }
        return dist;
    }
};