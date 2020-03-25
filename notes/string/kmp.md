# KMP Algorithm

KMP (Knuth-Morris-Pratt) algorithm is a substring search algorithm.

LPS: Longest proper Prefix which is also Suffix.

## Algorithm

1. Generate the LPS array.
2. Take advantage of the LPS array so that once we find a mismatch, we can efficiently jump to an earlier point and continue searching.

## Implementation

```cpp
// OJ: https://leetcode.com/problems/implement-strstr/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(N)
class Solution {
    vector<int> prefix(string &s) {
        int N = s.size();
        vector<int> pi(N);
        for (int i = 1; i < N; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) ++j;
            pi[i] = j;
        }
        return pi;
    }
public:
    int strStr(string s, string t) {
        if (t.empty()) return 0;
        int M = s.size(), N = t.size(), i = 0, j = 0;
        auto pi = prefix(t);
        while (i < M) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            }
            if (j == N) return i - j;
            if (i < M && s[i] != t[j]) {
                if (j) j = pi[j - 1];
                else ++i;
            }
        }
        return -1;
    }
};
```

## Reference

* https://youtu.be/GTJr8OvyEVQ
* https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/