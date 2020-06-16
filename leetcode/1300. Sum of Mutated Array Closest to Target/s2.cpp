// OJ: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
// Ref: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/discuss/463306/JavaC%2B%2BPython-Just-Sort-O(nlogn) 
class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(begin(A), end(A));
        int N = A.size(), i = 0;
        while (i < N && target > A[i] * (N - i)) target -= A[i++];
        return i == N ? A[N - 1] : round((target - 0.0001) / (N - i));
    }
};