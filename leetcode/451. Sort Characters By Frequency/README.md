# [451. Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)

<p>Given a string, sort it in decreasing order based on the frequency of characters.</p>

<p><b>Example 1:</b>
</p><pre><b>Input:</b>
"tree"

<b>Output:</b>
"eert"

<b>Explanation:</b>
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre><b>Input:</b>
"cccaaa"

<b>Output:</b>
"cccaaa"

<b>Explanation:</b>
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
</pre>
<p></p>

<p><b>Example 3:</b>
</p><pre><b>Input:</b>
"Aabb"

<b>Output:</b>
"bbAa"

<b>Explanation:</b>
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
</pre>
<p></p>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Heap](https://leetcode.com/tag/heap/)

**Similar Questions**:
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [First Unique Character in a String (Easy)](https://leetcode.com/problems/first-unique-character-in-a-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sort-characters-by-frequency/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    string frequencySort(string s) {
        int cnt[256] = {};
        for (char c : s) cnt[c]++;
        sort(s.begin(), s.end(), [&](char a, char b) {
            return cnt[a] == cnt[b] ? a > b : cnt[a] > cnt[b];
        });
        return s;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/sort-characters-by-frequency/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string frequencySort(string s) {
        vector<char> v;
        int cnt[256] = {};
        for (char c : s) {
            if (cnt[c]++ == 0) v.push_back(c);
        }
        sort(v.begin(), v.end(), [&](char a, char b) { return cnt[a] > cnt[b]; });
        string ans;
        for (char c : v) {
            for (int i = 0; i < cnt[c]; ++i) ans.push_back(c);
        }
        return ans;
    }
};
```