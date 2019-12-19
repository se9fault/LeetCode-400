/*
Design a simplified version of Twitter where users can post tweets,
follow/unfollow another user and is able to see the 10 most recent tweets in the
user's news feed. Your design should support the following methods:

postTweet(userId, tweetId) : Compose a new tweet.
getNewsFeed(userId) : Retrieve the 10 most recent tweet ids in the user's news
feed. Each item in the news feed must be posted by users who the user followed
or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId) : Follower follows a followee.
unfollow(followerId, followeeId) : Follower unfollows a followee.

Example:
Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

class Twitter {
public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto id : friends[userId]) {
            for (auto a : tweets[id]) {
                if (q.size() > 0 && q.top().first > a.first && q.size() > 10)
                    break;
                q.push(a);
                if (q.size() > 10)
                    q.pop();
            }
        }
        while (!q.empty()) {
            res.insert(res.begin(), q.top().second);
            q.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            friends[followerId].erase(followeeId);
        }
    }

private:
    int time;
    unordered_map<int, unordered_set<int>> friends;
    unordered_map<int, vector<pair<int, int>>> tweets;
};