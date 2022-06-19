class WordFilter {
private:
    unordered_map<string,int> mp;
public:
    WordFilter(vector<string>& words) {
        int idx = 0;
        for(auto &it: words){
            int n = it.size();
            string str = it;
            for(int i=0;i<n;i++){
                string pre = str.substr(0,i+1);
                for(int j=n-1;j>=0;j--){
                    string suf = str.substr(j);
                    mp[pre + "#" + suf] = idx;
                }
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        string temp = prefix + "#" + suffix;
        if(mp.find(temp) == mp.end()) return -1;
        return mp[temp];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */