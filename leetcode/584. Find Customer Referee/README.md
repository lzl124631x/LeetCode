# [584. Find Customer Referee (Easy)](https://leetcode.com/problems/find-customer-referee/)

<p>Given a table <code>customer</code> holding customers information and the referee.</p>

<pre>+------+------+-----------+
| id   | name | referee_id|
+------+------+-----------+
|    1 | Will |      NULL |
|    2 | Jane |      NULL |
|    3 | Alex |         2 |
|    4 | Bill |      NULL |
|    5 | Zack |         1 |
|    6 | Mark |         2 |
+------+------+-----------+
</pre>

<p>Write a query to return the list of customers <b>NOT</b> referred by the person with id '2'.</p>

<p>For the sample data above, the result is:</p>
<pre>+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+
</pre>

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/find-customer-referee/
# Author: github.com/lzl124631x
SELECT
    name
FROM
    customer
WHERE
    referee_id <> 2 OR referee_id IS NULL
```