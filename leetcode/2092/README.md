# [2092. Find All People With Secret (Hard)](https://leetcode.com/problems/find-all-people-with-secret/)

<p>You are given an integer <code>n</code> indicating there are <code>n</code> people numbered from <code>0</code> to <code>n - 1</code>. You are also given a <strong>0-indexed</strong> 2D integer array <code>meetings</code> where <code>meetings[i] = [x<sub>i</sub>, y<sub>i</sub>, time<sub>i</sub>]</code> indicates that person <code>x<sub>i</sub></code> and person <code>y<sub>i</sub></code> have a meeting at <code>time<sub>i</sub></code>. A person may attend <strong>multiple meetings</strong> at the same time. Finally, you are given an integer <code>firstPerson</code>.</p>

<p>Person <code>0</code> has a <strong>secret</strong> and initially shares the secret with a person <code>firstPerson</code> at time <code>0</code>. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person <code>x<sub>i</sub></code> has the secret at <code>time<sub>i</sub></code>, then they will share the secret with person <code>y<sub>i</sub></code>, and vice versa.</p>

<p>The secrets are shared <strong>instantaneously</strong>. That is, a person may receive the secret and share it with people in other meetings within the same time frame.</p>

<p>Return <em>a list of all the people that have the secret after all the meetings have taken place. </em>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
<strong>Output:</strong> [0,1,2,3,5]
<strong>Explanation:
</strong>At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
<strong>Output:</strong> [0,1,3]
<strong>Explanation:</strong>
At time 0, person 0 shares the secret with person 3.
At time 2, neither person 1 nor person 2 know the secret.
At time 3, person 3 shares the secret with person 0 and person 1.
Thus, people 0, 1, and 3 know the secret after all the meetings.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
<strong>Output:</strong> [0,1,2,3,4]
<strong>Explanation:</strong>
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 6, meetings = [[0,2,1],[1,3,1],[4,5,1]], firstPerson = 1
<strong>Output:</strong> [0,1,2,3]
<strong>Explanation:</strong>
At time 0, person 0 shares the secret with person 1.
At time 1, person 0 shares the secret with person 2, and person 1 shares the secret with person 3.
Thus, people 0, 1, 2, and 3 know the secret after all the meetings.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 3</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i </sub>&lt;= n - 1</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li><code>1 &lt;= time<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= firstPerson &lt;= n - 1</code></li>
</ul>


**Similar Questions**:
* [Reachable Nodes In Subdivided Graph (Hard)](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/)

## Solution 1. Union Find

Sort `meetings` in ascending order of meeting time.

Visit the meetings happening at the same time together.

We can connect the two persons in the same meeting using a UnionFind.

Tricky point here: After traversing this batch of meetings, we reset the persons who don't know the secret by checking if he/she is connected to person 0. With UnionFind, reseting means setting `id[x] = x`.

In the end, we add all the persons who are connected to person 0 into the answer array.

```cpp
// OJ: https://leetcode.com/problems/find-all-people-with-secret/
// Author: github.com/lzl124631x
// Time: O(MlogM + (M + N) * logN) where `M` is the length of `meetings`
//        Can be reduced to `O(MlogM + (M + N) * alpha(N))`
// Space: O(M + N). Can be reduced to O(N) if we make `ppl` an `unordered_set`.
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        id[find(b)] = find(a);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    void reset(int a) { id[a] = a; }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& A, int firstPerson) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[2] < b[2]; }); // Sort the meetings in ascending order of meeting time
        UnionFind uf(n);
        uf.connect(0, firstPerson); // Connect person 0 with the first person
        vector<int> ppl;
        for (int i = 0, M = A.size(); i < M; ) {
            ppl.clear();
            int time = A[i][2];
            for (; i < M && A[i][2] == time; ++i) { // For all the meetings happening at the same time
                uf.connect(A[i][0], A[i][1]); // Connect the two persons
                ppl.push_back(A[i][0]); // Add both persons into the pool
                ppl.push_back(A[i][1]);
            }
            for (int n : ppl) { // For each person in the pool, check if he/she's connected with person 0.
                if (!uf.connected(0, n)) uf.reset(n); // If not, this person doesn't have secret, reset it.
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (uf.connected(0, i)) ans.push_back(i); // Push all the persons who are connected with person 0 into answer array
        }
        return ans;
    }
};
```

**Complexity Analysis**:

Sorting takes `O(MlogM)` time.

Each meeting is visited and pushed into/popped out of `ppl` only once. For each visit, the `connect`/`connected` takes amortized `O(logN)` time. So, traversing all the meetings takes `O(MlogN)` time. Note that if we do union-by-rank, the time complexity can be reduced to `O(M * alpha(N))` where `alpha(N)` is the inverse function of Ackermann function, and is even more efficient than `logN`. But in LeetCode, the difference is negligible, so I usually just use path compression for simplicity. It's definitly worth mentioning this knowledge during your interview though.

Lastly, traversing all the persons and checking connection with person 0 takes amortized `O(NlogN)` time.

So, overall the **time complexity** is amortized `O(MlogM + (M + N) * logN)`, which can be reduced to `O(MlogM + (M + N) * alpha(N))` with union-by-rank.

As for space complexity, the Union Find takes `O(N)` space. The `ppl` array takes `O(M)` space in the worst case, but it can be reduced to `O(N)` if we use `unordered_set`. I use `vector<int>` because `unordered_set<int>` has extra overhead which at times consumes more time/space than `vector<int>` in LeetCode.

So, overall the **(extra) space complexity** is `O(M + N)` which can be reduced to `O(N)`.

## Discuss

https://leetcode.com/problems/find-all-people-with-secret/discuss/1599815/C%2B%2B-Union-Find