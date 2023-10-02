# [293. Flip Game (Easy)](https://leetcode.com/problems/flip-game/)

<p>You are playing the following Flip Game with your friend: Given a string that contains only these two characters: <code>+</code> and <code>-</code>, you and your friend take turns to flip two <b>consecutive</b> <code>"++"</code> into <code>"--"</code>. The game ends when a person can no longer make a move and therefore the other person will be the winner.</p>

<p>Write a function to compute all possible states of the string after one valid move.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> <code>s = "++++"</code>
<strong>Output:</strong> 
[
  "--++",
  "+--+",
  "++--"
]
</pre>

<p><strong>Note: </strong>If there is no valid move, return an empty list <code>[]</code>.</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Flip Game II (Medium)](https://leetcode.com/problems/flip-game-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/flip-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 1, N = s.size(); i < N; ++i) {
            if (s[i] != '+' || s[i - 1] != '+') continue;
            ans.push_back(s);
            ans.back()[i] = ans.back()[i - 1] = '-';
        }
        return ans;
    }
};
```