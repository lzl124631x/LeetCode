# [547. Friend Circles (Medium)](https://leetcode.com/problems/friend-circles/)

<p>
There are <b>N</b> students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a <b>direct</b> friend of B, and B is a <b>direct</b> friend of C, then A is an <b>indirect</b> friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
</p>

<p>
Given a <b>N*N</b> matrix <b>M</b> representing the friend relationship between students in the class. If M[i][j] = 1, then the i<sub>th</sub> and j<sub>th</sub> students are <b>direct</b> friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
<b>Output:</b> 2
<b>Explanation:</b>The 0<sub>th</sub> and 1<sub>st</sub> students are direct friends, so they are in a friend circle. <br>The 2<sub>nd</sub> student himself is in a friend circle. So return 2.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
<b>Output:</b> 1
<b>Explanation:</b>The 0<sub>th</sub> and 1<sub>st</sub> students are direct friends, the 1<sub>st</sub> and 2<sub>nd</sub> students are direct friends, <br>so the 0<sub>th</sub> and 2<sub>nd</sub> students are indirect friends. All of them are in the same friend circle, so return 1.
</pre>
<p></p>


<p><b>Note:</b><br>
</p><ol>
<li>N is in range [1,200].</li>
<li>M[i][i] = 1 for all students.</li>
<li>If M[i][j] = 1, then M[j][i] = 1.</li>
</ol>
<p></p>

**Companies**:  
[Two Sigma](https://leetcode.com/company/two-sigma), [LinkedIn](https://leetcode.com/company/linkedin), [Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Number of Connected Components in an Undirected Graph (Medium)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
* [Robot Return to Origin (Easy)](https://leetcode.com/problems/robot-return-to-origin/)
* [Sentence Similarity (Easy)](https://leetcode.com/problems/sentence-similarity/)
* [Sentence Similarity II (Medium)](https://leetcode.com/problems/sentence-similarity-ii/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/friend-circles/
// Author: github.com/lzl124631x
// Time: O(N^2 * a(N)), where `a` is the inverse function of Ackermann function. O(a(N)) is faster than O(log(N)).
// Space: O(N)
class UnionFind {
private:
    vector<int> rank;
    vector<int> id;
    int count;
    int find (int i) {
        if (id[i] == i) return i;
        return id[i] = find(id[i]);
    }
public:
    UnionFind(int n) : rank(n, 0), id(n), count(n) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int i, int j) {
        int p = find(i), q = find(j);
        if (p == q) return;
        if (rank[p] > rank[q]) id[p] = q;
        else {
            id[q] = p;
            if (rank[p] == rank[q]) rank[p]++;
        }
        --count;
    }
    int getCount() { return count; }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        UnionFind uf(N);
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (M[i][j]) uf.connect(i, j);
        return uf.getCount();
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/friend-circles
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
  void dfs(vector<vector<int>>& M, int i, vector<bool> &visited) {
    visited[i] = true;
    for (int j = i + 1; j < M.size(); ++j) {
      if (!M[i][j] || visited[j]) continue;
      dfs(M, j, visited);
    }
  }
public:
  int findCircleNum(vector<vector<int>>& M) {
    vector<bool> visited(M.size(), false);
    int cnt = 0;
    for (int i = 0; i < M.size(); ++i) {
      if (visited[i]) continue;
      dfs(M, i, visited);
      ++cnt;
    }
    return cnt;
  }
};
```