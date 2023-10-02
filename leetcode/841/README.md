# [841. Keys and Rooms (Medium)](https://leetcode.com/problems/keys-and-rooms/)

<p>There are <code>N</code> rooms and you start in room <code>0</code>.&nbsp; Each room has a distinct number in <code>0, 1, 2, ..., N-1</code>, and each room may have&nbsp;some keys to access the next room.&nbsp;</p>

<p>Formally, each room <code>i</code>&nbsp;has a list of keys <code>rooms[i]</code>, and each key <code>rooms[i][j]</code> is an integer in <code>[0, 1, ..., N-1]</code> where <code>N = rooms.length</code>.&nbsp; A key <code>rooms[i][j] = v</code>&nbsp;opens the room with number <code>v</code>.</p>

<p>Initially, all the rooms start locked (except for room <code>0</code>).&nbsp;</p>

<p>You can walk back and forth between rooms freely.</p>

<p>Return <code>true</code>&nbsp;if and only if you can enter&nbsp;every room.</p>

<ol>
</ol>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>[[1],[2],[3],[]]
<strong>Output: </strong>true
<strong>Explanation:  </strong>
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>[[1,3],[3,0,1],[2],[0]]
<strong>Output: </strong>false
<strong>Explanation: </strong>We can't enter the room with number 2.
</pre>

<p><b>Note:</b></p>

<ol>
	<li><code>1 &lt;= rooms.length &lt;=&nbsp;1000</code></li>
	<li><code>0 &lt;= rooms[i].length &lt;= 1000</code></li>
	<li>The number of keys in all rooms combined is at most&nbsp;<code>3000</code>.</li>
</ol>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/keys-and-rooms/
// Author: github.com/lzl124631x
// Time: O(K) where K is the count of all the keys.
// Space: O(N) where N is the count of rooms
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& A) {
        int N = A.size(), cnt = 0;
        vector<bool> seen(N);
        seen[0] = true;
        queue<int> q;
        q.push(0);
        while (q.size()) {
            int i = q.front();
            q.pop();
            ++cnt;
            for (int j : A[i]) {
                if (seen[j]) continue;
                seen[j] = true;
                q.push(j);
            }
        }
        return cnt == N;
    }
};
```