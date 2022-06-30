class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingre, vector<string>& supplies) {
        unordered_set<string> supp(supplies.begin(),supplies.end());
        int n = recipes.size();
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indegree;
        for(auto &it: recipes){
            indegree[it] = 0;
        }
        
        for(int i=0;i<n;i++){
            for(auto &it: ingre[i]){
                if(supp.find(it) == supp.end()){
                    adj[it].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        vector<string> result;
        queue<string> q;
        for(auto &it: indegree){
            if(it.second == 0){
                q.push(it.first);
                result.push_back(it.first);
            }
        }
        
        while(!q.empty()){
            string node = q.front();
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    result.push_back(it);
                }
            }
        }
        return result;
    }
};