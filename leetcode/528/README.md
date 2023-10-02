# [528. Random Pick with Weight (Medium)](https://leetcode.com/problems/random-pick-with-weight/)

Given an array `w` of positive integers, where `w[i]` describes the weight of index `i`, write a function `pickIndex` which randomly picks an index in proportion to its weight.

Note:

1.  `1 <= w.length <= 10000`
2.  `1 <= w[i] <= 10^5`
3.  `pickIndex` will be called at most `10000` times.

**Example 1:**

**Input:** \["Solution","pickIndex"\] \[\[\[1\]\],\[\]\]  
**Output:** \[null,0\]

**Example 2:**

**Input:** \["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"\] \[\[\[1,3\]\],\[\],\[\],\[\],\[\],\[\]\]  
**Output:** \[null,0,1,1,1,0\]

**Explanation of Input Syntax:**

The input is two lists: the subroutines called and their arguments. `Solution`'s constructor has one argument, the array `w`. `pickIndex` has no arguments. Arguments are always wrapped with a list, even if there aren't any.

## Solution 1. Naive

```cpp
// OJ: https://leetcode.com/problems/random-pick-with-weight/
// Author: github.com/lzl124631x
// Time: O(W) for both APIs
// Space: O(W)
class Solution {
private:
    int sum;
    vector<int> w;
public:
    Solution(vector<int> w): w(w) {
        srand (time(NULL));
        sum = accumulate(w.begin(), w.end(), 0);
    }
    
    int pickIndex() {
        int r = rand() % sum;
        for (int i = 0; i < w.size(); ++i) {
            r -= w[i];
            if (r < 0) return i;
        }
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/random-pick-with-weight/
// Author: github.com/lzl124631x
// Time:
//      Solution: O(W)
//      pickIndex: O(log(W))
// Space: O(W)
class Solution {
private:
    vector<int> bounds;
public:
    Solution(vector<int> w) {
        srand (time(NULL));
        int sum = 0;
        for (int i : w) bounds.push_back(sum += i);
    }
    
    int pickIndex() {
        int r = 1 + (rand() % bounds.back());
        int L = 0, R = bounds.size();
        while (L < R) {
            int M = (L + R) / 2;
            if (bounds[M] < r) L = M + 1;
            else R = M;
        }
        return L;
    }
};
```
## Solution 3. Binary Search with STL.

```cpp
// OJ: https://leetcode.com/problems/random-pick-with-weight/
// Author: github.com/lzl124631x
// Time:
//      Solution: O(W)
//      pickIndex: O(log(W))
// Space: O(W)
class Solution {
private:
    vector<int> sums;
public:
    Solution(vector<int> w): sums(w) {
        partial_sum(sums.begin(), sums.end(), sums.begin());
    }
    
    int pickIndex() {
        return upper_bound(sums.begin(), sums.end(), rand() % sums.back()) - sums.begin();
    }
};
```