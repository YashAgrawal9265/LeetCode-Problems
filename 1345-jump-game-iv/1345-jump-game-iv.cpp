class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<int> vis(n,0);
        
        // {node,jump}
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0] = 1;
        while(!q.empty()){
            auto [node,jump] = q.front();
            q.pop();
            if(node == n-1) return jump;
            vector<int>& next = mp[arr[node]];
            next.push_back(node-1);
            next.push_back(node+1);
            for(auto it: next){
                if(it >= 0 and it < n and !vis[it]){
                    vis[it] = 1;
                    q.push({it,jump+1});
                }
            }
            next.clear();
        }
        return -1;
    }
};