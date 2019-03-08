# OJ: https://leetcode.com/problems/friend-requests-i-overall-acceptance-rate/
# Author: github.com/lzl124631x
SELECT ROUND(
    IFNULL(
        (SELECT COUNT(*) FROM (SELECT DISTINCT requester_id, accepter_id FROM request_accepted) AS a)
        /
        (SELECT COUNT(*) FROM (SELECT DISTINCT sender_id, send_to_id FROM friend_request) AS b)
        , 0)
, 2) AS accept_rate