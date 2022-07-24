struct cmp{
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const{
        if(a.first != b.first){
            return a.first > b.first;
        }
        
        return a.second < b.second;
        
    }
};
class FoodRatings {
private:
    unordered_map<string,string> mp1;
    unordered_map<string,int> mp2;
    map<string,set<pair<int,string>,cmp>> mp3;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisine, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            mp1[foods[i]] = cuisine[i];
            mp2[foods[i]] = ratings[i];
            mp3[cuisine[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int old_rating = mp2[food];
        string cuisine = mp1[food];
        mp3[cuisine].erase({old_rating,food});
        mp2[food] = newRating;
        mp3[cuisine].insert({newRating,food});
                         
    }
    
    string highestRated(string cuisine) {
        return mp3[cuisine].begin()->second;
    }
};