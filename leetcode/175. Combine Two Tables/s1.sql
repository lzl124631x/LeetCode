# OJ: https://leetcode.com/problems/combine-two-tables/
# Author: github.com/lzl124631x
SELECT FirstName, LastName, City, State
FROM Person LEFT JOIN Address
ON Person.PersonId = Address.PersonId