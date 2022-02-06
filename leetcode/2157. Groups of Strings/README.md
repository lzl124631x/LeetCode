# [2157. Groups of Strings (Hard)](https://leetcode.com/problems/groups-of-strings/)

<p>You are given a <strong>0-indexed</strong> array of strings <code>words</code>. Each string consists of <strong>lowercase English letters</strong> only. No letter occurs more than once in any string of <code>words</code>.</p>

<p>Two strings <code>s1</code> and <code>s2</code> are said to be <strong>connected</strong> if the set of letters of <code>s2</code> can be obtained from the set of letters of <code>s1</code> by any <strong>one</strong> of the following operations:</p>

<ul>
	<li>Adding exactly one letter to the set of the letters of <code>s1</code>.</li>
	<li>Deleting exactly one letter from the set of the letters of <code>s1</code>.</li>
	<li>Replacing exactly one letter from the set of the letters of <code>s1</code> with any letter, <strong>including</strong> itself.</li>
</ul>

<p>The array <code>words</code> can be divided into one or more non-intersecting <strong>groups</strong>. A string belongs to a group if any <strong>one</strong> of the following is true:</p>

<ul>
	<li>It is connected to <strong>at least one</strong> other string of the group.</li>
	<li>It is the <strong>only</strong> string present in the group.</li>
</ul>

<p>Note that the strings in <code>words</code> should be grouped in such a manner that a string belonging to a group cannot be connected to a string present in any other group. It can be proved that such an arrangement is always unique.</p>

<p>Return <em>an array</em> <code>ans</code> <em>of size</em> <code>2</code> <em>where:</em></p>

<ul>
	<li><code>ans[0]</code> <em>is the <strong>total number</strong> of groups</em> <code>words</code> <em>can be divided into, and</em></li>
	<li><code>ans[1]</code> <em>is the <strong>size of the largest</strong> group</em>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["a","b","ab","cde"]
<strong>Output:</strong> [2,3]
<strong>Explanation:</strong>
- words[0] can be used to obtain words[1] (by replacing 'a' with 'b'), and words[2] (by adding 'b'). So words[0] is connected to words[1] and words[2].
- words[1] can be used to obtain words[0] (by replacing 'b' with 'a'), and words[2] (by adding 'a'). So words[1] is connected to words[0] and words[2].
- words[2] can be used to obtain words[0] (by deleting 'b'), and words[1] (by deleting 'a'). So words[2] is connected to words[0] and words[1].
- words[3] is not connected to any string in words.
Thus, words can be divided into 2 groups ["a","b","ab"] and ["cde"]. The size of the largest group is 3.  
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["a","ab","abc"]
<strong>Output:</strong> [1,3]
<strong>Explanation:</strong>
- words[0] is connected to words[1].
- words[1] is connected to words[0] and words[2].
- words[2] is connected to words[1].
Since all strings are connected to each other, they should be grouped together.
Thus, the size of the largest group is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 26</code></li>
	<li><code>words[i]</code> consists of lowercase English letters only.</li>
	<li>No letter occurs more than once in <code>words[i]</code>.</li>
</ul>


**Similar Questions**:
* [Word Ladder II (Hard)](https://leetcode.com/problems/word-ladder-ii/)
* [Similar String Groups (Hard)](https://leetcode.com/problems/similar-string-groups/)
* [Largest Component Size by Common Factor (Hard)](https://leetcode.com/problems/largest-component-size-by-common-factor/)

## Solution 1. Union Find + Bitmask

Let `m` be a map from a bitmask to the corresponding index in `A`.

For each `A[i]`:
* generate the correponding hash `h`
* generate the addition, deletion and replacement variant of hash `h`.
* Assume the variant's hash is `t`, we connect `i` with `m[t]` using Union Find.

In the end, Union Find can tell us the number of groups and the size of all groups.

Note that this sometimes gets TLE because of the tight time constraint and the randomness of `unordered_map`.

```cpp
// OJ: https://leetcode.com/contest/weekly-contest-278/problems/groups-of-strings/
// Author: github.com/lzl124631x
// Time: O(26 * 26 * NlogN)
// Space: O(N)
class UnionFind {
    vector<int> id, size;
    int cnt;
public:
    UnionFind(int n) : id(n), size(n, 1), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        size[y] += size[x];
        --cnt;
    }
    int getSize(int a) {
        return size[find(a)];
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    vector<int> groupStrings(vector<string>& A) {
        int N = A.size();
        UnionFind uf(N);
        unordered_map<int, int> m; // map from hash to index
        m.reserve(N);
        for (int i = 0; i < N; ++i) {
            int h = 0;
            for (char c : A[i]) h |= 1 << (c - 'a'); // `h` is the bitmask representation of `A[i]`
            for (int j = 0; j < 26; ++j) {
                if (h >> j & 1) { // if `h`'s j-th bit is 1
                    int del = h ^ (1 << j); // `del` is the bitmask after deleting the `j`-th bit
                    if (m.count(del)) uf.connect(i, m[del]); // Connect `A[i]` with its deletion variant
                    for (int k = 0; k < 26; ++k) { // we replace `j`-th bit with `k`-th bit
                        int rep = del | (1 << k); // `rep` is the bitmask after replacing `j`-th bit with `k`-th bit.
                        if (rep != del && m.count(rep)) uf.connect(i, m[rep]);
                    }
                } else {
                    int add = h | (1 << j); // `add` is the bitmask after adding `j`-th bit
                    if (m.count(add)) uf.connect(i, m[add]);
                }
            }
            m[h] = i;
        }
        int mx = 1;
        for (int i = 0; i < N; ++ i) mx = max(mx, uf.getSize(i));
        return {uf.getCount(), mx};
    }
};
```

## Solution 2. Optimization

1. Added "union by rank" to the Union Find to reduce the time complexity of `find` from `O(logN)` to `O(alpha(N))` where `alpha(N)` is the inverse function of Ackermann function.
2. For the replacement operation, reduced the time from `O(26 * 26)` to `O(26)` by "meet-in-the-middle". If two strings are connected after replacement operation, then they can be the same string after deleting one character. Example `"abc"` and `"abd"` are connected because they both become `"ab"` after one deletion.

```cpp
// OJ: https://leetcode.com/problems/groups-of-strings/
// Author: github.com/lzl124631x
// Time: O(26 * N * alpha(N))
// Space: O(26 * N)
class UnionFind {
    vector<int> id, rank, size;
    int cnt;
public:
    UnionFind(int n) : id(n), rank(n, 0), size(n, 1), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] > rank[y]) {
            id[y] = x;
            size[x] += size[y];
        } else {
            id[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
        --cnt;
    }
    int getSize(int a) {
        return size[find(a)];
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    vector<int> groupStrings(vector<string>& A) {
        int N = A.size();
        UnionFind uf(N);
        unordered_map<int, int> m, delMap;
        m.reserve(N);
        for (int i = 0; i < N; ++i) {
            int h = 0;
            for (char c : A[i]) h |= 1 << (c - 'a'); // `h` is the bitmask representation of `A[i]`
            for (int j = 0; j < 26; ++j) {
                if (h >> j & 1) { // if `h`'s j-th bit is 1
                    int del = h ^ (1 << j); // `del` is the bitmask after deleting the `j`-th bit
                    if (m.count(del)) uf.connect(i, m[del]); // Connect `A[i]` with its deletion variant
                    if (delMap.count(del)) uf.connect(i, delMap[del]);
                    else delMap[del] = i;
                } else {
                    int add = h | (1 << j); // `add` is the bitmask after adding `j`-th bit
                    if (m.count(add)) uf.connect(i, m[add]);
                }
            }
            m[h] = i;
        }
        int mx = 1;
        for (int i = 0; i < N; ++ i) mx = max(mx, uf.getSize(i));
        return {uf.getCount(), mx};
    }
};
```

## Discuss

https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/discuss/1730117