# [597. Friend Requests I: Overall Acceptance Rate (Easy)](https://leetcode.com/problems/friend-requests-i-overall-acceptance-rate/)

In social network like Facebook or Twitter, people send friend requests and accept others’ requests as well. Now given two tables as below:
<p>&nbsp;</p>
Table: <code>friend_request</code>

<pre>| sender_id | send_to_id |request_date|
|-----------|------------|------------|
| 1         | 2          | 2016_06-01 |
| 1         | 3          | 2016_06-01 |
| 1         | 4          | 2016_06-01 |
| 2         | 3          | 2016_06-02 |
| 3         | 4          | 2016-06-09 |
</pre>

<p>&nbsp;</p>
Table: <code>request_accepted</code>

<pre>| requester_id | accepter_id |accept_date |
|--------------|-------------|------------|
| 1            | 2           | 2016_06-03 |
| 1            | 3           | 2016-06-08 |
| 2            | 3           | 2016-06-08 |
| 3            | 4           | 2016-06-09 |
| 3            | 4           | 2016-06-10 |
</pre>

<p>&nbsp;</p>
Write a query to find the overall acceptance rate of requests rounded to 2 decimals, which is the number of acceptance divide the number of requests.

<p>&nbsp;</p>
For the sample data above, your query should return the following result.

<p>&nbsp;</p>

<pre>|accept_rate|
|-----------|
|       0.80|
</pre>

<p>&nbsp;</p>
<b>Note:</b>

<ul>
	<li>The accepted requests are not necessarily from the table <code>friend_request</code>. In this case, you just need to simply count the total accepted requests (no matter whether they are in the original requests), and divide it by the number of requests to get the acceptance rate.</li>
	<li>It is possible that a sender sends multiple requests to the same receiver, and a request could be accepted more than once. In this case, the ‘duplicated’ requests or acceptances are only counted once.</li>
	<li>If there is no requests at all, you should return 0.00 as the accept_rate.</li>
</ul>

<p>&nbsp;</p>
<b>Explanation:</b> There are 4 unique accepted requests, and there are 5 requests in total. So the rate is 0.80.

<p>&nbsp;</p>
<b>Follow-up:</b>

<ul>
	<li>Can you write a query to return the accept rate but for every month?</li>
	<li>How about the cumulative accept rate for every day?</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/friend-requests-i-overall-acceptance-rate/
# Author: github.com/lzl124631x
SELECT ROUND(
    IFNULL(
        (SELECT COUNT(*) FROM (SELECT DISTINCT requester_id, accepter_id FROM request_accepted) AS a)
        /
        (SELECT COUNT(*) FROM (SELECT DISTINCT sender_id, send_to_id FROM friend_request) AS b)
        , 0)
, 2) AS accept_rate
```