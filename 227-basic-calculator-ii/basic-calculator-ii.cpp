class Solution {
public:
    int calculate(string str) {
        int n= str.size();
        int lastNum = 0;
        int curNum = 0;
        char opr = '+';
        int result = 0;
        for(int i=0;i<n;i++){
            if(str[i] >= '0' and str[i] <= '9'){
                curNum = curNum*10 + (str[i] - '0');
            }
            if(!isdigit(str[i]) && str[i] != ' ' or i == (n-1)){
                char curOpr = str[i];
                if(opr == '+'){
                    result += lastNum;
                    lastNum = curNum;
                }
                else if(opr == '-'){
                    result += lastNum;
                    lastNum = -curNum;
                }
                else if(opr == '*'){
                    lastNum =  lastNum * curNum;
                    
                }
                else if(opr == '/'){
                    lastNum = lastNum / curNum;
                }
                curNum = 0;
                opr = curOpr;
            }

        }
        result += lastNum;
        return result;
    }
};