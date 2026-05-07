class Twitter {
private :
    
public:
    Twitter() {
        
    }
    map<int,vector<pair<int,int>>> tweetStore;
    map<int,vector<int>> userConnection;
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
        for(i=0;i<n;i++)
        {
            if(userConnection[userId][i]==userId)continue;
            m=tweetStore[userConnection[userId][i]].size();
            for(j=0;j<m;j++)
                priority_tweet.push(tweetStore[userConnection[userId][i]][j]);
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
        int i,n=userConnection[followerId].size();
        for(i=0;i<n;i++)
        {
            if(userConnection[followerId][i]==followeeId)
                return ;
        }
        userConnection[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        cout<<"followerId : "<<followerId<<" followeeId : "<<followeeId<<endl;
        int i,n= userConnection[followerId].size();
        for(i=0;i<n;i++)
        {
            if(userConnection[followerId][i]==followeeId)
            {
                userConnection[followerId].erase(userConnection[followerId].begin()+i);
                break;
            }
        }
    }
};
