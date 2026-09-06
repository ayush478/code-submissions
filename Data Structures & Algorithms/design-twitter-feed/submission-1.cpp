class Twitter {
   public:
    int timestamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> userTweets;

    Twitter() { timestamp = 0; }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // {timestamp, {userId, index}}
        priority_queue<pair<int, pair<int, int>>> pq;

        // User's own latest tweet
        if (!userTweets[userId].empty()) {
            int index = userTweets[userId].size() - 1;

            pq.push({userTweets[userId][index].first, {userId, index}});
        }

        // Latest tweet of each followee
        for (int followeeId : following[userId]) {
            if (!userTweets[followeeId].empty()) {
                int index = userTweets[followeeId].size() - 1;

                pq.push({userTweets[followeeId][index].first, {followeeId, index}});
            }
        }

        vector<int> res;

        while (!pq.empty() && res.size() < 10) {
            auto top = pq.top();
            pq.pop();

            int timestamp = top.first;
            int user = top.second.first;
            int index = top.second.second;

            // Add tweet to result
            res.push_back(userTweets[user][index].second);

            // Add next older tweet from same user
            if (index > 0) {
                index--;

                pq.push({userTweets[user][index].first, {user, index}});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) { following[followerId].erase(followeeId); }
};