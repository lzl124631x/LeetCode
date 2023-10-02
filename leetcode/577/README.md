# [577. Employee Bonus (Easy)](https://leetcode.com/problems/employee-bonus/)

<p>
Select all employee's name and bonus whose bonus is &lt; 1000.
</p>
<p>
Table:<code>Employee </code>
</p>

<pre>+-------+--------+-----------+--------+
| empId |  name  | supervisor| salary |
+-------+--------+-----------+--------+
|   1   | John   |  3        | 1000   |
|   2   | Dan    |  3        | 2000   |
|   3   | Brad   |  null     | 4000   |
|   4   | Thomas |  3        | 4000   |
+-------+--------+-----------+--------+
empId is the primary key column for this table.
</pre>

<p>
Table: <code>Bonus</code></p>
<pre>+-------+-------+
| empId | bonus |
+-------+-------+
| 2     | 500   |
| 4     | 2000  |
+-------+-------+
empId is the primary key column for this table.
</pre>
<p>
Example ouput: 
</p>
<pre>+-------+-------+
| name  | bonus |
+-------+-------+
| John  | null  |
| Dan   | 500   |
| Brad  | null  |
+-------+-------+
</pre>

**Companies**:  
[Netsuite](https://leetcode.com/company/netsuite)

**Similar Questions**:
* [Combine Two Tables (Easy)](https://leetcode.com/problems/combine-two-tables/)

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/employee-bonus/
# Author: github.com/lzl124631x
SELECT
    Employee.name, Bonus.bonus
FROM
    Employee LEFT JOIN Bonus
    ON Employee.empId = Bonus.empId
WHERE
    bonus < 1000 OR bonus IS NULL
```