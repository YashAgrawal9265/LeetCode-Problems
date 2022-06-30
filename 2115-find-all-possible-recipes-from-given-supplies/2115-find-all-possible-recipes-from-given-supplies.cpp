class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supp(supplies.begin(),supplies.end());
        
        vector<string> result;
        
        int n = recipes.size();
        vector<int> vis(n,0);
        int x = supp.size();
        while(true){
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                bool flag = true;
                for(auto &it: ingredients[i]){
                    if(supp.find(it) == supp.end()){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    vis[i] = 1;
                    result.push_back(recipes[i]);
                    supp.insert(recipes[i]);
                }
            }
            if(supp.size() == x) break;
            else x = supp.size();
        }
        
        return result;
    }
};