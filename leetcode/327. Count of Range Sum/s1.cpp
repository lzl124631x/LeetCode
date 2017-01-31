class Solution {
private:
    int countMergeSort(vector<long long> &sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = (start + end) / 2;
        int count = countMergeSort(sums, start, mid, lower, upper)
                    + countMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid, r = 0;
        vector<long long> cache(end - start, 0);
        for (int i = start; i < mid; ++i, ++r) {
            while (k < end && sums[k] - sums[i] < lower) ++k;
            while (j < end && sums[j] - sums[i] <= upper) ++j;
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r] = sums[i];
            count += j - k;
        }
        for (int i = 0; i < r; ++i) sums[start + i] = cache[i];
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int N = nums.size();
        vector<long long> sums(N + 1, 0);
        for (int i = 0; i < N; ++i) sums[i + 1] = sums[i] + nums[i];
        return countMergeSort(sums, 0, N + 1, lower, upper);
    }
};