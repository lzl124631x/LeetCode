# OJ: https://leetcode.com/problems/duplicate-emails/
# Author: github.com/lzl124631x
select Email from
(
  select Email, count(Email) as num
  from Person
  group by Email
) as statistic
where num > 1