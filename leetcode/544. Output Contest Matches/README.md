# [544. Output Contest Matches (Medium)](https://leetcode.com/problems/output-contest-matches/)

<p>
During the NBA playoffs, we always arrange the rather strong team to play with the rather weak team, like make the rank 1 team play with the rank n<sub>th</sub> team, which is a good strategy to make the contest more interesting. Now, you're given <b>n</b> teams, you need to output their <b>final</b> contest matches in the form of a string.
</p>

<p>The <b>n</b> teams are given in the form of positive integers from 1 to n, which represents their initial rank. (Rank 1 is the strongest team and Rank n is the weakest team.) We'll use parentheses('(', ')') and commas(',') to represent the contest team pairing - parentheses('(' , ')') for pairing and commas(',') for partition. During the pairing process in each round, you always need to follow the strategy of making the rather strong one pair with the rather weak one.</p> 

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 2
<b>Output:</b> (1,2)
<b>Explanation:</b> 
Initially, we have the team 1 and the team 2, placed like: 1,2.
Then we pair the team (1,2) together with '(', ')' and ',', which is the final answer.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 4
<b>Output:</b> ((1,4),(2,3))
<b>Explanation:</b> 
In the first round, we pair the team 1 and 4, the team 2 and 3 together, as we need to make the strong team and weak team together.
And we got (1,4),(2,3).
In the second round, the winners of (1,4) and (2,3) need to play again to generate the final winner, so you need to add the paratheses outside them.
And we got the final answer ((1,4),(2,3)).
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> 8
<b>Output:</b> (((1,8),(4,5)),((2,7),(3,6)))
<b>Explanation:</b> 
First round: (1,8),(2,7),(3,6),(4,5)
Second round: ((1,8),(4,5)),((2,7),(3,6))
Third round: (((1,8),(4,5)),((2,7),(3,6)))
Since the third round will generate the final winner, you need to output the answer (((1,8),(4,5)),((2,7),(3,6))).
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The <b>n</b> is in range [2, 2<sup>12</sup>].</li>
<li>We ensure that the input <b>n</b> can be converted into the form 2<sup>k</sup>, where k is a positive integer.</li>
</ol>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/output-contest-matches/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = to_string(1 + i);
        while (n != 1) {
            for (int i = 0, j = 0; i < n / 2; ++i) {
                ans[j++] = "(" + ans[i] + "," + ans[n - i - 1] + ")";
            }
            n /= 2;
        }
        return ans[0];
    }
};
```