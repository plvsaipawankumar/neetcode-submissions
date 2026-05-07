class Twitter {
private :
    
public:
    Twitter() {
        
    }
    map<int,vector<pair<int,int>>> tweetStore;
    map<int,set<int>> userConnection;
    //std::vector<std::vector<int>> userConnection(101,vector<int>(1,0));

    int timer=0;
    void postTweet(int userId, int tweetId) {
        tweetStore[userId].push_back({timer,tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>> priority_tweet;
        int i,j,m,n=userConnection[userId].size();
        for(auto i : userConnection[userId])
        {
            if(i==userId)continue;
            m=tweetStore[i].size();
            for(j=0;j<m;j++)
                priority_tweet.push(tweetStore[i][j]);
        }

        for(i=0;i<tweetStore[userId].size();i++)
            priority_tweet.push(tweetStore[userId][i]);

        i=0;
        while(i<10 && !priority_tweet.empty())
        {
            ans.push_back(priority_tweet.top().second);
            priority_tweet.pop();
            i++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        userConnection[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userConnection[followerId].erase(followeeId);
    }
};
