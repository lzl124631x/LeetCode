# [358. Rearrange String k Distance Apart (Hard)](https://leetcode.com/problems/rearrange-string-k-distance-apart)

<p>Given a string <code>s</code> and an integer <code>k</code>, rearrange <code>s</code> such that the same characters are <strong>at least</strong> distance <code>k</code> from each other. If it is not possible to rearrange the string, return an empty string <code>""</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aabbcc", k = 3
<strong>Output:</strong> "abcabc"
<strong>Explanation:</strong> The same letters are at least a distance of 3 from each other.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "aaabc", k = 3
<strong>Output:</strong> ""
<strong>Explanation:</strong> It is not possible to rearrange the string.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "aaadbbcc", k = 2
<strong>Output:</strong> "abacabcd"
<strong>Explanation:</strong> The same letters are at least a distance of 2 from each other.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
</ul>

**Companies**:
[Twitter](https://leetcode.com/company/twitter), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Task Scheduler (Medium)](https://leetcode.com/problems/task-scheduler/)
* [Reorganize String (Medium)](https://leetcode.com/problems/reorganize-string/)
* [Construct String With Repeat Limit (Medium)](https://leetcode.com/problems/construct-string-with-repeat-limit/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/rearrange-string-k-distance-apart
// Author: github.com/lzl124631x
// Time: O(ND) where D is the size of character set
// Space: O(D)
class Solution {
public:
    string rearrangeString(string s, int k) {
        int freq[26] = {}, maxFreq = 0, maxFreqCnt = 0, prev[26] = {[0 ... 25] = -1};
        for (char c : s) maxFreq = max(maxFreq, ++freq[c - 'a']);
        for (int i = 0; i < 26; ++i) maxFreqCnt += freq[i] == maxFreq;
        int other = s.size() - maxFreqCnt * maxFreq, segment = maxFreq - 1, gap = segment * (k - maxFreqCnt);
        if (gap > other) return ""; 
        string ans; 
        for (int i = 0; i < s.size(); ++i) {
            int pick = -1;
            for (int j = 0; j < 26; ++j) {
                if ((prev[j] == -1 || i - prev[j] >= k) && freq[j] > 0 && (pick == -1 || freq[j] > freq[pick])) {
                    pick = j;
                }
            }
            prev[pick] = i;
            freq[pick]--;
            ans += 'a' + pick;
        }
        return ans;
    }
};
```

## Solution 2. Heap + Cooldown queue

```cpp
// OJ: https://leetcode.com/problems/rearrange-string-k-distance-apart
// Author: github.com/lzl124631x
// Time: O(NlogD)
// Space: O(D)
class Solution {
public:
    string rearrangeString(string s, int k) {
        int freq[26] = {}, maxFreq = 0, maxFreqCnt = 0;
        for (char c : s) maxFreq = max(maxFreq, ++freq[c - 'a']);
        for (int i = 0; i < 26; ++i) maxFreqCnt += freq[i] == maxFreq;
        int other = s.size() - maxFreqCnt * maxFreq, segment = maxFreq - 1, gap = segment * (k - maxFreqCnt);
        if (gap > other) return ""; 
        auto cmp = [&](int a, int b) { return freq[a] < freq[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); // a max heap of available characters
        queue<int> cd; // a cooldown queue with the index of the previous occurrence
        for (int i = 0; i < 26; ++i) {
            if (freq[i]) pq.push(i);
        }
        string ans; 
        for (int i = 0; i < s.size(); ++i) {
            if (cd.size() && cd.front() <= i - k) {
                pq.push(ans[cd.front()] - 'a');
                cd.pop();
            }
            int pick = pq.top();
            pq.pop();
            cd.push(i);
            freq[pick]--;
            ans += 'a' + pick;
        }
        return ans;
    }
};
```