# OJ: https://leetcode.com/problems/managers-with-at-least-5-direct-reports/
# Author: github.com/lzl124631x
SELECT Name
FROM Employee AS a JOIN
    (SELECT ManagerId
    FROM Employee
    GROUP BY ManagerId
    HAVING Count(ManagerId) >= 5) as b
    ON a.Id = b.ManagerId