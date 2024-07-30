class Solution {
public:
    bool checkValidString(string str) {
        int n = str.size();
        int min = 0, max = 0;
        for(auto it: str){
            if(it == '('){
                min++;
                max++;
            }
            else if(it == ')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
            
        }
        return min == 0;
    }
};