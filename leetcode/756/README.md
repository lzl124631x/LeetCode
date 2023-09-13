# [756. Pyramid Transition Matrix (Medium)](https://leetcode.com/problems/pyramid-transition-matrix/)

<p>We are stacking blocks to form a pyramid. Each block has a color which is a one letter string.</p>

<p>We are allowed to place any color block <code>C</code> on top of two adjacent blocks of colors <code>A</code> and <code>B</code>, if and only if <code>ABC</code> is an allowed triple.</p>

<p>We start with a bottom row of <code>bottom</code>, represented as a single string. We also start with a list of allowed triples <code>allowed</code>. Each allowed triple is represented as a string of length 3.</p>

<p>Return true if we can build the pyramid all the way to the top, otherwise false.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]
<b>Output:</b> true
<b>Explanation:</b>
We can stack the pyramid like this:
    A
   / \
  G   E
 / \ / \
B   C   D

We are allowed to place G on top of B and C because BCG is an allowed triple.  Similarly, we can place E on top of C and D, then A on top of G and E.</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]
<b>Output:</b> false
<b>Explanation:</b>
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>bottom</code> will be a string with length in range <code>[2, 8]</code>.</li>
	<li><code>allowed</code> will have length in range <code>[0, 200]</code>.</li>
	<li>Letters in all strings will be chosen from the set <code>{'A', 'B', 'C', 'D', 'E', 'F', 'G'}</code>.</li>
</ul>


**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/pyramid-transition-matrix/
// Author: github.com/lzl124631x
// Time: O(7^B)
// Space: O(A+7^B)
class Solution {
    vector<char> next[7][7] = {};
    vector<string> formNextLevel(string &bottom) {
        vector<string> ans{""};
        for (int i = 1; i < bottom.size(); ++i) {
            auto &n = next[bottom[i - 1] - 'A'][bottom[i] - 'A'];
            vector<string> v;
            for (char c : n) {
                for (auto &s : ans) {
                    if (s.empty() || next[s.back() - 'A'][c - 'A'].size()) v.push_back(s + c);
                }
            }
            swap(v, ans);
        }
        return ans;
    }
    bool dfs(string &bottom) {
        if (bottom.size() == 1) return true;
        for (auto &s : formNextLevel(bottom)) {
            if (dfs(s)) return true;
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) next[s[0] - 'A'][s[1] - 'A'].push_back(s[2]);
        return dfs(bottom);
    }
};
```