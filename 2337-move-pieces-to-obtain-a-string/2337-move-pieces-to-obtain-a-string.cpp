class Solution {
public:
    bool canChange(string start, string target) {
        if(start.size() != target.size()) return false;
        int n = start.size();
        int i=0,j=0;
        while(i < start.size() or j < target.size()){
            while(i < n and start[i] == '_') i++;
            while(j < n and target[j] == '_') j++;
            
            if(i == n and j == n) return true;
            if(i == n or j == n) return false;
            if(start[i] != target[j]) return false;
            if(start[i] == 'L'){
                if(i < j) return false;
            }
            else{
                if(i > j) return false;
            }
            i++;
            j++;
        }
        return i == n and j == n;
    }
};