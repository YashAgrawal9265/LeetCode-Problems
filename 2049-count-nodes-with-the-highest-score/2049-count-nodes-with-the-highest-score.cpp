class Solution {
public:
    int dfs(vector<int> adj[], int node, int parent, vector<int>& size){
        for(auto it: adj[node]){
            if(it != parent){
                size[node] += dfs(adj,it,node,size);
            }
        }
        return size[node];
    }
    int countHighestScoreNodes(vector<int>& p) {
        int n = p.size();
        vector<int> adj[n];
        for(int i=1;i<n;i++){
            int u = p[i], v = i;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> size(n,1);
        dfs(adj,0,-1,size);
        
        long long mxScore = INT_MIN;
        int result = 0;
      
        for(int i=0;i<n;i++){
            long long score = 1;
            for(auto it: adj[i]){
                if(it == p[i]) score *= (size[0]-size[i]);
                else score *= size[it];
            }
            // cout<<i<<" "<<score<<endl;
            if(score > mxScore){
                mxScore = score;
                result = 1;
            }
            else if(score == mxScore) result++;
        }
        
        return result;
    }
};