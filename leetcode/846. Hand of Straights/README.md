# [846. Hand of Straights (Medium)](https://leetcode.com/problems/hand-of-straights/)

<p>Alice has a <code>hand</code> of cards, given as an array of integers.</p>

<p>Now she wants to rearrange the cards into groups so that each group is size <code>W</code>, and consists of <code>W</code> consecutive cards.</p>

<p>Return <code>true</code> if and only if she can.</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>hand = [1,2,3,6,2,3,4,7,8], W = 3
<strong>Output: </strong>true
<strong>Explanation:</strong> Alice's <code>hand</code> can be rearranged as <code>[1,2,3],[2,3,4],[6,7,8]</code>.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>hand = [1,2,3,4,5], W = 4
<strong>Output: </strong>false
<strong>Explanation:</strong> Alice's <code>hand</code> can't be rearranged into groups of <code>4</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= hand.length &lt;= 10000</code></li>
	<li><code>0 &lt;= hand[i]&nbsp;&lt;= 10^9</code></li>
	<li><code>1 &lt;= W &lt;= hand.length</code></li>
</ul>
<strong>Note:</strong> This question is the same as&nbsp;1296:&nbsp;<a href="https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/">https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/</a>

**Related Topics**:  
[Ordered Map](https://leetcode.com/tag/ordered-map/)

## Solution 1. Multiset

```cpp
// OJ: https://leetcode.com/problems/hand-of-straights/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool isNStraightHand(vector<int>& A, int W) {
        multiset<int> s(begin(A), end(A));
        while (s.size()) {
            int n = *s.begin();
            s.erase(s.begin());
            for (int i = 1; i < W; ++i) {
                auto it = s.find(n + i);
                if (it == s.end()) return false;
                s.erase(it);
            }
        }
        return true;
    }
};
```

## Solution 2. Map

```cpp
// OJ: https://leetcode.com/problems/hand-of-straights/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool isNStraightHand(vector<int>& A, int W) {
        map<int, int> m;
        for (int n : A) m[n]++;
        while (m.size()) {
            int n = m.begin()->first;
            if (--m[n] == 0) m.erase(n);
            for (int i = 1; i < W; ++i) {
                if (m.count(n + i) == 0) return false;
                if (--m[n + i] == 0) m.erase(n + i);
            }
        }
        return true;
    }
};
```

One optimization is that we can delete multiple group at the same time.

```cpp
// OJ: https://leetcode.com/problems/hand-of-straights/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool isNStraightHand(vector<int>& A, int W) {
        map<int, int> m;
        for (int n : A) m[n]++;
        while (m.size()) {
            int n = m.begin()->first, cnt = m.begin()->second;
            m.erase(n);
            for (int i = 1; i < W; ++i) {
                if (m[n + i] < cnt) return false;
                if ((m[n + i] -= cnt) == 0) m.erase(n + i);
            }
        }
        return true;
    }
};
```