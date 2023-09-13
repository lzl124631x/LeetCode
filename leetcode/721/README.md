# [721. Accounts Merge (Medium)](https://leetcode.com/problems/accounts-merge/)

<p>Given a list of <code>accounts</code> where each element <code>accounts[i]</code> is a list of strings, where the first element <code>accounts[i][0]</code> is a name, and the rest of the elements are <strong>emails</strong> representing emails of the account.</p>

<p>Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.</p>

<p>After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails <strong>in sorted order</strong>. The accounts themselves can be returned in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
<strong>Output:</strong> [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
<strong>Explanation:</strong>
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
<strong>Output:</strong> [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= accounts.length &lt;= 1000</code></li>
	<li><code>2 &lt;= accounts[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= accounts[i][j] &lt;= 30</code></li>
	<li><code>accounts[i][0]</code> consists of English letters.</li>
	<li><code>accounts[i][j] (for j &gt; 0)</code> is a valid email.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Pinterest](https://leetcode.com/company/pinterest), [Bloomberg](https://leetcode.com/company/bloomberg), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Redundant Connection (Medium)](https://leetcode.com/problems/redundant-connection/)
* [Sentence Similarity (Easy)](https://leetcode.com/problems/sentence-similarity/)
* [Sentence Similarity II (Medium)](https://leetcode.com/problems/sentence-similarity-ii/)

## Solution 1. Union Find (Account as Nodes)

### Complexity Analysis

Let `N` be the length of `A`, `M` be the maximum length of `A[i]`, `W` is the maximum email string length.

Filling `emailToIndex` takes `O(NMW)` time and `O(NMW)` space.

The `UnionFind` takes `O(N)` space.

Connecting nodes in the `UnionFind` takes `O(NMW)` time.

Filling the `idToEmail` takes `O(NMWlog(NM))` time and `O(NMW)` space.

Gathering the answer takes `O(NMW)` time.

So, overall it takes `O(NMWlog(NM))` time and `O(NMW)` space.

```cpp
// OJ: https://leetcode.com/problems/accounts-merge/
// Author: github.com/lzl124631x
// Time: O(NMWlog(NM))
// Space: O(NMW)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {
        unordered_map<string, int> emailToIndex; // email to the index of the last account entry containing this email
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 1; j < A[i].size(); ++j) emailToIndex[A[i][j]] = i;
        }
        UnionFind uf(A.size());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 1; j < A[i].size(); ++j) uf.connect(i, emailToIndex[A[i][j]]);
        }
        unordered_map<int, set<string>> idToEmail;
        for (int i = 0; i < A.size(); ++i) {
            auto &st = idToEmail[uf.find(i)];
            for (int j = 1; j < A[i].size(); ++j) st.insert(A[i][j]);
        }
        vector<vector<string>> ans;
        for (auto &[id, emails] : idToEmail) {
            ans.push_back({A[id][0]});
            for (auto &email : emails) ans.back().push_back(email);
        }
        return ans;
    }
};
```

## Solution 2. Union Find (Email as Nodes)

```cpp
// OJ: https://leetcode.com/problems/accounts-merge/
// Author: github.com/lzl124631x
// Time: O(NMWlog(NM))
// Space: O(NMW)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
}; 
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {
        unordered_map<string, int> emailIds; // Assign each email an ID
        int N = A.size(), emailId = 0;
        for (auto &v : A) {
            for (int j = 1; j < v.size(); ++j) {
                if (!emailIds.count(v[j])) emailIds[v[j]] = emailId++;
            }
        }
        UnionFind uf(emailId);
        for (auto &v : A) {
            for (int j = 2; j < v.size(); ++j) {
                uf.connect(emailIds[v[1]], emailIds[v[j]]); // Connect the email IDs
            }
        }
        unordered_set<int> seen;
        vector<vector<string>> ans;
        unordered_map<int, int> emailIdToIndex; // Representative email ID to the index of person in answer array
        for (auto &v : A) {
            int id = uf.find(emailIds[v[1]]);
            if (!emailIdToIndex.count(id)) { // If we haven't seen this representative email ID, this is a new person.
                emailIdToIndex[id] = ans.size();
                ans.push_back({ v[0] });
            }
            int index = emailIdToIndex[id];
            for (int i = 1; i < v.size(); ++i) {
                if (seen.count(emailIds[v[i]])) continue;
                seen.insert(emailIds[v[i]]);
                ans[index].push_back(v[i]);
            }
        }
        for (auto &v : ans) sort(begin(v) + 1, end(v));
        return ans;
    }
};
```

## Solution 3. DFS (Emails as Nodes)

We first build a graph where the nodes are the emails. If two emails belongs to the same person, we will add an edge between them.

Then we traverse the `A`, and `dfs` to visit all the nodes in the same graph component. When visting, we append the emails to the person's email list.

### Complexity Analysis

Building the graph takes `O(NMW)` time and `O(NMW)` space.

Visiting all the components will take `O(NMW)` time and `O(NMW)` space for the `seen`.

Sorting the emails in the components takes `O(NMWlog(NM))` time overall.

So the time complexity is `O(NMWlog(NM))` and space complexity is `O(NMW)`.

```cpp
// OJ: https://leetcode.com/problems/accounts-merge/
// Author: github.com/lzl124631x
// Time: O(NMWlog(NM))
// Space: O(NMW)
class Solution {
    unordered_map<string, unordered_set<string>> G;
    unordered_set<string> seen;
    vector<vector<string>> ans;
    void dfs(const string &s) {
        if (seen.count(s)) return;
        seen.insert(s);
        ans.back().push_back(s);
        for (const auto &nei : G[s]) {
            dfs(nei);
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {
        for (auto &v : A) {
            for (int i = 1; i < v.size(); ++i) {
                G[v[1]].insert(v[i]);
                G[v[i]].insert(v[1]);
            }
        }
        for (int i = 0; i < A.size(); ++i) {
            if (seen.count(A[i][1])) continue;
            ans.push_back({A[i][0]});
            dfs(A[i][1]);
            sort(begin(ans.back()) + 1, end(ans.back()));
        }
        return ans;
    }
};
```