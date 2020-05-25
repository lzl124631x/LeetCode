# [Fox and Names](https://codeforces.com/contest/510/problem/C)

<div class="problem-statement">   <div class="header">     <div class="title">C. Fox And Names</div>     <div class="time-limit">       <div class="property-title">time limit per test</div>2 seconds</div>     <div class="memory-limit">       <div class="property-title">memory limit per test</div>256 megabytes</div>     <div class="input-file">       <div class="property-title">input</div>standard input</div>     <div class="output-file">       <div class="property-title">output</div>standard output</div></div>   <div>     <p>Fox Ciel is going to publish a paper on FOCS (Foxes Operated       Computer Systems, pronounce: "Fox"). She heard a rumor:       the authors list on the paper is always sorted in the <span class="tex-font-style-underline">lexicographical</span> order. </p>     <p>After checking some examples, she found out that sometimes it       wasn't true. On some papers authors' names weren't sorted in <span class="tex-font-style-underline">lexicographical</span> order in       normal sense. But it was always true that after some modification       of the order of letters in alphabet, the order of authors becomes         <span class="tex-font-style-underline">lexicographical</span>!</p>     <p>She wants to know, if there exists an order of letters in Latin       alphabet such that the names on the paper she is submitting are       following in the <span class="tex-font-style-underline">lexicographical</span> order. If       so, you should find out any such order.</p>     <p>       <span class="tex-font-style-underline">Lexicographical</span>       order is defined in following way. When we compare <span class="tex-span">         <i>s</i></span> and <span class="tex-span">         <i>t</i></span>, first we find the leftmost position with       differing characters: <span class="tex-span">         <i>s</i>         <sub class="lower-index">           <i>i</i></sub> ≠ <i>t</i>         <sub class="lower-index">           <i>i</i></sub></span>. If there is no such position (i. e.         <span class="tex-span">         <i>s</i></span> is a prefix of <span class="tex-span">         <i>t</i></span> or vice versa) the shortest string is less.       Otherwise, we compare characters <span class="tex-span">         <i>s</i>         <sub class="lower-index">           <i>i</i></sub></span> and <span class="tex-span">         <i>t</i>         <sub class="lower-index">           <i>i</i></sub></span> according to their order in alphabet.</p></div>         <div class="input-specification">     <div class="section-title">Input</div>          <p>The first line contains an integer <span class="tex-span">         <i>n</i></span> (<span class="tex-span">1 ≤ <i>n</i> ≤ 100</span>): number of names.</p>     <p>Each of the following <span class="tex-span">         <i>n</i></span> lines contain one string <span class="tex-span">         <i>name</i>         <sub class="lower-index">           <i>i</i></sub></span> (<span class="tex-span">1 ≤ |<i>name</i>         <sub class="lower-index">           <i>i</i></sub>| ≤ 100</span>), the <span class="tex-span">         <i>i</i></span>-th name. Each name contains only lowercase Latin       letters. All names are different.</p></div>         <div class="output-specification">     <div class="section-title">Output</div>          <p>If there exists such order of letters that the given names are       sorted lexicographically, output any such order as a permutation       of characters 'a'–'z' (i. e. first output the first letter of the       modified alphabet, then the second, and so on).</p>     <p>Otherwise output a single word "Impossible" (without quotes).</p></div>         <div class="sample-tests">     <div class="section-title">Examples</div>               <div class="sample-test">       <div class="input">         <div class="title">Input<div title="Copy" data-clipboard-target="#id0047712434416716754" id="id005306748541724176" class="input-output-copier">Copy</div></div>         <pre id="id0047712434416716754">3<br>rivest<br>shamir<br>adleman<br></pre></div>       <div class="output">         <div class="title">Output<div title="Copy" data-clipboard-target="#id00910818824933006" id="id009543982272196343" class="input-output-copier">Copy</div></div>         <pre id="id00910818824933006">bcdefghijklmnopqrsatuvwxyz<br></pre></div>       <div class="input">         <div class="title">Input<div title="Copy" data-clipboard-target="#id002388487012888436" id="id005430558037252329" class="input-output-copier">Copy</div></div>         <pre id="id002388487012888436">10<br>tourist<br>petr<br>wjmzbmr<br>yeputons<br>vepifanov<br>scottwu<br>oooooooooooooooo<br>subscriber<br>rowdark<br>tankengineer<br></pre></div>       <div class="output">         <div class="title">Output<div title="Copy" data-clipboard-target="#id005914977943989022" id="id00508145167718012" class="input-output-copier">Copy</div></div>         <pre id="id005914977943989022">Impossible<br></pre></div>       <div class="input">         <div class="title">Input<div title="Copy" data-clipboard-target="#id003705258721664211" id="id005026967956215982" class="input-output-copier">Copy</div></div>         <pre id="id003705258721664211">10<br>petr<br>egor<br>endagorion<br>feferivan<br>ilovetanyaromanova<br>kostka<br>dmitriyh<br>maratsnowbear<br>bredorjaguarturnik<br>cgyforever<br></pre></div>       <div class="output">         <div class="title">Output<div title="Copy" data-clipboard-target="#id008150708744113269" id="id003510007903748298" class="input-output-copier">Copy</div></div>         <pre id="id008150708744113269">aghjlnopefikdmbcqrstuvwxyz<br></pre></div>       <div class="input">         <div class="title">Input<div title="Copy" data-clipboard-target="#id0019654425752322746" id="id005916429744071743" class="input-output-copier">Copy</div></div>         <pre id="id0019654425752322746">7<br>car<br>care<br>careful<br>carefully<br>becarefuldontforgetsomething<br>otherwiseyouwillbehacked<br>goodluck<br></pre></div>       <div class="output">         <div class="title">Output<div title="Copy" data-clipboard-target="#id0048188148367915673" id="id0007533705205471852" class="input-output-copier">Copy</div></div>         <pre id="id0048188148367915673">acbdefhijklmnogpqrstuvwxyz<br></pre></div></div></div></div>

## Solution 1. Topological Sort (BFS)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define PRINTCASE printf("Case #%d: ",case_n++)
#define PRINTCASE_ printf("Case #%d:\n",case_n++)
#define RD(a) scanf("%d", &(a))
#define RDD(a, b) scanf("%d%d", &(a), &(b))
#define PD(a) printf("%d", (a))
#define PD_(a) printf("%d\n", (a))
#define REP(i,s,t) for(int i=(s);i<(t);i++)

string solve(int N, vector<string> &A) {
    vector<unordered_set<int>> G(26);
    for (int i = 1; i < N; ++i) {
        int j = 0;
        auto &a = A[i - 1], &b = A[i];
        for (; j < min(a.size(), b.size()); ++j) {
            if (a[j] == b[j]) continue;
            G[a[j] - 'a'].insert(b[j] - 'a');
            break;
        }
        if (j == min(a.size(), b.size()) && a.size() > b.size()) return "Impossible";
    }
    string ans;
    int indegree[26] = {};
    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        for (int v : G[i]) indegree[v]++;
    }
    for (int i = 0; i < 26; ++i) {
        if (indegree[i] == 0) q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        ans.push_back('a' + u);
        for (int v : G[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }
    return ans.size() == 26 ? ans : "Impossible";
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    CASET {
        int N;
        RD(N);
        vector<string> A(N);
        REP(i, 0, N) {
            cin >> A[i];
        }
        PRINTCASE;
        cout << solve(N, A) << endl;
    }
    return 0;
}
```

## Solution 2. Topological Sort (DFS)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define PRINTCASE printf("Case #%d: ",case_n++)
#define PRINTCASE_ printf("Case #%d:\n",case_n++)
#define RD(a) scanf("%d", &(a))
#define RDD(a, b) scanf("%d%d", &(a), &(b))
#define PD(a) printf("%d", (a))
#define PD_(a) printf("%d\n", (a))
#define REP(i,s,t) for(int i=(s);i<(t);i++)

vector<int> state;
string ans;
vector<unordered_set<int>> G;
bool dfs(int u) {
    if (state[u]) return state[u] == 1;
    state[u] = -1;
    for (int v : G[u]) {
        if (!dfs(v)) return false;
    }
    state[u] = 1;
    ans.push_back('a' + u);
    return true;
}
string solve(int N, vector<string> &A) {
    G.assign(26, {});
    ans.clear();
    state.assign(26, 0);
    for (int i = 1; i < N; ++i) {
        int j = 0;
        auto &a = A[i - 1], &b = A[i];
        for (; j < min(a.size(), b.size()); ++j) {
            if (a[j] == b[j]) continue;
            G[a[j] - 'a'].insert(b[j] - 'a');
            break;
        }
        if (j == min(a.size(), b.size()) && a.size() > b.size()) return "Impossible";
    }
    for (int i = 0; i < 26; ++i) {
        if (state[i]) continue;
        if (!dfs(i)) return "Impossible";
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    CASET {
        int N;
        RD(N);
        vector<string> A(N);
        REP(i, 0, N) {
            cin >> A[i];
        }
        PRINTCASE;
        cout << solve(N, A) << endl;
    }
    return 0;
}
```