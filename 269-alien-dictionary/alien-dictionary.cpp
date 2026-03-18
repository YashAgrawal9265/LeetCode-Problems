class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        vector<int> adj[26];
        vector<int> charMap(26,0);
        int nodeCount = 0;
        for(auto it: words){
            for(auto i: it){
                if(charMap[i-'a'] == 1) continue;
                charMap[i - 'a'] = 1;
                nodeCount++;
            }
        }
        unordered_map<char,int> indegree;
        for(int i=0;i<26;i++){
            if(charMap[i] == 1){
                indegree[i + 'a'] = 0;
            }
        }
        for(int k=0;k<n-1;k++){
            string str1 = words[k];
            string str2 = words[k+1];
            int i =0, j = 0;
            if(str1.size() > str2.size() and str1.substr(0,str2.size()) == str2) return "";
            while(i < str1.size() and j < str2.size()){
                if(str1[i] != str2[j]){
                    adj[str1[i] - 'a'].push_back(str2[j] - 'a');
                    indegree[str2[j]]++;
                    break;
                }
                i++,j++;
            }
        }
        
        queue<char> q;
        
        for(auto it: indegree){
            if(it.second == 0) q.push(it.first);
        }
        string result = "";
        while(!q.empty()){
            char node = q.front();
            q.pop();
            result += node;
            for(auto it: adj[node - 'a']){
                indegree[it + 'a']--;
                if(indegree[it + 'a'] == 0) q.push(it + 'a');
            }
        }
        // cout<<result<<endl;
        return result.size() != nodeCount ? "" : result;
    }
};