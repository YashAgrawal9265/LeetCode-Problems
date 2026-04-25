class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        int farthest = 0;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // int l = node + minJump;
            int l = max(node+minJump, farthest+1);
            for(int i=l;i<=min(node+maxJump,n-1);i++){
                if(s[i] == '0'){
                    q.push(i);
                    if(i == n-1) return true;
                }
            }
            farthest = node + maxJump;
        }
        return false;
    }
};