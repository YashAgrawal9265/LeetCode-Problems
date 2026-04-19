class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<double,string>>> adj;
        int i = 0;
        for(auto it: equations){
            string u = it[0], v= it[1];
            adj[u].push_back({values[i],v});
          
            adj[v].push_back({1.0/values[i],u});
            i++;
        }
        vector<double> result;
        for(auto it: queries){
            unordered_set<string> vis;
            result.push_back(bfs(adj,vis,it[0],it[1]));
        }
        return result;
    }
    double bfs(unordered_map<string,vector<pair<double,string>>>& adj, unordered_set<string>& vis, string src ,string target){
        if(adj.find(src) == adj.end() || adj.find(target) == adj.end()) return -1.0;
        
        queue<pair<double,string>> q;
        q.push({1.0,src});
        vis.insert(src);
        while(!q.empty()){
            
            auto [wt,node] = q.front();
            q.pop();
           
            if(node == target) return wt;
            
            for(auto it: adj[node]){
                double childWt = it.first;
                string child = it.second;
                if(vis.find(child) == vis.end()){
                    vis.insert(child);
                    q.push({wt*childWt,child});
                }
            }
        }
        return -1.0;

    }
};