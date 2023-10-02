# [911. Online Election (Medium)](https://leetcode.com/problems/online-election/)

<p>In an election, the <code>i</code>-th&nbsp;vote was cast for <code>persons[i]</code> at time <code>times[i]</code>.</p>

<p>Now, we would like to implement the following query function: <code>TopVotedCandidate.q(int t)</code> will return the number of the person that was leading the election at time <code>t</code>.&nbsp;&nbsp;</p>

<p>Votes cast at time <code>t</code> will count towards our query.&nbsp; In the case of a tie, the most recent vote (among tied candidates) wins.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["TopVotedCandidate","q","q","q","q","q","q"]</span>, <span id="example-input-1-2">[[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]</span>
<strong>Output: </strong><span id="example-output-1">[null,0,1,1,0,0,1]</span>
<strong>Explanation: </strong>
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= persons.length = times.length &lt;= 5000</code></li>
	<li><code>0 &lt;= persons[i] &lt;= persons.length</code></li>
	<li><code>times</code>&nbsp;is a strictly increasing array with all elements in <code>[0, 10^9]</code>.</li>
	<li><code>TopVotedCandidate.q</code> is called at most <code>10000</code> times per test case.</li>
	<li><code>TopVotedCandidate.q(int t)</code> is always called with <code>t &gt;= times[0]</code>.</li>
</ol>
</div>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/online-election/
// Author: github.com/lzl124631x
// Time:
//     TopVotedCandidate: O(N)
//     q: O(logN)
// Space: O(N)
class TopVotedCandidate {
private:
    vector<int> winners;
    vector<int> times;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times): times(times) {
        unordered_map<int, int> m;
        int winner = 0;
        for (int p : persons) {
            m[p]++;
            if (m[p] >= m[winner]) winner = p;
            winners.push_back(winner);
        }
    }
    
    int q(int t) {
        int n = upper_bound(times.begin(), times.end(), t) - times.begin();
        return winners[n - 1];
    }
};
```