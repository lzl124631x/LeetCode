# [Stable Wall](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003379bb)

<div class="problem-statement-string"><h3>Problem</h3> <p>
  Apollo is playing a game involving <href a="https://en.wikipedia.org/wiki/Polyomino">polyominos</href>.
  A polyomino is a shape made by joining together one or more squares edge to edge to form a single
  connected shape. The game involves combining <b>N</b> polyominos into a single rectangular shape
  without any holes. Each polyomino is labeled with a unique character from <code>A</code> to <code>Z</code>.
</p><p>
  Apollo has finished the game and created a rectangular wall containing <b>R</b> rows and <b>C</b> columns.
  He took a picture and sent it to his friend Selene. Selene likes pictures of walls, but she likes
  them even more if they are <i>stable</i> walls. A wall is stable if it can be created by adding
  polyominos one at a time to the wall so that each polyomino is always <i>supported</i>.
  A polyomino is supported if each of its squares is either on the ground, or has another square
  below it.
</p><p>
  Apollo would like to check if his wall is stable and if it is, prove that fact to Selene by
  telling her the order in which he added the polyominos.
</p> <h3>Input</h3> <p>
  The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> test cases follow.
  Each test case begins with a line containing the two integers <b>R</b> and <b>C</b>.
  Then, <b>R</b> lines follow, describing the wall from top to bottom.
  Each line contains a string of <b>C</b> uppercase characters from <code>A</code> to <code>Z</code>, describing
  that row of the wall.
</p> <h3>Output</h3> <p>
  For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is
  a string of <b>N</b> uppercase characters, describing the order in which he built them.
  If there is more than one such order, output any of them.
  If the wall is not stable, output <code>-1</code> instead.
</p> <h3>Limits</h3> <p>
  Time limit: 20 seconds per test set.<br>
  Memory limit: 1GB.<br>
  1 ≤ <b>T</b> ≤ 100.<br>
  1 ≤ <b>R</b> ≤ 30.<br>
  1 ≤ <b>C</b> ≤ 30.<br>
  No two polyominos will be labeled with the same letter.<br>
  The input is guaranteed to be valid according to the rules described in the statement.<br></p> <h4>Test set 1</h4> <p>
  1 ≤ <b>N</b> ≤ 5.<br></p> <h4>Test set 2</h4> <p>
  1 ≤ <b>N</b> ≤ 26.<br></p> <h3>Sample</h3> <div class="problem-io-wrapper"><table><tr><td><br> <span class="io-table-header">Input</span> <br>&nbsp;
  </td> <td><br> <span class="io-table-header">Output</span> <br>&nbsp;
  </td></tr> <tr><td><pre class="io-content">4
4 6
ZOAAMM
ZOAOMM
ZOOOOM
ZZZZOM
4 4
XXOO
XFFO
XFXO
XXXO
5 3
XXX
XPX
XXX
XJX
XXX
3 10
AAABBCCDDE
AABBCCDDEE
AABBCCDDEE

  </pre></td> <td><pre class="io-content">Case #1: ZOAM
Case #2: -1
Case #3: -1
Case #4: EDCBA

  </pre></td></tr></table></div> <p>
  In sample case #1, note that <code>ZOMA</code> is another possible answer.
</p><p>
  In sample case #2 and sample case #3, the wall is not stable, so the answer is <code>-1</code>.
</p><p>
  In sample case #4, the only possible answer is <code>EDCBA</code>.
  </p></div>

## Solution 1. Topological Sort (BFS)

```cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define PRINTCASE printf("Case #%d: ",case_n++)
#define PRINTCASE_ printf("Case #%d:\n",case_n++)
#define RD(a) scanf("%d", &(a))
#define RDD(a, b) scanf("%d%d", &(a), &(b))
#define PD(a) printf("%d", (a))
#define PD_(a) printf("%d\n", (a))
#define REP(i,s,t) for(int i=(s);i<(t);i++)

string solve(int R, int C, vector<string> A) {
    unordered_map<char, unordered_set<char>> G;
    for (int i = 0; i < C; ++i) {
        unordered_set<char> seen;
        for (int j = R - 1; j >= 0; --j) {
            if (!G.count(A[j][i])) G[A[j][i]] = {};
            for (char c : seen) {
                if (c == A[j][i]) continue;
                G[c].insert(A[j][i]);
            }
            seen.insert(A[j][i]);
        }
    }
    unordered_map<char, int> indegree;
    for (auto &p : G) {
        for (char c : p.second) indegree[c]++;
    }
    queue<char> q;
    for (auto &p : G) {
        if (indegree[p.first] == 0) q.push(p.first);
    }
    string ans;
    while (q.size()) {
        char u = q.front();
        q.pop();
        ans.push_back(u);
        for (char v : G[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }
    return ans.size() == G.size() ? ans : "-1";
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    CASET {
        int R, C;
        RDD(R, C);
        vector<string> A(R);
        REP(i, 0, R) {
            cin >> A[i];
        }
        PRINTCASE;
        cout << solve(R, C, A) << endl;
    }
    return 0;
}
```

## Solution 2. Topological Sort (DFS)

```cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define PRINTCASE printf("Case #%d: ",case_n++)
#define PRINTCASE_ printf("Case #%d:\n",case_n++)
#define RD(a) scanf("%d", &(a))
#define RDD(a, b) scanf("%d%d", &(a), &(b))
#define PD(a) printf("%d", (a))
#define PD_(a) printf("%d\n", (a))
#define REP(i,s,t) for(int i=(s);i<(t);i++)

unordered_map<char, unordered_set<char>> G;
string ans;
unordered_map<char, int> seen;
bool dfs(char u) {
    if (seen[u]) return seen[u] == 1;
    seen[u] = -1;
    for (char v : G[u]) {
        if (!dfs(v)) return false;
    }
    seen[u] = 1;
    ans.push_back(u);
    return true;
}

string solve(int R, int C, vector<string> A) {
    for (int i = 0; i < C; ++i) {
        unordered_set<char> seen;
        for (int j = R - 1; j >= 0; --j) {
            if (!G.count(A[j][i])) G[A[j][i]] = {};
            for (char c : seen) {
                if (c == A[j][i]) continue;
                G[c].insert(A[j][i]);
            }
            seen.insert(A[j][i]);
        }
    }
    for (auto &p : G) {
        if (seen[p.first]) continue;
        if (!dfs(p.first)) return "-1";
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    CASET {
        G.clear();
        ans.clear();
        seen.clear();
        int R, C;
        RDD(R, C);
        vector<string> A(R);
        REP(i, 0, R) {
            cin >> A[i];
        }
        PRINTCASE;
        cout << solve(R, C, A) << endl;
    }
    return 0;
}
```