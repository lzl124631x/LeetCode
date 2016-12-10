class Solution {
private:
    long long compute(vector<int> &A, int start) {
        long long sum = 0;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            sum += i * A[(i + start) % n];
        }
        return sum;
    }
    
    long long sum (vector<int> &A) {
        long long sum = 0;
        for (int i : A) {
            sum += i;
        }
        return sum;
    }
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0) return 0;
        long long m, last, s = sum(A);
        int n = A.size();
        m = last = compute(A, 0);
        for (int i = 1; i < n; ++i) {
            last = last + s - n * A[n - i];
            m = max(m, last);
        }
        return m;
    }
};