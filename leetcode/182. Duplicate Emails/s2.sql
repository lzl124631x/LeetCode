# OJ: https://leetcode.com/problems/duplicate-emails/
# Author: github.com/lzl124631x
select Email
from Person
group by Email
having count(Email) > 1;