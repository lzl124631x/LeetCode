# [175. Combine Two Tables (Easy)](https://leetcode.com/problems/combine-two-tables/)

<p>Table: <code>Person</code></p>

<pre>+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
PersonId is the primary key column for this table.
</pre>

<p>Table: <code>Address</code></p>

<pre>+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
AddressId is the primary key column for this table.
</pre>

<p>&nbsp;</p>

<p>Write a SQL query for a report that provides the following information for each person in the Person table, regardless if there is an address for each of those people:</p>

<pre>FirstName, LastName, City, State
</pre>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Similar Questions**:
* [Employee Bonus (Easy)](https://leetcode.com/problems/employee-bonus/)

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/combine-two-tables/
# Author: github.com/lzl124631x
SELECT FirstName, LastName, City, State
FROM Person LEFT JOIN Address
ON Person.PersonId = Address.PersonId
```