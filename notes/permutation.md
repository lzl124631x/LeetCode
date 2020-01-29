# Permutation

## Next Permutation

[31. Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)

Given a permutation, get the next permutation.

Example:

* given `[2,1,3]`, the next permutation is `[2,3,1]`.
* given `[1,2,1]`, the next permutation is `[2,1,1]`.

```cpp
/**
 * Returns true if the input `nums` is already the maximum in lexicographical order.
 */
bool nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2, j = nums.size() - 1;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i >= 0) {
        while (j > i && nums[j] <= nums[i]) --j;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
    return i >= 0;
}
```

The first section

```cpp
int i = nums.size() - 2;
while (i >= 0 && nums[i] >= nums[i + 1]) --i;
```

is looking for the last element in front of the descending subarray.

For example, `nums = [2,1,4,3]`, then `i` will point to `1` which is the last element in front of the descending subarray `[4, 3]`.

If not found, it means that the whole array is descending. The next permutation will be the reverse of the input array.

If found, we can swap it with the smallest element greater than itself, which is covered in the `if` condition.

```cpp
if (i >= 0) {
    while (j > i && nums[j] <= nums[i]) --j;
    swap(nums[i], nums[j]);
}
```
And to get the next permutation, we need to reverse the subarray starting from `nums[i + 1]` to the end.

For example, `nums = [1,6,3,5,4,2]`, then `i = 2` pointing to `3` and `j = 4` pointing to `4`. We swap `nums[i]` and `nums[j]` so swapping them gives `[1,6,4,5,3,2]`, then reverse the subarray starting from `2` to the end, getting `[1,6,4,2,3,5]`.

## Problems

* [46. Permutations (Medium)](https://leetcode.com/problems/permutations/submissions/)
* [31. Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)
* [47. Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)