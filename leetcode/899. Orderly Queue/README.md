# [899. Orderly Queue (Hard)](https://leetcode.com/problems/orderly-queue/)

A string `S` of lowercase letters is given.  Then, we may make any number of _moves_.

In each move, we choose one of the first `K` letters (starting from the left), remove it, and place it at the end of the string.

Return the lexicographically smallest string we could have after any number of moves.

**Example 1:**

**Input:** S = "cba", K = 1  
**Output:** "acb"  
**Explanation:**   
In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".  
In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".

**Example 2:**

**Input:** S = "baaca", K = 3  
**Output:** "aaabc"  
**Explanation:**   
In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".  
In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".

**Note:**

1.  `1 <= K <= S.length <= 1000`
2.  `S` consists of lowercase letters only.

## Solution 1.

When `K >= 2`, we can in effect swap any two characters, which means we can do bubble sort. So the result for `K >= 2` is just the sorted `S`.

When `K == 1`, we need to rotate the string and find the minimum.

```cpp
// OJ: https://leetcode.com/problems/orderly-queue/
// Author: github.com/lzl124631x
// Time: O(S^2)
// Space: O(S)
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string ans = S;
        for (int i = 0; i < S.size(); ++i) {
            rotate(S.begin(), S.begin() + 1, S.end());
            if (S < ans) ans = S;
        }
        return ans;
    }
};
```