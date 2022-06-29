class Solution {
private:
    int calculateXor(vector<int> adj[], int node, int parent, vector<int>& subTreeXor){
        int childXor = 0;
        for(auto it: adj[node]){
            if(it != parent){
                childXor ^= calculateXor(adj,it,node,subTreeXor);
            }
        }
        subTreeXor[node] ^= childXor;
        return subTreeXor[node];
    }
private:
    int solve(vector<int> adj[], vector<int>& nums, int node, int parent, int& first, int& remXor, int& result){
        int childXor = 0;
        for(auto it: adj[node]){
            if(it != parent){
                int second = solve(adj,nums,it,node,first,remXor,result);
                int third = remXor ^ second;
                int score = max(first,max(second,third)) - min(first,min(second,third));
                result = min(result,score);
                childXor ^= second;
            }
        }
        return nums[node] ^ childXor;
        
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> subTreeXor(nums.begin(),nums.end());
        int totalXor = calculateXor(adj,0,-1,subTreeXor);
        queue<pair<int,int>> q;
        q.push({0,-1});
        
        int result = INT_MAX;
        while(!q.empty()){
            auto [node,parent] = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(it != parent){
                    q.push({it,node});
                    int first = subTreeXor[it];
                    int rem = totalXor ^ first;
                    solve(adj,nums,node,it,first,rem,result);
                }
            }
        }
        return result;
    }
};