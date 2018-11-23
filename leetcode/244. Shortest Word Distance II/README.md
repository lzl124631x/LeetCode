# [244. Shortest Word Distance II (Medium)](https://leetcode.com/problems/shortest-word-distance-ii/)

<p>Design a class which receives a list of words in the constructor, and implements a method that takes two words <em>word1</em> and <em>word2</em> and return the shortest distance between these two words in the list. Your method will be called <em>repeatedly</em> many times with different parameters.&nbsp;</p>

<p><strong>Example:</strong><br>
Assume that words = <code>["practice", "makes", "perfect", "coding", "makes"]</code>.</p>

<pre><b>Input:</b> <em>word1</em> = <code>“coding”</code>, <em>word2</em> = <code>“practice”</code>
<b>Output:</b> 3
</pre>

<pre><b>Input:</b> <em>word1</em> = <code>"makes"</code>, <em>word2</em> = <code>"coding"</code>
<b>Output:</b> 1</pre>

<p><strong>Note:</strong><br>
You may assume that <em>word1</em> <strong>does not equal to</strong> <em>word2</em>, and <em>word1</em> and <em>word2</em> are both in the list.</p>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Merge Two Sorted Lists (Easy)](https://leetcode.com/problems/merge-two-sorted-lists/)
* [Shortest Word Distance (Easy)](https://leetcode.com/problems/shortest-word-distance/)
* [Shortest Word Distance III (Medium)](https://leetcode.com/problems/shortest-word-distance-iii/)

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