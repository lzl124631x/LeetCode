# [127. Word Ladder (Hard)](https://leetcode.com/problems/word-ladder/)

<p>Given two words <code>beginWord</code> and <code>endWord</code>, and a dictionary <code>wordList</code>, return <em>the length of the shortest transformation sequence from</em> <code>beginWord</code> <em>to</em> <code>endWord</code>, <em>such that</em>:</p>

<ul>
	<li>Only one letter can be changed at a time.</li>
	<li>Each transformed word must exist in the word list.</li>
</ul>

<p>Return <code>0</code> if there is no such transformation sequence.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
<strong>Output:</strong> 5
<strong>Explanation:</strong> As one shortest transformation is "hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; "cog", return its length 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The endWord "cog" is not in wordList, therefore no possible transformation.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;beginWord.length &lt;= 100</code></li>
	<li><code>endWord.length == beginWord.length</code></li>
	<li><code>1 &lt;= wordList.length &lt;= 5000</code></li>
	<li><code>wordList[i].length ==&nbsp;beginWord.length</code></li>
	<li><code>beginWord</code>,&nbsp;<code>endWord</code>, and&nbsp;<code>wordList[i]</code> consist of lowercase English letters.</li>
	<li><code>beginWord !=&nbsp;endWord</code></li>
	<li>All the strings in&nbsp;<code>wordList</code> are <strong>unique</strong>.</li>
</ul>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Word Ladder II (Hard)](https://leetcode.com/problems/word-ladder-ii/)
* [Minimum Genetic Mutation (Medium)](https://leetcode.com/problems/minimum-genetic-mutation/)

## Solution 1. BFS

Since we are looking for the shortest path, BFS should be our first option.

Given a word `w`, we can try to change each `w[i]` to a character from `'a'` to `'z'`.

Once we found a neighbor word `v`, we remove `v` from the word list and push it to the queue.

### Time Complexity

In the worst case we need to visit all the `N` words in `A`. For each word, we check all its `26W` neighbors, and copy them to `queue` (the copying takes `O(W)` time), so `addNeighbors` takes `O(W^2)` time.

Thus, overall it takes `O(N * W^2)` time

```cpp
// OJ: https://leetcode.com/problems/word-ladder/
// Author: github.com/lzl124631x
// Time: O(N * W^2)
// Space: O(NW)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(begin(wordList), end(wordList));
        if (s.count(endWord) == 0) return 0;
        queue<string> q{{beginWord}};
        s.erase(beginWord);
        int step = 1;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto u = q.front();
                q.pop();
                if (u == endWord) return step;
                for (char &c : u) { // add unvisited neighbors of `u`
                    char tmp = c;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (tmp == ch) continue;
                        c = ch;
                        if (s.count(u) == 0) continue;
                        s.erase(u);
                        q.push(u);
                    }
                    c = tmp;
                }
            }
            ++step;
        }
        return 0;
    }
};
```

## Solution 2. Bi-directional BFS

```cpp
// OJ: https://leetcode.com/problems/word-ladder/
// Author: github.com/lzl124631x
// Time: O(N * W^2)
// Space: O(NW)
class Solution {
public:
    int ladderLength(string B, string E, vector<string>& A) {
        unordered_set<string> head, tail, s(begin(A), end(A));
        if (s.count(E) == 0) return 0;
        head.insert(B);
        tail.insert(E);
        s.erase(B);
        s.erase(E);
        int ans = 2;
        while (head.size() && tail.size()) {
            if (head.size() > tail.size()) swap(head, tail);
            unordered_set<string> next;
            for (auto w : head) {
                for (char &c : w) {
                    char tmp = c;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        c = ch;
                        if (tail.count(w)) return ans;
                        if (s.count(w) == 0) continue;
                        next.insert(w);
                        s.erase(w);
                    }
                    c = tmp;
                }
            }
            ++ans;
            swap(head, next);
        }
        return 0;
    }
};
```