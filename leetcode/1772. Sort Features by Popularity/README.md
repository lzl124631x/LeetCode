# [1772. Sort Features by Popularity (Medium)](https://leetcode.com/problems/sort-features-by-popularity/)

<p>You are given a string array <code>features</code> where <code>features[i]</code> is a single word that represents the name of a feature of the latest product you are working on. You have made a survey where users have reported which features they like. You are given a string array <code>responses</code>, where each <code>responses[i]</code> is a string containing space-separated words.</p>

<p>The <strong>popularity</strong> of a feature is the number of <code>responses[i]</code> that contain the feature. You want to sort the features in non-increasing order by their popularity. If two features have the same popularity, order them by their original index in <code>features</code>. Notice that one response could contain the same feature multiple times; this feature is only counted once in its popularity.</p>

<p>Return <em>the features in sorted order.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> features = ["cooler","lock","touch"], responses = ["i like cooler cooler","lock touch cool","locker like touch"]
<strong>Output:</strong> ["touch","cooler","lock"]
<strong>Explanation:</strong> appearances("cooler") = 1, appearances("lock") = 1, appearances("touch") = 2. Since "cooler" and "lock" both had 1 appearance, "cooler" comes first because "cooler" came first in the features array.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> features = ["a","aa","b","c"], responses = ["a","a aa","a a a a a","b a"]
<strong>Output:</strong> ["a","aa","b","c"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= features.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= features[i].length &lt;= 10</code></li>
	<li><code>features</code> contains no duplicates.</li>
	<li><code>features[i]</code> consists of lowercase letters.</li>
	<li><code>1 &lt;= responses.length &lt;= 10<sup>2</sup></code></li>
	<li><code>1 &lt;= responses[i].length &lt;= 10<sup>3</sup></code></li>
	<li><code>responses[i]</code> consists of lowercase letters and spaces.</li>
	<li><code>responses[i]</code> contains no two consecutive spaces.</li>
	<li><code>responses[i]</code> has no leading or trailing spaces.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [Top K Frequent Words (Medium)](https://leetcode.com/problems/top-k-frequent-words/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sort-features-by-popularity/
// Author: github.com/lzl124631x
// Time: O(R + FlogF)
// Space: O(F)
class Solution {
public:
    vector<string> sortFeatures(vector<string>& F, vector<string>& R) {
        unordered_map<string, int> m, index;
        for (int i = 0; i < F.size(); ++i) index[F[i]] = i;
        for (auto &r : R) {
            stringstream ss(r);
            string word;
            unordered_set<string> seen;
            while (ss >> word) {
                if (index.count(word)) seen.insert(word);
            }
            for (auto &s : seen) m[s]++;
        }
        sort(begin(F), end(F), [&](auto &a, auto &b) { return m[a] != m[b] ? m[a] > m[b] : index[a] < index[b]; });
        return F;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/sort-features-by-popularity/
// Author: github.com/lzl124631x
// Time: O(R + FlogF)
// Space: O(F)
class Solution {
public:
    vector<string> sortFeatures(vector<string>& F, vector<string>& R) {
        unordered_map<string, int> m;
        for (int i = 0; i < F.size(); ++i) m[F[i]] = 0;
        for (auto &r : R) {
            stringstream ss(r);
            string word;
            unordered_set<string> seen;
            while (ss >> word) {
                if (m.count(word)) seen.insert(word);
            }
            for (auto &s : seen) m[s]++;
        }
        map<int, vector<string>, greater<>> rank;
        for (auto &f : F) rank[m[f]].push_back(f);
        vector<string> ans;
        for (auto &[r, fs] : rank) {
            for (auto &f : fs) ans.push_back(f);
        }
        return ans;
    }
};
```