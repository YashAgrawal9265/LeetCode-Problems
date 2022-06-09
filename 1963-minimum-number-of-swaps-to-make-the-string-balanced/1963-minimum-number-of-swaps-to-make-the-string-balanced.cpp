class Solution {
public:
    int minSwaps(string str) {
        int open = 0, close = 0;
        for(int i=0;i<str.size();i++){
            if(str[i] == '[') open++;
            else{
                if(open > 0) open--;
                else close++;
            }
        }
        return (close + 1) /2;
    }
};