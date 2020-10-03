# [1606. Find Servers That Handled Most Number of Requests (Hard)](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)

<p>You have <code>k</code> servers numbered from <code>0</code> to <code>k-1</code> that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but <strong>cannot handle more than one request at a time</strong>. The requests are assigned to servers according to a specific algorithm:</p>

<ul>
	<li>The <code>i<sup>th</sup></code> (0-indexed) request arrives.</li>
	<li>If all servers are busy, the request is dropped (not handled at all).</li>
	<li>If the <code>(i % k)<sup>th</sup></code> server is available, assign the request to that server.</li>
	<li>Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the <code>i<sup>th</sup></code> server is busy, try to assign the request to the <code>(i+1)<sup>th</sup></code> server, then the <code>(i+2)<sup>th</sup></code> server, and so on.</li>
</ul>

<p>You are given a <strong>strictly increasing</strong> array <code>arrival</code> of positive integers, where <code>arrival[i]</code> represents the arrival time of the <code>i<sup>th</sup></code> request, and another array <code>load</code>, where <code>load[i]</code> represents the load of the <code>i<sup>th</sup></code> request (the time it takes to complete). Your goal is to find the <strong>busiest server(s)</strong>. A server is considered <strong>busiest</strong> if it handled the most number of requests successfully among all the servers.</p>

<p>Return <em>a list containing the IDs (0-indexed) of the <strong>busiest server(s)</strong></em>. You may return the IDs in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/08/load-1.png" style="width: 389px; height: 221px;">
<pre><strong>Input:</strong> k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
<strong>Output:</strong> [1] 
<strong>Explanation:</strong>
All of the servers start out available.
The first 3 requests are handled by the first 3 servers in order.
Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
<strong>Output:</strong> [0]
<strong>Explanation:</strong>
The first 3 requests are handled by first 3 servers.
Request 3 comes in. It is handled by server 0 since the server is available.
Server 0 handled two requests, while servers 1 and 2 handled one request each. Hence server 0 is the busiest server.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> k = 3, arrival = [1,2,3], load = [10,12,11]
<strong>Output:</strong> [0,1,2]
<strong>Explanation: </strong>Each server handles a single request, so they are all considered the busiest.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
<strong>Output:</strong> [1]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> k = 1, arrival = [1], load = [1]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arrival.length, load.length &lt;= 10<sup>5</sup></code></li>
	<li><code>arrival.length == load.length</code></li>
	<li><code>1 &lt;= arrival[i], load[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>arrival</code> is <strong>strictly increasing</strong>.</li>
</ul>


**Related Topics**:  
[Ordered Map](https://leetcode.com/tag/ordered-map/)

## Solution 1. Set + Heap

When we meet circular array, one idea that should come into our mind is concatenating the array to the end of itself so that we can easily wrap around.

In this solution, `set<int> free` contains the index of available servers. We also insert `index + k` into `free` so that we can wrap around to find a server whose index is smaller than the current server.

When we find an available server, we erase it (and `index + k`) from `free`, and put `{ endTime, serverIndex }` into a min-heap `pq`.

For each `arrival[i]`, we first free all those servers from `pq` whose `endTime` is smaller than or equal to `arrival[i]`, then find the smallest index available in `free` and use it.


```cpp
// OJ: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
// Author: github.com/lzl124631x
// Time: O(KlogK + N * (logK)^2)
// Space: O(K)
// Ref: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/discuss/876804/C%2B%2B-or-Circular-Aay-or-Ordered-Set-or-Priority-Queue-or-O(N-(log-K-%2B-log-N)-or-O(K)
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& A, vector<int>& L) {
        set<int> free; // servers in free are available to use
        int N = A.size();
        for (int i = 0; i < 2 * k - 1; i ++) free.insert(i); // add i + k into the free pool so that we can easily find an available space in circular array.
        vector<int> cnt(k);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // <end, server>. Servers in pq are occupied. We don't insert `server + k` into pq.
        for (int i = 0; i < N; ++i) {
            int start = A[i], len = L[i];
            while (pq.size() && pq.top().first <= start) { // free those freeable servers.
                auto [end, server] = pq.top();
                pq.pop();
                free.insert(server);
                free.insert(server + k);
            }
            if (free.size()) {
                int server = *free.lower_bound(i % k) % k;
                free.erase(server);
                free.erase(server + k);
                cnt[server]++;
                pq.push({ start + len, server });
            }
        }
        int mx = *max_element(begin(cnt), end(cnt));
        vector<int> ans;
        for (int i = 0; i < k; i ++) {
            if (cnt[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};
```