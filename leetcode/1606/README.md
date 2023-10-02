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

`set<int> free` contains the index of available servers. `busy` is a min-heap each item of which is a pair of `{ endTime, serverIndex }`.

When we find an available server, we erase it from `free`, and put `{ endTime, serverIndex }` into a min-heap `busy`.

For each `arrival[i]`, we first free all those servers from `busy` whose `endTime` is smaller than or equal to `arrival[i]`, then find the first available server in `free` whose index is greater than `i % k` in circular order.

About time complexity, iterating the `N` elements in `A` and `L` takes `O(N)`, within each iteration, the amortized time complexity is `O(logK)`. It's because the sizes of the `free` and `busy` are at most `K`, so each push and pop operation takes `O(logK)` time.

Note that for the loop popping `busy`, since at most we can pop `busy` `K` times and each pop takes `O(logK)` time, it looks like it's `O(KlogK)` and the `busy`'s popping operation takes `O(NKlogK)` overall. But since we at most pop `busy` `N - K` times through out the entire function, so the `busy`'s popping operation takes at most `(N - k)logK` time. Thus the funtion's overall time complexity is still `O(NlogK)`.

```cpp
// OJ: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
// Author: github.com/lzl124631x
// Time: O(N * logK)
// Space: O(K)
// Ref: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/discuss/876793/Java-O(nlogn)-use-both-TreeSet-and-PriorityQueue
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& A, vector<int>& L) {
        vector<int> cnt(k);
        set<int> free;
        for (int i = 0; i < k; ++i) free.insert(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy; // endTime, serverIndex
        for (int i = 0; i < A.size(); ++i) {
            int start = A[i], end = start + L[i];
            while (busy.size() && busy.top().first <= start) {
                int server = busy.top().second;
                busy.pop();
                free.insert(server);
            }
            if (free.empty()) continue;
            auto it = free.lower_bound(i % k);
            if (it == free.end()) it = free.begin();
            cnt[*it]++;
            busy.emplace(end, *it);
            free.erase(*it);
        }
        vector<int> ans;
        int mx = *max_element(begin(cnt), end(cnt));
        for (int i = 0; i < k; ++i) {
            if (cnt[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};
```

## Solution 2.

`free[t]` is the available time of server `t`. Initially `free[t] = 0` for all `0 <= t < k`. When a server `t` takes request `i`, `free[t] = arrival[i] + load[i]`, i.e. it's free at the end time of the request.

`map<int, int> m` is a map from the start time of a request to its load/length. It stores the requests that are not yet handled.

We round-robin visit the servers. For the `i`-th request, we put it into the request pool `m` as `m[arrival[i]] = load[i]`. Its corresponding `i % k`-th server is free at `free[i % k]`, so we scan (binary search) in the `m` to find requests that this `i % k`-th server can handle.

Note that all the requests in `m` thus far are the leftover requests that can't be handled by previous servers. So this `i % k`-th server can just take whatever it can handle. Every time it handles a request, update its free time to be the end time of the request, increment `cnt[i % k]`, remove the request from `m`, and keep finding the next request that it can handle.

Every time a server successfully handles a request, we mark this round `i` as the last successful round. If we've scanned `k` servers since the last successful round but still haven't handled any leftover requests, then no server could handle those leftover requests, we should break now.

```cpp
// OJ: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/discuss/876998/C%2B%2B-Map
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& A, vector<int>& L) {
        vector<int> cnt(k), free(k), ans;
        map<int, int> m;
        for (int i = 0, last = 0;; ++i) {
            if (i < A.size()) m[A[i]] = A[i] + L[i];
            else if (i - last > k) break; // If we've scanned `k` servers since the last time we handle a request, but still haven't handled any leftover requests, then no server could handle those leftover requests, break.
            auto it = m.lower_bound(free[i % k]);
            while (it != end(m)) { // when there are requests whose start times are greater than or equal to the free time of server `i % k`
                last = i; // update the last successfully handled request.
                ++cnt[i % k]; // let this `i % k`-th server handle this request.
                free[i % k] = it->second;
                m.erase(it); // remove this request
                it = m.lower_bound(free[i % k]);
            } // all the leftover requests in `m` are passed over to the next server to handle
        }
        int mx = *max_element(begin(cnt), end(cnt));
        for (int i = 0; i < k; ++i) {
            if (cnt[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};
```