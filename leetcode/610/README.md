# [610. Triangle Judgement (Easy)](https://leetcode.com/problems/triangle-judgement/)

A pupil Tim gets homework to identify whether three line segments could possibly form a triangle.<p></p> However, this assignment is very heavy because there are hundreds of records to calculate.<p></p>
 
Could you help Tim by writing a query to judge whether these three sides can form a triangle, assuming table <code>triangle</code> holds the length of the three sides x, y and z.<p></p>
 
<pre>| x  | y  | z  |
|----|----|----|
| 13 | 15 | 30 |
| 10 | 20 | 15 |
</pre>
 
For the sample data above, your query should return the follow result:
<pre>| x  | y  | z  | triangle |
|----|----|----|----------|
| 13 | 15 | 30 | No       |
| 10 | 20 | 15 | Yes      |
</pre>

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/triangle-judgement/
# Author: github.com/lzl124631x
SELECT
    x, y, z,
    CASE
        WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes'
        ELSE 'No'
    END AS 'triangle'
FROM
    triangle
```