# [2402. Meeting Rooms III (Hard)](https://leetcode.com/problems/meeting-rooms-iii)

<p>You are given an integer <code>n</code>. There are <code>n</code> rooms numbered from <code>0</code> to <code>n - 1</code>.</p>

<p>You are given a 2D integer array <code>meetings</code> where <code>meetings[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> means that a meeting will be held during the <strong>half-closed</strong> time interval <code>[start<sub>i</sub>, end<sub>i</sub>)</code>. All the values of <code>start<sub>i</sub></code> are <strong>unique</strong>.</p>

<p>Meetings are allocated to rooms in the following manner:</p>

<ol>
	<li>Each meeting will take place in the unused room with the <strong>lowest</strong> number.</li>
	<li>If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the <strong>same</strong> duration as the original meeting.</li>
	<li>When a room becomes unused, meetings that have an earlier original <strong>start</strong> time should be given the room.</li>
</ol>

<p>Return<em> the <strong>number</strong> of the room that held the most meetings. </em>If there are multiple rooms, return<em> the room with the <strong>lowest</strong> number.</em></p>

<p>A <strong>half-closed interval</strong> <code>[a, b)</code> is the interval between <code>a</code> and <code>b</code> <strong>including</strong> <code>a</code> and <strong>not including</strong> <code>b</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 5 * 10<sup>5</sup></code></li>
	<li>All the values of <code>start<sub>i</sub></code> are <strong>unique</strong>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

**Similar Questions**:
* [Meeting Rooms (Easy)](https://leetcode.com/problems/meeting-rooms/)
* [Meeting Rooms II (Easy)](https://leetcode.com/problems/meeting-rooms-ii/)
* [Maximum Number of Events That Can Be Attended (Easy)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)
* [Find Servers That Handled Most Number of Requests (Easy)](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)
* [Maximum Number of Events That Can Be Attended II (Easy)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

## Solution 1. Heap

Sort the meetings in ascending order of start time.

We keep a min-heap `roomsInUse` whose elements are pairs of `{end time, room number}` of those rooms in-use. The room with the earliest end time is at the top.

We scan meetings one by one. To find a room for the current meeting, we free all the rooms in `roomsInUse` that ends before the start time of the current meeting. 

There are two additional cases to consider:
1. If there is no meeting room available, and the end time of the next available room `e` is greater than the start time of the current meeting, then we must postpone the current meeting to start at `e`.
2. After postponing a meeting to start at time `e`, the subsequent meetings that starts before time `e` needs to be postponed as well to at least time `e`. So, we need to log the start time used by the previous meeting `prevStartTime`, and the next meeting's start time should be at least `prevStartTime`.

After freeing rooms, we pick the smallest room index from set `availableRooms`.

```cpp
// OJ: https://leetcode.com/problems/meeting-rooms-iii
// Author: github.com/lzl124631x
// Time: O(MlogN)
// Space: O(N)
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[0] < b[0]; });
        auto cmp = [](auto &a, auto &b) { return a[0] > b[0]; };
        priority_queue<vector<long>, vector<vector<long>>, decltype(cmp)> roomsInUse(cmp); // end time, room number. The room with the smallest end time is at the top
        vector<int> usage(n);
        long prevStartTime = -1;
        set<int> availableRooms;
        for (int i = 0; i < n; ++i) availableRooms.insert(i);
        for (auto &m : A) {
            long start = m[0], end = m[1], duration = end - start;
            if (start < prevStartTime) { // if the current start time is earlier than the previous start time, this meeting must be at least postponed to the same start time as the previous one
                start = prevStartTime;
                end = start + duration;
            }
            if (availableRooms.empty() && roomsInUse.top()[0] > start) { // if no rooms are available, and the end time of the next available meeting room is greater than start time of the current meeting, we need to postpone this current meeting
                start = roomsInUse.top()[0];
                end = start + duration;
            }
            while (roomsInUse.size() && roomsInUse.top()[0] <= start) {
                availableRooms.insert(roomsInUse.top()[1]);
                roomsInUse.pop();
            }
            prevStartTime = start;
            int room = *availableRooms.begin();
            ++usage[room];
            availableRooms.erase(room);
            roomsInUse.push({end, room});
        }
        return max_element(begin(usage), end(usage)) - begin(usage);
    }
};
```

## Solution 2. Heap

```cpp
// OJ: https://leetcode.com/problems/meeting-rooms-iii
// Author: github.com/lzl124631x
// Time: O(MlogN)
// Space: O(N)
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[0] < b[0]; });
        priority_queue<vector<long>, vector<vector<long>>, greater<>> roomsInUse; // end time, room number. The room with the smallest end time, or the smallest room number when there are multiple rooms with the same smallest end time, is at the top.
        vector<int> usage(n);
        set<int> availableRooms;
        for (int i = 0; i < n; ++i) availableRooms.insert(i);
        for (auto &m : A) {
            long start = m[0], end = m[1], room;
            while (roomsInUse.size() && roomsInUse.top()[0] <= start) {
                availableRooms.insert(roomsInUse.top()[1]);
                roomsInUse.pop();
            }
            if (availableRooms.size()) {
                room = *availableRooms.begin();
                availableRooms.erase(room);
                roomsInUse.push({end, room});
            } else {
                long time = roomsInUse.top()[0];
                room = roomsInUse.top()[1];
                roomsInUse.pop();
                roomsInUse.push({ time + end - start, room });
            }
            ++usage[room];
        }
        return max_element(begin(usage), end(usage)) - begin(usage);
    }
};
```