# [2039. The Time When the Network Becomes Idle (Medium)](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/)

<p>There is a network of <code>n</code> servers, labeled from <code>0</code> to <code>n - 1</code>. You are given a 2D integer array <code>edges</code>, where <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> indicates there is a message channel between servers <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code>, and they can pass <strong>any</strong> number of messages to <strong>each other</strong> directly in <strong>one</strong> second. You are also given a <strong>0-indexed</strong> integer array <code>patience</code> of length <code>n</code>.</p>

<p>All servers are <strong>connected</strong>, i.e., a message can be passed from one server to any other server(s) directly or indirectly through the message channels.</p>

<p>The server labeled <code>0</code> is the <strong>master</strong> server. The rest are <strong>data</strong> servers. Each data server needs to send its message to the master server for processing and wait for a reply. Messages move between servers <strong>optimally</strong>, so every message takes the <strong>least amount of time</strong> to arrive at the master server. The master server will process all newly arrived messages <strong>instantly</strong> and send a reply to the originating server via the <strong>reversed path</strong> the message had gone through.</p>

<p>At the beginning of second <code>0</code>, each data server sends its message to be processed. Starting from second <code>1</code>, at the <strong>beginning</strong> of <strong>every</strong> second, each data server will check if it has received a reply to the message it sent (including any newly arrived replies) from the master server:</p>

<ul>
	<li>If it has not, it will <strong>resend</strong> the message periodically. The data server <code>i</code> will resend the message every <code>patience[i]</code> second(s), i.e., the data server <code>i</code> will resend the message if <code>patience[i]</code> second(s) have <strong>elapsed</strong> since the <strong>last</strong> time the message was sent from this server.</li>
	<li>Otherwise, <strong>no more resending</strong> will occur from this server.</li>
</ul>

<p>The network becomes <strong>idle</strong> when there are <strong>no</strong> messages passing between servers or arriving at servers.</p>

<p>Return <em>the <strong>earliest second</strong> starting from which the network becomes <strong>idle</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="example 1" src="https://assets.leetcode.com/uploads/2021/09/22/quiet-place-example1.png" style="width: 750px; height: 384px;">
<pre><strong>Input:</strong> edges = [[0,1],[1,2]], patience = [0,2,1]
<strong>Output:</strong> 8
<strong>Explanation:</strong>
At (the beginning of) second 0,
- Data server 1 sends its message (denoted 1A) to the master server.
- Data server 2 sends its message (denoted 2A) to the master server.

At second 1,
- Message 1A arrives at the master server. Master server processes message 1A instantly and sends a reply 1A back.
- Server 1 has not received any reply. 1 second (1 &lt; patience[1] = 2) elapsed since this server has sent the message, therefore it does not resend the message.
- Server 2 has not received any reply. 1 second (1 == patience[2] = 1) elapsed since this server has sent the message, therefore it resends the message (denoted 2B).

At second 2,
- The reply 1A arrives at server 1. No more resending will occur from server 1.
- Message 2A arrives at the master server. Master server processes message 2A instantly and sends a reply 2A back.
- Server 2 resends the message (denoted 2C).
...
At second 4,
- The reply 2A arrives at server 2. No more resending will occur from server 2.
...
At second 7, reply 2D arrives at server 2.

Starting from the beginning of the second 8, there are no messages passing between servers or arriving at servers.
This is the time when the network becomes idle.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="example 2" src="https://assets.leetcode.com/uploads/2021/09/04/network_a_quiet_place_2.png" style="width: 100px; height: 85px;">
<pre><strong>Input:</strong> edges = [[0,1],[0,2],[1,2]], patience = [0,10,10]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Data servers 1 and 2 receive a reply back at the beginning of second 2.
From the beginning of the second 3, the network becomes idle.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == patience.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>patience[0] == 0</code></li>
	<li><code>1 &lt;= patience[i] &lt;= 10<sup>5</sup></code> for <code>1 &lt;= i &lt; n</code></li>
	<li><code>1 &lt;= edges.length &lt;= min(10<sup>5</sup>, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt; n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li>There are no duplicate edges.</li>
	<li>Each server can directly or indirectly reach another server.</li>
</ul>


**Similar Questions**:
* [Network Delay Time (Medium)](https://leetcode.com/problems/network-delay-time/)
* [N-ary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)
* [Maximum Depth of N-ary Tree (Easy)](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)

## Solution 1. BFS

1. BFS to get the distance from each server to server `0`.
2. For the `i`-th server with round-trip distance `d`, the earliest second starting from which the network doesn't have any message from this server is `1 + (d - 1) / patience[i] * patience[i] + d)`. The maximum among them is the answer.

```cpp
// OJ: https://leetcode.com/problems/the-time-when-the-network-becomes-idle/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& E, vector<int>& P) {
        int N = P.size(), step = 0, ans = 0;
        vector<vector<int>> G(N);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<bool> seen(N);
        seen[0] = true;
        queue<int> q{{0}};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) {
                    if (seen[v]) continue;
                    seen[v] = true;
                    q.push(v);
                    int d = (step + 1) * 2; // the round-trip distance
                    ans = max(ans, 1 + (d - 1) / P[v] * P[v] + d); // `1 + (d - 1) / P[v] * P[v] + d` is the earliest second starting from which there is no messages from this server left in the network
                }
            }
            step++;
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/the-time-when-the-network-becomes-idle/discuss/1524271/C%2B%2B-BFS