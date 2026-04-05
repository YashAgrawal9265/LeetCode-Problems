/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int dfs(unordered_map<int,Employee*> adj, int node, unordered_map<int,int>& vis){
        vis[node] = 1;
        int sum = adj[node]->importance;
        for(auto it: adj[node]->subordinates){
            if(!vis[it]) sum += dfs(adj,it,vis);
        }
        return sum;
    }
    int getImportance(vector<Employee*> arr, int id) {
        unordered_map<int,Employee*> adj;
        
        for(auto it: arr){
            adj[it->id] = it;
        }
        unordered_map<int,int> vis;
        return dfs(adj,id,vis);
    }
};