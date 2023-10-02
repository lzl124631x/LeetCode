# [603. Consecutive Available Seats (Easy)](https://leetcode.com/problems/consecutive-available-seats/)

Several friends at a cinema ticket office would like to reserve consecutive available seats.<br>
Can you help to query all the consecutive available seats order by the seat_id using the following <code>cinema</code> table?

<pre>| seat_id | free |
|---------|------|
| 1       | 1    |
| 2       | 0    |
| 3       | 1    |
| 4       | 1    |
| 5       | 1    |
</pre><p></p>

Your query should return the following result for the sample case above.<p></p>
<pre>| seat_id |
|---------|
| 3       |
| 4       |
| 5       |
</pre>

<b>Note</b>:
<li>The seat_id is an auto increment int, and free is bool ('1' means free, and '0' means occupied.).</li>
<li>Consecutive available seats are more than 2(inclusive) seats consecutively available.</li>
<p></p>

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/consecutive-available-seats/
# Author: github.com/lzl124631x
SELECT DISTINCT
    a.seat_id
FROM
    cinema a JOIN cinema b
    ON ABS(a.seat_id - b.seat_id) = 1
    and a.free = true and b.free = true
ORDER BY a.seat_id
```