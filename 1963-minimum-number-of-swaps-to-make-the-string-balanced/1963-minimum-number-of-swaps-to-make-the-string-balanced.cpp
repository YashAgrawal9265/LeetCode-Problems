class Solution {
public:
    int minSwaps(string str) {
        int open = 0, close = 0;
        for(auto it: str){
            if(it == '[') open++;
            else{
                if(open > 0) open--;
                else close++;
            }
        }
        return (close + 1) / 2;
    }
};