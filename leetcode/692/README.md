# [692. Top K Frequent Words (Medium)](https://leetcode.com/problems/top-k-frequent-words/)

<p>Given a non-empty list of words, return the <i>k</i> most frequent elements.</p>
<p>Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> ["i", "love", "leetcode", "i", "love", "coding"], k = 2
<b>Output:</b> ["i", "love"]
<b>Explanation:</b> "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
<b>Output:</b> ["the", "is", "sunny", "day"]
<b>Explanation:</b> "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>You may assume <i>k</i> is always valid, 1 ≤ <i>k</i> ≤ number of unique elements.</li>
<li>Input words contain only lowercase letters.</li>
</ol>
<p></p>

<p><b>Follow up:</b><br>
</p><ol>
<li>Try to solve it in <i>O</i>(<i>n</i> log <i>k</i>) time and <i>O</i>(<i>n</i>) extra space.</li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Heap](https://leetcode.com/tag/heap/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [K Closest Points to Origin (Medium)](https://leetcode.com/problems/k-closest-points-to-origin/)
* [Sort Features by Popularity (Medium)](https://leetcode.com/problems/sort-features-by-popularity/)

## Solution 1. Heap

```cpp
// OJ: https://leetcode.com/problems/top-k-frequent-words/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(N)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& A, int k) {
        unordered_map<string, int> m;
        for (auto &s : A) m[s]++;
        auto cmp = [&](auto &a, auto &b) { return m[a] == m[b] ? a < b : m[a] > m[b]; };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        for (auto &[s, cnt] : m) {
            pq.push(s);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> ans;
        while (pq.size()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```

## TODO

Use quick select.

https://leetcode.com/problems/top-k-frequent-words/discuss/431008/Summary-of-all-the-methods-you-can-imagine-of-this-problem