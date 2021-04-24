# [822. Card Flipping Game (Medium)](https://leetcode.com/problems/card-flipping-game/)

<p>On a table are <code>N</code> cards, with a positive integer printed on the front and back of each card (possibly different).</p>

<p>We flip any number of cards, and after we choose one&nbsp;card.&nbsp;</p>

<p>If the number <code>X</code> on the back of the chosen&nbsp;card is not on the front of any card, then this number X is good.</p>

<p>What is the smallest number that is good?&nbsp; If no number is good, output <code>0</code>.</p>

<p>Here, <code>fronts[i]</code> and <code>backs[i]</code> represent the number on the front and back of card <code>i</code>.&nbsp;</p>

<p>A&nbsp;flip swaps the front and back numbers, so the value on the front is now on the back and vice versa.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
<strong>Output:</strong> <code>2</code>
<strong>Explanation:</strong> If we flip the second card, the fronts are <code>[1,3,4,4,7]</code> and the backs are <code>[1,2,4,1,3]</code>.
We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so <code>2</code> is good.</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= fronts.length == backs.length&nbsp;&lt;=&nbsp;1000</code>.</li>
	<li><code>1 &lt;=&nbsp;fronts[i]&nbsp;&lt;= 2000</code>.</li>
	<li><code>1 &lt;= backs[i]&nbsp;&lt;= 2000</code>.</li>
</ol>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/card-flipping-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int flipgame(vector<int>& F, vector<int>& B) {
        unordered_set<int> same;
        int N = F.size(), mn = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (F[i] == B[i]) same.insert(F[i]);
        }
        for (int i = 0; i < N; ++i) {
            if (same.count(F[i]) == 0) mn = min(mn, F[i]);
            if (same.count(B[i]) == 0) mn = min(mn, B[i]);
        }
        return mn == INT_MAX ? 0 : mn;
    }
};
```