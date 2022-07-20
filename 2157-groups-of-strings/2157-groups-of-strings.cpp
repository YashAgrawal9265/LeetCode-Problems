class DisjointSet{
public:
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    void Union(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(size[u] > size[v]){
            parent[v] = u;
            size[u] += size[v];
        }
        else{
            parent[u] = v;
            size[v] += size[u];
        }
    }
    int getSize(int u){
        u = findParent(u);
        return size[u];
    }
};
class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[&](string& a, string& b){
            return a.size() < b.size();
        });
        DisjointSet dst(n);
        unordered_map<int,int> mp, del_mp;
        for(int idx=0;idx<words.size();idx++){
            int hash = 0;
            for(auto it: words[idx]){
                hash |= (1 << (it-'a'));
            }
            // deletion operation
            for(auto it: words[idx]){
                int t_hash = hash;
                int mask = (1 << (it-'a'));
                t_hash = t_hash & (~mask);
                if(mp.find(t_hash) != mp.end()and dst.findParent(mp[t_hash]) != dst.findParent(idx)){
                    dst.Union(mp[t_hash],idx);
                }
                if(del_mp.find(t_hash) != del_mp.end()and dst.findParent(del_mp[t_hash]) != dst.findParent(idx)) dst.Union(del_mp[t_hash],idx);
                else del_mp[t_hash] = idx;
                // hash |= mask;
            }
            
            // Replacement operation
            // for(char c='a'; c<='z'; c++){
            //     for(auto it: words[idx]){
            //         int t_hash = hash;
            //         int mask = (1 << (it-'a'));
            //         t_hash = t_hash & (~mask);
            //         t_hash |= (1 << (c-'a'));
            //         if(mp.find(t_hash) != mp.end() and dst.findParent(mp[t_hash]) != dst.findParent(idx)){
            //             dst.Union(mp[t_hash],idx);
            //         }
            //         // hash |= mask;
            //         // hash &= (1 << (c-'a'));
            //     }
            // }
            mp[hash] = idx;
        }
        int group = 0, mxSize = 0;
        for(int i=0;i<n;i++){
            if(dst.parent[i] == i){
                group++;
                mxSize = max(mxSize,dst.getSize(i));
            }
        }
        return {group,mxSize};
    }
};