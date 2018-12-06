# [355. Design Twitter (Medium)](https://leetcode.com/problems/design-twitter/)

<p>Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:</p>

<p>
</p><ol>
<li><b>postTweet(userId, tweetId)</b>: Compose a new tweet.</li>
<li><b>getNewsFeed(userId)</b>: Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.</li>
<li><b>follow(followerId, followeeId)</b>: Follower follows a followee.</li>
<li><b>unfollow(followerId, followeeId)</b>: Follower unfollows a followee.</li>
</ol>
<p></p>

<p><b>Example:</b>
</p><pre>Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -&gt; [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -&gt; [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -&gt; [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
</pre>
<p></p>

**Companies**:  
[Twitter](https://leetcode.com/company/twitter), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Heap](https://leetcode.com/tag/heap/), [Design](https://leetcode.com/tag/design/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-twitter/
// Author: github.com/lzl124631x
// Time:
//     * Twitter: O(1)
//     * getNewsFeed: O(F)
//     * follow: O(1)
//     * unfollow: O(1)
// Space: O(F + R) where F is number of feeds, R is count of follower-followee relationships.
class Twitter {
private:
    deque<pair<int, int>> feeds;
    unordered_map<int, unordered_set<int>> followerToFollowee;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        feeds.push_front(make_pair(userId, tweetId));
    }
    vector<int> getNewsFeed(int userId) {
        vector<int> v;
        auto it = feeds.begin();
        auto &followees = followerToFollowee[userId];
        int cnt = 0;
        while (it != feeds.end() && cnt < 10) {
            int posterId = it->first;
            if (posterId == userId
            || followees.find(posterId) != followees.end()) {
                v.push_back(it->second);
                ++cnt;
            }
            ++it;
        }
        return v;
    }
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followerToFollowee[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followerToFollowee[followerId].erase(followeeId);
    }
};
```