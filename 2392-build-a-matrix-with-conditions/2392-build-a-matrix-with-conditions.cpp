class Solution {
private:
    bool topoSort(vector<int> adj[], int k,vector<int>& result){
        vector<int> indegree(k+1);
        for(int i=1;i<=k;i++){
            for(auto it: adj[i]) indegree[it]++;
        }
        queue<int> q;
        for(int i=1;i<=k;i++)
            if(indegree[i] == 0) 
                q.push(i);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return result.size() == k;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<int> adj1[k+1], adj2[k+1];
        for(auto it: row){
            adj1[it[0]].push_back(it[1]);
        }
        for(auto it: col){
            adj2[it[0]].push_back(it[1]);
        }
        vector<int> topoRow, topoCol;
        if(!topoSort(adj1,k,topoRow) or !topoSort(adj2,k,topoCol)) return {};
        
        unordered_map<int,int> row_idx, col_idx;
        for(int i=0;i<topoRow.size();i++){
            row_idx[topoRow[i]] = i;
            col_idx[topoCol[i]] = i;
        }
        
        vector<vector<int>> result(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            result[row_idx[i]][col_idx[i]] = i;
        }
        return result;
        
    }
};