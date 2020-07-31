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
// Time: O(NA) where A is the size of the alphabet
// Space: O(A)
class Solution {
public:
    string reorganizeString(string S) {
        int cnts[26] = {};
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

## Solution 2. Interleaving Placement

```cpp
// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/lzl124631x
// Time: O(AlogA + N) where A is the size of the alphabet 
// Space: O(A)
// Ref: https://leetcode.com/problems/reorganize-string/solution/
class Solution {
public:
    string reorganizeString(string S) {
        int N = S.size(), cnt[26] = {}, j = 1;
        for (char c : S) cnt[c - 'a'] += 100;
        for (int i = 0; i < 26; ++i) cnt[i] += i;
        sort(begin(cnt), end(cnt));
        string ans(N, ' ');
        for (int n : cnt) {
            int ct = n / 100, ch = n % 100;
            if (ct == 0) continue;
            if (ct > (N + 1) / 2) return "";
            while (ct--) {
                ans[j] = ch + 'a';
                j = (j + 2) % N;
                if (j == 1) j = 0;
            }
        }
        return ans;
    }
};
```

## Solution 3. Greedy + Heap

```cpp
// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/lzl124631x
// Time: O(A + NlogA) where A is the size of the alphabet
// Space: O(A)
class Solution {
public:
    string reorganizeString(string S) {
        int cnt[26] = {}, prev = -1;
        for (char c : S) cnt[c - 'a']++;
        auto cmp = [&](int a, int b) { return cnt[a] < cnt[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (int i = 0; i < 26; ++i) if (cnt[i]) q.push(i);
        string ans;
        while (q.size()) {
            int c = q.top();
            q.pop();
            ans.push_back('a' + c);
            if (prev != -1) q.push(prev);
            if (--cnt[c]) prev = c;
            else prev = -1;
        }
        if (prev != -1) return "";
        return ans;
    }
};
```