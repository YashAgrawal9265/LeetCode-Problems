class Solution {
private:
    bool solve(string start, string end){
        int n = start.size();
        int i = 0; // pointing to end string
        int j = 0; // pointing to start string
        while(i < n){
            if(end[i] == start[j]){
                i++,j++;
            }
            else if(end[i] == 'R' and start[j] == 'L' or end[i] == 'L' and start[j] == 'R'){
                return false;
            }
            else if(end[i] == 'X' and start[j] == 'L'){
                return false;
            }
            else if(end[i] == 'R' and start[j] == 'X'){
                return false;
            }
            else{
                int k = j;
                while(k < n){
                    if(k < n and start[k] == end[i]){
                        break;
                    }
                    k++;
                }
                if(k == n) return false;;
                while(k != j){
                    if(start[k-1] == 'X' and start[k] == 'L'){
                        swap(start[k],start[k-1]);
                    }
                    else if(start[k-1] == 'R' and start[k] == 'X'){
                        swap(start[k],start[k-1]);
                    }
                    else{
                        return false;
                    }
                    k--;
                }
                j++;
                i++;
            } 
        }
        return true;
    }
public:
    bool canTransform(string start, string end) {
        // cout<<solve(start,end)<<" "<<solve(end,start);
        return solve(start,end);
    }
};