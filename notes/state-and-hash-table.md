# State and Hash Table

Let hash table `m` be a map from the state `x` to the index of the first occurrence of the state `x`.

For a given index `i`, assume its state is `x`, then `i - m[x]` is the optimal solution for subarray `0 ~ i`.

## Problems

* [525. Contiguous Array (Medium)](https://leetcode.com/problems/contiguous-array/)
* [1371. Find the Longest Substring Containing Vowels in Even Counts (Medium)](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)