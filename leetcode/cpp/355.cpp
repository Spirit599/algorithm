struct tweetInfo
{
    int time;
    int tweetId;
};
struct pqInfo
{
    int time;
    int tweetId;
    int index;
    vector<tweetInfo>* vecPtr;
};


bool cmp(const pqInfo& pq1, const pqInfo& pq2) {
        return pq1.time < pq2.time;
}

class Twitter {
public:
    

    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, vector<tweetInfo>> tweetList;
    int time = 0;
    
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {

        tweetList[userId].push_back({time++, tweetId});
    }

    
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<pqInfo, vector<pqInfo>, decltype(&cmp)> pq(cmp);
        followList[userId].insert(userId);
        for(int user : followList[userId])
        {
            auto it = tweetList.find(user);
            if(it == tweetList.end())
                continue;
            if(it->second.size() == 0)
                continue;
            int index = it->second.size() - 1;
            pq.push({it->second[index].time, it->second[index].tweetId, index, &(it->second)});
        }

        vector<int> ret;
        int n = 10; 
        
        while(!pq.empty() && n--)
        {
            auto cur = pq.top();
            pq.pop();
            ret.push_back(cur.tweetId);

            int index = cur.index;
            printf("%d\n", (*(cur.vecPtr)).size());
            if(index == 0)
                continue;
            --index;

            pq.push({(*(cur.vecPtr))[index].time, (*(cur.vecPtr))[index].tweetId, index, cur.vecPtr});
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {

        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {

        followList[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */