# [765. Couples Holding Hands (Hard)](https://leetcode.com/problems/couples-holding-hands/)

<p>
N couples sit in 2N seats arranged in a row and want to hold hands.  We want to know the minimum number of swaps so that every couple is sitting side by side.  A <i>swap</i> consists of choosing <b>any</b> two people, then they stand up and switch seats. 
</p><p>
The people and seats are represented by an integer from <code>0</code> to <code>2N-1</code>, the couples are numbered in order, the first couple being <code>(0, 1)</code>, the second couple being <code>(2, 3)</code>, and so on with the last couple being <code>(2N-2, 2N-1)</code>.
</p><p>
The couples' initial seating is given by <code>row[i]</code> being the value of the person who is initially sitting in the i-th seat.

</p><p><b>Example 1:</b><br></p><pre><b>Input:</b> row = [0, 2, 1, 3]
<b>Output:</b> 1
<b>Explanation:</b> We only need to swap the second (row[1]) and third (row[2]) person.
</pre><p></p>

<p><b>Example 2:</b><br></p><pre><b>Input:</b> row = [3, 2, 0, 1]
<b>Output:</b> 0
<b>Explanation:</b> All couples are already seated side by side.
</pre><p></p>

<p>
<b>Note:</b>
</p><ol> 
<li> <code>len(row)</code> is even and in the range of <code>[4, 60]</code>.</li>
<li> <code>row</code> is guaranteed to be a permutation of <code>0...len(row)-1</code>.</li>
</ol>

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive/)
* [Missing Number (Easy)](https://leetcode.com/problems/missing-number/)
* [K-Similar Strings (Hard)](https://leetcode.com/problems/k-similar-strings/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/couples-holding-hands/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/couples-holding-hands/discuss/117520/Java-union-find-easy-to-understand-5-ms
class UnionFind {
    vector<int> id, rank;
    int cnt;
public:
    UnionFind(int n) : id(n), rank(n, 1), cnt(n) {
        for(int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] <= rank[y]) {
            id[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        } else id[y] = x;
        --cnt;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int N = row.size() / 2;
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) uf.connect(row[2 * i] / 2, row[2 * i + 1] / 2);
        return N - uf.getCount();
    }
};
```