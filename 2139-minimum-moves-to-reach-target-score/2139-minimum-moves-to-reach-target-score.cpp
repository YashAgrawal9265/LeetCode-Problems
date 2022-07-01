class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int result = 0;
        while(target > 1){
            if(target % 2 == 0){
                if(maxDoubles > 0){
                    target /= 2;
                    result++;
                    maxDoubles--;
                }
                else{
                    result += (target - 1);
                    target = 1;
                }
            }
            else{
                result++;
                target--;
            }
            
        }
        return result;
    }
};