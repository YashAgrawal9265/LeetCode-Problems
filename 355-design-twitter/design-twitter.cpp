class Ele{
public:
    int count;
    int tweetId;
    int userId;
    int idx;
    Ele(int count, int tweetId, int userId, int idx){
        this->count = count;
        this->tweetId = tweetId;
        this->userId = userId;
        this->idx = idx;
    }
};
struct cmp{
    bool operator()(Ele a, Ele b){
        return a.count < b.count;
    }
};
class Twitter {
private:
    unordered_map<int,unordered_set<int>> userMap;
    unordered_map<int,vector<pair<int,int>>> tweetMap;
    int count;
public:
    Twitter() {
        userMap.clear();
        tweetMap.clear();
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count,tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Ele, vector<Ele>, cmp> pq;
        userMap[userId].insert(userId);
       
        for(auto followers: userMap[userId]){
            if(tweetMap[followers].size() > 0){
                int index = tweetMap[followers].size() - 1;
                int count = tweetMap[followers][index].first;
                int tweetId = tweetMap[followers][index].second;
                pq.push(Ele(count,tweetId,followers,index));
            }
           
        }
        vector<int> result;
        while(!pq.empty() and result.size() < 10){
            auto [count,tweetId,userId,index] = pq.top();
            pq.pop();
            if(index - 1 >= 0){
                int count = tweetMap[userId][index-1].first;
                int tweetId = tweetMap[userId][index-1].second;
                pq.push(Ele(count,tweetId,userId,index-1));
            }
            result.push_back(tweetId);
        }
        
        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        userMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(userMap[followerId].find(followeeId) != userMap[followerId].end()){
            userMap[followerId].erase(followeeId);
        }
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