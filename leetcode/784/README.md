# [784. Letter Case Permutation (Easy)](https://leetcode.com/problems/letter-case-permutation/)
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

**Examples:**  
**Input:** S = "a1b2"  
**Output:** \["a1b2", "a1B2", "A1b2", "A1B2"\]

**Input:** S = "3z4"  
**Output:** \["3z4", "3Z4"\]

**Input:** S = "12345"  
**Output:** \["12345"\]

**Note:**

*   `S` will be a string with length between `1` and `12`.
*   `S` will consist only of letters or digits.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/letter-case-permutation/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
private:
    vector<string> ans;
    void dfs(string &S, int i) {
        while (i < S.size() && !isalpha(S[i])) ++i;
        if (i == S.size()) {
            ans.push_back(S);
            return;
        }
        dfs(S, i + 1);
        S[i] += ('A' - 'a') * ((S[i] >= 'a' && S[i] <= 'z') ? 1 : -1);
        dfs(S, i + 1);
    }
public:
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0);
        return ans;
    }
};
```