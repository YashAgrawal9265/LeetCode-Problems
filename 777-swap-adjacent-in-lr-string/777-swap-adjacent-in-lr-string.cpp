class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0; // pointing to start string;
        int j = 0; // poiting to end string;
        while(i < n or j < n){
            while(start[i] == 'X') i++;
            while(end[j] == 'X') j++;
            if(i == n and j == n) return true;
            if(i == n or j == n) return false;
            if(start[i] != end[j]) return false;
            if(start[i] == 'L' and i < j) return false;
            if(start[i] == 'R' and i > j) return false;
            i++;
            j++;
        }
        return true;
    }
};