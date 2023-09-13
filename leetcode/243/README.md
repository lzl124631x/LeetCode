# [243. Shortest Word Distance (Easy)](https://leetcode.com/problems/shortest-word-distance/)

<p>Given a list of words and two words <em>word1</em> and <em>word2</em>, return the shortest distance between these two words in the list.</p>

<p><strong>Example:</strong><br>
Assume that words = <code>["practice", "makes", "perfect", "coding", "makes"]</code>.</p>

<pre><b>Input:</b> <em>word1</em> = <code>“coding”</code>, <em>word2</em> = <code>“practice”</code>
<b>Output:</b> 3
</pre>

<pre><b>Input:</b> <em>word1</em> = <code>"makes"</code>, <em>word2</em> = <code>"coding"</code>
<b>Output:</b> 1
</pre>

<p><strong>Note:</strong><br>
You may assume that <em>word1</em> <strong>does not equal to</strong> <em>word2</em>, and <em>word1</em> and <em>word2</em> are both in the list.</p>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Shortest Word Distance II (Medium)](https://leetcode.com/problems/shortest-word-distance-ii/)
* [Shortest Word Distance III (Medium)](https://leetcode.com/problems/shortest-word-distance-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shortest-word-distance/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int prev1 = -1, prev2 = -1, ans = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                if (prev2 != -1) ans = min(ans, i - prev2);
                prev1 = i;
            }
            if (words[i] == word2) {
                if (prev1 != -1) ans = min(ans, i - prev1);
                prev2 = i;
            }
        }
        return ans;
    }
};
```