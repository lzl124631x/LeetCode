# OJ: https://leetcode.com/problems/find-customer-referee/
# Author: github.com/lzl124631x
SELECT
    name
FROM
    customer
WHERE
    reference_id <> 2 OR reference_id IS NULL