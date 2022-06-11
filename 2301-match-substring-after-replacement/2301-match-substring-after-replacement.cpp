class Solution { 
public: 
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) { 
        unordered_map<char,unordered_set<char>> mp; 
         
        for(auto it : mappings){
             mp[it[0]].insert(it[1]); 
        }
           
         int m = sub.size();
        vector<string> result; 
         
        for(int i = 0 ; i <= s.size()-m; i++){
            result.push_back(s.substr(i,m)); 
        }
            
         
        for(auto it : result) 
        { 
            bool flag = true; 
            int i = 0; 
            while(i < m) 
            { 
                if(sub[i] != it[i]) 
                { 
                    if(mp[sub[i]].find(it[i]) == mp[sub[i]].end()) 
                    { 
                        flag = false; 
                        break; 
                    } 
                } 
                i++; 
            } 
            if(flag){
                 return true; 
            }
               
        } 
        return false; 
    } 
};