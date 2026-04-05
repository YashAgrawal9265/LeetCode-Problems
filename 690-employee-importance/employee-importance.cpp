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
    int dfs(unordered_map<int,vector<int>> adj, int node, unordered_map<int,int>& imp, unordered_map<int,int>& vis){
        vis[node] = 1;
        int sum = imp[node];
        for(auto it: adj[node]){
            if(!vis[it]) sum += dfs(adj,it,imp,vis);
        }
        return sum;
    }
    int getImportance(vector<Employee*> arr, int id) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> imp;
                
        for(auto it: arr){
            int id = it->id, nodeImportance = it->importance;
            imp[id] = nodeImportance;
            for(auto i: it->subordinates){
                adj[id].push_back(i);
            }
            
        }
        unordered_map<int,int> vis;
        return dfs(adj,id,imp,vis);
    }
};