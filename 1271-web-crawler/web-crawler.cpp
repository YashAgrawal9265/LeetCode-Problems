/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    bool isMatch(string& url1, string& url2){
        int i = 0, j = 0;
        int n1 = url1.size(), n2 = url2.size();
        int slashCount = 0;
        while(i < n1 and j < n2){
            if(url1[i] == '/') slashCount++;
            if(url1[i] != url2[j] and slashCount < 3) return false;
            if(slashCount == 3) return true;
            i++,j++;
        }
        return true;
    }
    void dfs(HtmlParser htmlParser, string& url, unordered_map<string,int>& vis, vector<string>& result){
        vis[url] = 1;
        result.push_back(url);
        for(auto it: htmlParser.getUrls(url)){
            // cout<<it<<endl;
            if(vis.find(it) == vis.end() and isMatch(url,it)){
                dfs(htmlParser,it,vis,result);
            }
        }
        
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_map<string,int> vis;
        vector<string> result;
        dfs(htmlParser,startUrl,vis,result);
        return result;
    }
};