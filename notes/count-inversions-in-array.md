# Count inversions in an array

In array `A`, two elements `A[i]` and `A[j]` form an inversion if `A[i] > A[j]` and `i < j`

_The count of inversion_ of an array indicates how far the array is from sorted. If the array is already sorted, its inversion count is 0. If the array is sorted in the reverse order then its inversion count is the maximum.

## Brute force

Brute force method is trivial -- for each number, count how many number to its right is smaller than it. The time complexit is `O(N^2)` and space complexity is `O(1)`.

## Merge Sort

During the merge, if we need to select a number `x` from the right part, we can add the inversion count by the count of remaining items in the left part, because they must be all greater than `x`.

For example, assume we want to merge `[1,3]` and `[0,2]`.

* we need to first select the `0` and there are `2` numbers left in the left part, we add the count by `2`.
* select `1` from the left part, leave the count unchanged.
* select `2` from the right part, add the count by `1` because there is only one `3` left in the left part.
* select `3` from the left part, leave the count unchanged.

So in total there are `2 + 1 = 3` inversions.

```cpp
// Time: O(NlogN)
// Space: O(N)
long long _mergeSort(vector<int> &A, vector<int> &tmp, int start, int end) {
    if (start + 1 >= end) return 0;
    long long mid = (start + end) / 2, cnt = 0;
    cnt += _mergeSort(A, tmp, start, mid);
    cnt += _mergeSort(A, tmp, mid, end);
    for (int i = start, j = mid, k = 0; i < mid || j < end; ++k) {
        if (i >= mid || (j < end && A[j] < A[i])) {
            tmp[k] = A[j++];
            cnt += mid - i;
        } else tmp[k] = A[i++];
    }
    for (int i = start; i < end; ++i) A[i] = tmp[i - start];
    return cnt;
}
long long mergeSort(vector<int> &A, int start, int end) {
    vector<int> tmp(A.size());
    return _mergeSort(A, tmp, start, end);
}
long long countInversions(vector<int>& A) {
    return mergeSort(A, 0, A.size());
}
```