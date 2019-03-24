# [570. Managers with at Least 5 Direct Reports (Medium)](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/)

<p>The <code>Employee</code> table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.</p>

<pre>+------+----------+-----------+----------+
|Id    |Name 	  |Department |ManagerId |
+------+----------+-----------+----------+
|101   |John 	  |A 	      |null      |
|102   |Dan 	  |A 	      |101       |
|103   |James 	  |A 	      |101       |
|104   |Amy 	  |A 	      |101       |
|105   |Anne 	  |A 	      |101       |
|106   |Ron 	  |B 	      |101       |
+------+----------+-----------+----------+
</pre>

<p>Given the <code>Employee</code> table, write a SQL query that finds out managers with at least 5 direct report. For the above table, your SQL query should return:</p>

<pre>+-------+
| Name  |
+-------+
| John  |
+-------+
</pre>

<p><b>Note:</b><br>
No one would report to himself.</p>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg)

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/managers-with-at-least-5-direct-reports/
# Author: github.com/lzl124631x
SELECT Name
FROM Employee AS a JOIN
    (SELECT ManagerId
    FROM Employee
    GROUP BY ManagerId
    HAVING Count(ManagerId) >= 5) as b
    ON a.Id = b.ManagerId
```