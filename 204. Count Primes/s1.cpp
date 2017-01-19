// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if (!n) return 0;
        vector<bool> isPrime(n, true);
        int cnt = 0, bound = sqrt(n);
        for (int i = 2; i < n; ++i) {
            if (!isPrime[i]) continue;
            ++cnt;
            if (i > bound) continue;
            for (int j = i * i; j < n; j += i) isPrime[j] = false;
        }
        return cnt;
    }
};