class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> adj[n];
        vector<int> cntEdges(n,0);
        for(auto it: edges){
            int u = it[0], v= it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            cntEdges[u]++;
            cntEdges[v]++;
        }
        queue<int> leaves;
        for(int i=0;i<n;i++){
            if(cntEdges[i] == 1){
                leaves.push(i);
            }
        }
        int remainingNodes = n;
        while(!leaves.empty()){
            int size = leaves.size();
            if(remainingNodes <= 2){
                break;
            }
            while(size--){
                remainingNodes--;
                int node = leaves.front();
                leaves.pop();
                for(auto it: adj[node]){
                    cntEdges[it]--;
                    if(cntEdges[it] == 1){
                        leaves.push(it);
                    }
                }
            }
            
        }
        vector<int> result;
        while(!leaves.empty()){
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};