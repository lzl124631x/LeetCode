# [869. Reordered Power of 2 (Medium)](https://leetcode.com/problems/reordered-power-of-2/)

Starting with a positive integer `N`, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return `true` if and only if we can do this in a way such that the resulting number is a power of 2.

**Example 1:**

**Input:** 1  
**Output:** true

**Example 2:**

**Input:** 10  
**Output:** false

**Example 3:**

**Input:** 16  
**Output:** true

**Example 4:**

**Input:** 24  
**Output:** false

**Example 5:**

**Input:** 46  
**Output:** true

**Note:**

1.  `1 <= N <= 10^9`

## Solution 1. Permutations

Traverse all the permutations of N, and examine each of them whether it is power of 2.

```cpp
// OJ: https://leetcode.com/problems/reordered-power-of-2/
// Author: github.com/lzl124631x
// Time: O(lg(N)!)
// Space: O(lg(N))
class Solution {
private:
    bool isPow2(long long N) {
        return (N & (N - 1)) == 0;
    }
    string num;
    bool dfs(int start) {
        if (start == num.size()) return isPow2(stoll(num));
        for (int i = start; i < num.size(); ++i) {
            if (num[i] == '0' && start == 0) continue;
            swap(num[start], num[i]);
            if (dfs(start + 1)) return true;
            swap(num[start], num[i]);
            while (i + 1 < num.size() && num[i] == num[i + 1]) ++i;
        }
        return false;
    }
public:
    bool reorderedPowerOf2(int N) {
        while (N) {
            num.push_back('0' + (N % 10));
            N /= 10;
        }
        sort(num.begin(), num.end(), greater<char>());
        return dfs(0);
    }
};
```

## Solution 2. Counting

There are only 32 possible powers of 2. Count the digits of `N` and compare the counts with those of a power of 2.

```cpp
// OJ: https://leetcode.com/problems/reordered-power-of-2/
// Author: github.com/lzl124631x
// Time: O(lg(N))
//     where lg(N) is number of digits in N base-10.
//     There are just 32 possible powers of 2. The comparison is O(lg(N)).
// Space: O(lg(N))
class Solution {
private:
    array<int, 10> count(int N) {
        array<int, 10> cnt = {};
        while (N) {
            cnt[N % 10]++;
            N /= 10;
        }
        return cnt;
    }
public:
    bool reorderedPowerOf2(int N) {
        auto cnt = count(N);
        for (int i = 0; i < 31; ++i) {
            auto c = count(1 << i);
            if (cnt == c) return true;
        }
        return false;
    }
};
```