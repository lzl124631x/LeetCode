# Segment Tree

* Used for solving range query problems like finding minimum, maximum, sum, greatest common divisor, least common denominator in array in logarithmic time
* Perfect binary tree

## Range Sum Query

[307. Range Sum Query - Mutable (Medium)](https://leetcode.com/problems/range-sum-query-mutable/)

1. Given `s` and `t`, return the sum from `A[s]` to `A[t]`.
1. Given `i` and `x`, change `A[i]` to `x`.

## Implementation

### Build Tree

```cpp
class NumArray {
    vector<int> tree;
    int N;
    void buildTree(vector<int> &nums) {
        for (int i = 0, j = N; i < N;) tree[j++] = nums[i++];
        for (int i = N - 1; i > 0; --i) tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        N = nums.size();
        tree = vector<int>(N * 2);
        buildTree(nums);
    }
    
    void update(int i, int val) {
        i += N;
        tree[i] = val;
        while (i > 0) {
            i /= 2;
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    int sumRange(int i, int j) {
        i += N;
        j += N;
        int sum = 0;
        while (i <= j) {
            if (i % 2) sum += tree[i++];
            if (j % 2 == 0) sum += tree[j--];
            i /= 2;
            j /= 2;
        }
        return sum;
    }
};
```

## Problems

* [307. Range Sum Query - Mutable (Medium)](https://leetcode.com/problems/range-sum-query-mutable/)

## Reference

* https://leetcode.com/problems/range-sum-query-mutable/solution/
* https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/