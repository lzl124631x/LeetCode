# Count inversions in an array

In array `A`, two elements `A[i]` and `A[j]` form an inversion if `A[i] > A[j]` and `i < j`

_The count of inversion_ of an array indicates how far the array is from sorted. If the array is already sorted, its inversion count is 0. If the array is sorted in the reverse order then its inversion count is the maximum.

## Brute force

Brute force method is trivial -- for each number, count how many number to its right is smaller than it. The time complexit is `O(N^2)` and space complexity is `O(1)`.

## Merge Sort

```cpp
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