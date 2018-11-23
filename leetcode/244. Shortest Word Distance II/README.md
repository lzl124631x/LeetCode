# [400. Nth Digit (Easy)](https://leetcode.com/problems/nth-digit/)

<p>Find the <i>n</i><sup>th</sup> digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... </p>

<p><b>Note:</b><br>
<i>n</i> is positive and will fit within the range of a 32-bit signed integer (<i>n</i> &lt; 2<sup>31</sup>).
</p>

<p><b>Example 1:</b>
</p><pre><b>Input:</b>
3

<b>Output:</b>
3
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre><b>Input:</b>
11

<b>Output:</b>
0

<b>Explanation:</b>
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
</pre>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shortest-word-distance-ii/
// Author: github.com/lzl124631x
// Time:
//     * WordDistance: O(N)
//     * shortest: O(N)
// Space: O(N)
class WordDistance {
private:
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }
    int shortest(string word1, string word2) {
        auto &a = m[word1], &b = m[word2];
        int i = 0, j = 0, dist = INT_MAX;
        while (i < a.size() && j < b.size() && dist > 1) {
            dist = min(dist, abs(a[i] - b[j]));
            if (a[i] > b[j]) ++j;
            else ++i;
        }
        return dist;
    }
};
```