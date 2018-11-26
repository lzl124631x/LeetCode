# [767. Reorganize String (Medium)](https://leetcode.com/problems/reorganize-string/)

<p>Given a string <code>S</code>, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.</p>

<p>If possible, output any possible result.&nbsp; If not possible, return the empty string.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> S = "aab"
<strong>Output:</strong> "aba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> S = "aaab"
<strong>Output:</strong> ""
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>S</code> will consist of lowercase letters and have length in range <code>[1, 500]</code>.</li>
</ul>

<p>&nbsp;</p>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Twitter](https://leetcode.com/company/twitter)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Heap](https://leetcode.com/tag/heap/), [Greedy](https://leetcode.com/tag/greedy/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Rearrange String k Distance Apart (Hard)](https://leetcode.com/problems/rearrange-string-k-distance-apart/)
* [Task Scheduler (Medium)](https://leetcode.com/problems/task-scheduler/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reorganizeString(string S) {
        int cnts[26] = {0};
        for (char c : S) cnts[c - 'a']++;
        string ans(S.size(), '\0');
        for (int i = 0; i < S.size(); ++i) {
            int maxIndex = -1;
            for (int j = 0; j < 26; ++j) {
                if (!cnts[j] || (i > 0 && ans[i - 1] == j + 'a')) continue;
                if (maxIndex == -1 || cnts[j] > cnts[maxIndex]) maxIndex = j;
            }
            if (maxIndex == -1) return "";
            cnts[maxIndex]--;
            ans[i] = maxIndex + 'a';
        }
        return ans;
    }
};
```