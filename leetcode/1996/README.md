# [1996. The Number of Weak Characters in the Game (Medium)](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/)

<p>You are playing a game that contains multiple characters, and each of the characters has <strong>two</strong> main properties: <strong>attack</strong> and <strong>defense</strong>. You are given a 2D integer array <code>properties</code> where <code>properties[i] = [attack<sub>i</sub>, defense<sub>i</sub>]</code> represents the properties of the <code>i<sup>th</sup></code> character in the game.</p>

<p>A character is said to be <strong>weak</strong> if any other character has <strong>both</strong> attack and defense levels <strong>strictly greater</strong> than this character's attack and defense levels. More formally, a character <code>i</code> is said to be <strong>weak</strong> if there exists another character <code>j</code> where <code>attack<sub>j</sub> &gt; attack<sub>i</sub></code> and <code>defense<sub>j</sub> &gt; defense<sub>i</sub></code>.</p>

<p>Return <em>the number of <strong>weak</strong> characters</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> properties = [[5,5],[6,3],[3,6]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> No character has strictly greater attack and defense than the other.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> properties = [[2,2],[3,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The first character is weak because the second character has a strictly greater attack and defense.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> properties = [[1,5],[10,4],[4,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The third character is weak because the second character has a strictly greater attack and defense.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= properties.length &lt;= 10<sup>5</sup></code></li>
	<li><code>properties[i].length == 2</code></li>
	<li><code>1 &lt;= attack<sub>i</sub>, defense<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Russian Doll Envelopes (Hard)](https://leetcode.com/problems/russian-doll-envelopes/)
* [Maximum Height by Stacking Cuboids  (Hard)](https://leetcode.com/problems/maximum-height-by-stacking-cuboids/)

## Solution 1. Sorting

```cpp
// OJ: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[0] < b[0]; });
        multiset<int> s;
        for (auto &a : A) s.insert(a[1]);
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ) {
            vector<int> ds;
            int at = A[i][0];
            while (i < N && A[i][0] == at) {
                ds.push_back(A[i][1]);
                s.erase(s.find(A[i][1]));
                ++i;
            }
            for (int d : ds) {
                ans += s.upper_bound(d) != s.end();
            }
        }
        return ans;
    }
};
```

## Solution 2. LIS

Similar to [354. Russian Doll Envelopes (Hard)](https://leetcode.com/problems/russian-doll-envelopes/)

```cpp
// OJ: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1]; });
        vector<int> dp;
        int ans = 0;
        for (auto &c : A) {
            int i = lower_bound(begin(dp), end(dp), c[1], greater<>()) - begin(dp);
            if (i == dp.size()) dp.emplace_back();
            dp[i] = c[1];
            ans += i > 0;
        }
        return ans;
    }
};
```

## TODO

Use Bucket Sort. Work on `O(N)` solution.