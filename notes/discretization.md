# Discretization

When the number range is very large and the numbers are very sparse, we can discretize the input numbers so that we can keep the ordering of the numbers while saving them in a much smaller array.

For example, the input array is:

```
-10000, 0, 10000
```

If we need to create an array covering the range we need to create one with length 20001, but actually there are just 3 numbers in it.

We can turn it into

```
0, 1, 2
```

with the following mapping

```
-10000 -> 0
0      -> 1
10000  -> 2
```

## Implementation

```cpp
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
vector<int> discretize(vector<int> &input) {
    set<int> s(input.begin(), input.end()); // In this way, we dedupe the data and sort them
    unordered_map<int, int> m; // mapping from old number to new number
    int id = 0;
    for (int n : s) m[n] = id++;
    vector<int> output(input.size());
    for (int i = 0; i < input.size(); ++i) output[i] = m[input[i]];
    return output;
}
```

## Problem

* [699. Falling Squares (Hard)](https://leetcode.com/problems/falling-squares/