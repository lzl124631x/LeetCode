# [767. Reorganize String (Medium)](https://leetcode.com/problems/reorganize-string)

<p>Given a string <code>s</code>, rearrange the characters of <code>s</code> so that any two adjacent characters are not the same.</p>
<p>Return <em>any possible rearrangement of</em> <code>s</code> <em>or return</em> <code>""</code> <em>if not possible</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> "aba"
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "aaab"
<strong>Output:</strong> ""
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Pinterest](https://leetcode.com/company/pinterest), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Rearrange String k Distance Apart (Hard)](https://leetcode.com/problems/rearrange-string-k-distance-apart/)
* [Task Scheduler (Medium)](https://leetcode.com/problems/task-scheduler/)
* [Longest Happy String (Medium)](https://leetcode.com/problems/longest-happy-string/)

## Solution 1. Sequential Placing (Greedy)

We place the letters from left to right. We always pick the letter that has the maximum count and is not the previously placed letter.

```cpp
// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/lzl124631x
// Time: O(NA) where A is the size of the alphabet
// Space: O(A)
class Solution {
public:
    string reorganizeString(string s) {
        int cnt[26] = {}, mxCnt = 0;
        for (char c : s) mxCnt = max(mxCnt, ++cnt[c - 'a']);
        if (mxCnt > (s.size() + 1) / 2) return "";
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            int mxIndex = -1;
            for (int c = 0; c < 26; ++c) {
                if (cnt[c] == 0 || (ans.size() && ans.back() == 'a' + c) || (mxIndex != -1 && cnt[c] <= cnt[mxIndex])) continue;
                mxIndex = c;
            }
            cnt[mxIndex]--;
            ans.push_back('a' + mxIndex);
        }
        return ans;
    }
};
```

## Solution 2. Sequential Placing (Greedy + Heap)

Similar to solution 1, but instead of traversing all the letters, we use a priority queue to pick the one with the maximum count. 

Since we can't place the letter we just placed again, we store the letter we just placed in a temp variable `prev`, and push it back into the priority queue one round later.

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

## Solution 3. Interleaving Placement

We fill the even indices first, then the odd indices.

```cpp
// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/lzl124631x
// Time: O(AlogA + N) where A is the size of the alphabet 
// Space: O(A)
// Ref: https://leetcode.com/problems/reorganize-string/solution/
class Solution {
public:
    string reorganizeString(string s) {
        int N = s.size(), cnt[26] = {}, j = 0;
        for (char c : s) cnt[c - 'a'] += 100;
        for (int i = 0; i < 26; ++i) cnt[i] += i;
        sort(begin(cnt), end(cnt), greater<>());
        string ans(N, 0);
        for (int n : cnt) {
            int ct = n / 100, ch = n % 100;
            if (ct == 0) continue;
            if (ct > (N + 1) / 2) return "";
            while (ct--) {
                ans[j] = ch + 'a';
                j = (j + 2) % N;
                if (j == 0) j = 1;
            }
        }
        return ans;
    }
};
```

We don't even need to sort the `cnt` array. We just need to place the letter with the maximum count first, and then place the rest in any order.

```cpp
// OJ: https://leetcode.com/problems/reorganize-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(A)
class Solution {
public:
    string reorganizeString(string s) {
        int cnt[26] = {}, mxIndex = -1, N = s.size(), j = 0;
        for (char c : s) ++cnt[c - 'a'];
        for (int i = 0; i < 26; ++i) {
            if (mxIndex == -1 || cnt[i] > cnt[mxIndex]) mxIndex = i;
        }
        if (cnt[mxIndex] > (N + 1) / 2) return "";
        string ans(N, 0);
        // Place the most frequent letter
        while (cnt[mxIndex]--) {
            ans[j] = 'a' + mxIndex;
            j += 2;
        }
        // Place rest of the letters in any order
        for (int i = 0; i < 26; ++i) {
            while (cnt[i]-- > 0) {
                if (j >= N) j = 1;
                ans[j] = 'a' + i;
                j += 2;
            }
        }
        return ans;
    }
};
```

