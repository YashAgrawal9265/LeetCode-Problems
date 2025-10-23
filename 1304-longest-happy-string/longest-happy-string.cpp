class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});

        string result = "";
        while(!pq.empty()){
            char c = pq.top().second;
            int count = pq.top().first;
            pq.pop();
            int n = result.size();
            if(n > 1 and result[n-1] == c and result[n-2] == c){
                if(pq.empty()){
                    break;
                }
                else{
                    char c2 = pq.top().second;
                    int count2 = pq.top().first;
                    pq.pop();
                    result += c2;
                    if(count2 -1 > 0) pq.push({count2-1,c2});
                }
            }
            result += c;
            if(count -1 > 0) pq.push({count-1,c});
        }
        return result;
    }
};