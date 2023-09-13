// OJ: https://leetcode.com/problems/random-flip-matrix/
// Author: github.com/lzl124631x
// Time:
//   Solution: O(1)
//   flip: O(1)
//   reset: O(MN) in worst case
// Space: O(MN) in worst case
// Ref: https://leetcode.com/problems/random-flip-matrix/solution/
class Solution {
private:
    unordered_map<int, int> m;
    int size, M, N;
    //c++11 random integer generation
    mt19937 rng{random_device{}()};
    //uniform random integer in [0, bound]
    int randint(int bound) {
        uniform_int_distribution<int> uni(0, bound);
        return uni(rng);
    }
public:
    Solution(int M, int N): M(M), N(N), size(M * N) {}
    
    vector<int> flip() {
        int r = randint(--size);
        int x = m.count(r) ? m[r] : r;
        m[r] = m.count(size) ? m[size] : size;
        return { x / N, x % N };
    }
    
    void reset() {
        m.clear();
        size = M * N;
    }
};