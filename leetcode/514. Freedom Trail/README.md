# [514. Freedom Trail (Hard)](https://leetcode.com/problems/freedom-trail/)

<p>In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.</p>

<p>Given a string <b>ring</b>, which represents the code engraved on the outer ring and another string <b>key</b>, which represents the keyword needs to be spelled. You need to find the <b>minimum</b> number of steps in order to spell all the characters in the keyword.</p>

<p>Initially, the first character of the <b>ring</b> is aligned at 12:00 direction. You need to spell all the characters in the string <b>key</b> one by one by rotating the ring clockwise or anticlockwise to make each character of the string <b>key</b> aligned at 12:00 direction and then by pressing the center button.</p>

<p>At the stage of rotating the ring to spell the key character <b>key[i]</b>:</p>

<ol>
	<li>You can rotate the <b>ring</b> clockwise or anticlockwise <b>one place</b>, which counts as 1 step. The final purpose of the rotation is to align one of the string <b>ring's</b> characters at the 12:00 direction, where this character must equal to the character <b>key[i]</b>.</li>
	<li>If the character <b>key[i]</b> has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.</li>
</ol>

<p><b>Example:</b></p>

<center><img src="https://assets.leetcode.com/uploads/2018/10/22/ring.jpg" style="width: 26%;"></center>
&nbsp;

<pre><b>Input:</b> ring = "godding", key = "gd"
<b>Output:</b> 4
<b>Explanation:</b>
For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
Also, we need 1 more step for spelling.
So the final output is 4.
</pre>

<p><b>Note:</b></p>

<ol>
	<li>Length of both ring and <b>key</b> will be in range 1 to 100.</li>
	<li>There are only lowercase letters in both strings and might be some duplcate characters in both strings.</li>
	<li>It's guaranteed that string <b>key</b> could always be spelled by rotating the string <b>ring</b>.</li>
</ol>


**Related Topics**:  
[Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/freedom-trail/
// Author: github.com/lzl124631x
// Time: O(N * M^2)
// Space: O(MN)
// Ref: https://leetcode.com/problems/freedom-trail/discuss/98902/Concise-Java-DP-Solution
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int M = ring.size(), N = key.size();
        vector<vector<int>> dp(N + 1, vector<int>(M));
        for (int i = N - 1; i >= 0; --i) {
            for (int j = 0; j < M; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < M; ++k) {
                    if (ring[k] != key[i]) continue;
                    int diff = abs(j - k);
                    int step = min(diff, M - diff);
                    dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
                }
            }
        }
        return dp[0][0] + N;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/freedom-trail/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    // d[0] clockwise, d[1] anticlockwise
    int d[100][26][2], dp[100][100] = {0};
    void buildDist(string &ring) {
        int idx[26] = {-1}, N = ring.size();
        for (int i = 0; i < N; ++i) idx[ring[i] - 'a'] = i;
        for (int i = 0; i < N; ++i) {
            idx[ring[i] - 'a'] = i;
            for (int j = 0; j < 26; ++j) d[i][j][1] = idx[j];
        }
        for (int i = N - 1; i >= 0; --i) idx[ring[i] - 'a'] = i;
        for (int i = N - 1; i >= 0; --i) {
            idx[ring[i] - 'a'] = i;
            for (int j = 0; j < 26; ++j) d[i][j][0] = idx[j];
        }
    }
    int lookUp(string &ring, string &key, int i, int j) {
        if (j == key.size()) return 0;
        if (dp[i][j] != 0) return dp[i][j];
        if (ring[i] == key[j]) return dp[i][j] = 1 + lookUp(ring, key, i, j + 1);
        int N = ring.size(), ans = INT_MAX;
        for (int t = 0; t < 2; ++t) {
            int to = d[i][key[j] - 'a'][t];
            int dst = (to - i) * (t == 0 ? 1 : -1) % N;
            if (dst < 0) dst += N;
            ans = min(ans, dst + 1 + lookUp(ring, key, to, j + 1));
        }
        return dp[i][j] = ans;
    }
public:
    int findRotateSteps(string ring, string key) {
        buildDist(ring);
        return lookUp(ring, key, 0, 0);
    }
};
```