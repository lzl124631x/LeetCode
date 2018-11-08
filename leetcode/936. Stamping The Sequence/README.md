# [936. Stamping The Sequence (Hard)](https://leetcode.com/problems/stamping-the-sequence/)

You want to form a `target` string of **lowercase letters**.

At the beginning, your sequence is `target.length` `'?'` marks.  You also have a `stamp` of lowercase letters.

On each turn, you may place the stamp over the sequence, and replace every letter in the sequence with the corresponding letter from the stamp.  You can make up to `10 * target.length` turns.

For example, if the initial sequence is "?????", and your stamp is `"abc"`,  then you may make "abc??", "?abc?", "??abc" in the first turn.  (Note that the stamp must be fully contained in the boundaries of the sequence in order to stamp.)

If the sequence is possible to stamp, then return an array of the index of the left-most letter being stamped at each turn.  If the sequence is not possible to stamp, return an empty array.

For example, if the sequence is "ababc", and the stamp is `"abc"`, then we could return the answer `[0, 2]`, corresponding to the moves "?????" -> "abc??" -> "ababc".

Also, if the sequence is possible to stamp, it is guaranteed it is possible to stamp within `10 * target.length` moves.  Any answers specifying more than this number of moves will not be accepted.

**Example 1:**

**Input:** stamp = "abc", target = "ababc"  
**Output:** \[0,2\]  
(\[1,0,2\] would also be accepted as an answer, as well as some other answers.)

**Example 2:**

**Input:** stamp = "abca", target = "aabcaca"  
**Output:** \[3,0,1\]  

**Note:**

1.  `1 <= stamp.length <= target.length <= 1000`
2.  `stamp` and `target` only contain lowercase letters.

## Solution 1.

From `target`, try to reverse the process. Find a sequence matching stamp, and erase the sequence with '?'. The problem is solvable if and only if we can finally get all '?'.

The matching rule:
1. '?' matches all characters
1. At least one non-'?' character should be in the sequence.

```cpp
// OJ: https://leetcode.com/problems/stamping-the-sequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
private:
    int findStamp(string &stamp, string &target) {
        for (int i = 0; i <= target.size() - stamp.size(); ++i) {
            int j = 0, cnt = 0;
            for (; j < stamp.size(); ++j) {
                if (target[i + j] == '?') continue;
                if (target[i + j] != stamp[j]) break;
                ++cnt;
            }
            if (cnt && j == stamp.size()) return i;
        }
        return -1;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int cnt = target.size();
        while (cnt) {
            int start = findStamp(stamp, target);
            if (start == -1) return {};
            ans.push_back(start);
            for (int i = 0; i < stamp.size(); ++i) {
                if (target[start + i] != '?') --cnt;
                target[start + i] = '?';
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```